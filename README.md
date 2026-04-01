*This project has been created as part of the 42 curriculum by ptricaud, pbride.*

# 🎮 cub3D — Raycasting Engine

---

## Description

cub3D is a pseudo-3D game engine inspired by the legendary **Wolfenstein 3D**, the
first FPS game ever made. The goal is to render a navigable 3D perspective view of a
maze from a 2D map, using the **raycasting** technique — without any 3D engine.

The map and scene configuration are loaded from a `.cub` file, which defines wall
textures, ceiling/floor colors, and the map grid itself. The player can move and rotate
through the scene in real time.

**Key features:**
- Textured walls rendered via the DDA (Digital Differential Analysis) algorithm
- Ceiling and floor rendering with configurable RGB colors
- Smooth player movement with collision detection, delta-time based
- Camera rotation via keyboard
- Multithreaded rendering: the screen is split into vertical strips, each handled by
  a dedicated `pthread` worker
- Custom garbage collector for safe and centralized memory management
- **Bonus:** Minimap with player position and ray visualization

---

## Instructions

### Requirements

- Linux / macOS
- MiniLibX (included or system-installed)
- CC / GCC / Clang
- Make

### Compilation

```bash
make
```

To remove object files:

```bash
make clean
```

To remove all compiled files:

```bash
make fclean
```

To recompile from scratch:

```bash
make re
```

To launch norminette ./src ./includes ./get_next_line ./libft

```bash
make norm
```

### Execution

```bash
./cub3D <path/to/map.cub>
```

**Example:**
```bash
./cub3D maps/map.cub
```

### Map file format (`.cub`)

```
NO ./textures/north.xpm
SO ./textures/south.xpm
WE ./textures/west.xpm
EA ./textures/east.xpm

F 220,100,0
C 135,206,235

111111
100001
1000N1
100001
111111
```

- `NO/SO/WE/EA` — paths to XPM wall textures
- `F` / `C` — Floor / Ceiling RGB color
- Map characters: `1` = wall, `0` = floor, `N/S/E/W` = player spawn direction
- The map **must** be fully enclosed by walls

### Controls

| Key | Action |
|---|---|
| `W / S` | Move forward / backward |
| `A / D` | Strafe left / right |
| `← / →` | Rotate camera |
| `ESC` | Quit |

---

## Technical Overview

### Source Structure

```
src/
├── main/
│   └── main.c / main_utils.c          # Entry point & argument handling
├── parsing/
│   ├── utils/
│   │   ├── extract_cf_utils.c         # check_ceilfloor_line, look_char, get_values, join_line, check_format
│   │   ├── extract_map_utils.c        # only_space, line_tester, null_terminate, map_fill, check_eof
│   │   ├── extract_text_utils.c       # blank_skipper, wt_line_getter, textures_getter
│   │   ├── parsing_map_utils.c        # find_longest, find_lengths, fill_temp_map, temp_map
│   │   ├── parsing_map_utils2.c       # edges_first, check_enclosed — additional map enclosure helpers
│   │   └── parsing_utils.c            # init_parsing, init_struct, tester_extract
│   ├── extract_ceilfloor.c            # Extract ceiling/floor RGB values from the .cub file
│   ├── extract_map.c                  # Extract the map grid (char **) from the .cub file
│   ├── extract_textures.c             # Extract the four texture file paths (NO/SO/WE/EA)
│   ├── file_alloc.c                   # Read & allocate the full .cub file content
│   ├── parsing_ceilfloor.c            # RGB parsing & validation (range, format)
│   ├── parsing_datas_gen.c            # Master validator — chains all parsing checks (parsing_datas)
│   ├── parsing_map.c                  # Map structure validation & enclosure check
│   ├── parsing_player.c               # Player spawn detection (N/S/E/W)
│   └── parsing_textures.c             # Texture path validation
├── game/
│   ├── utils/
│   │   ├── game_utils.c               # init_window, init_threads, init_textures, init_hooks
│   │   ├── game_utils2.c              # init_map_len, calculate_scale, update_delta_time, init_game
│   │   ├── mlx_utils.c                # put_pixel, put_square, put_circle, put_texture
│   │   ├── player_utils.c             # init_player_dir, init_plane, init_player
│   │   └── utils.c                    # get_real_rgb, get_texture — color & texture selectors
│   ├── 3d_scene.c                     # draw_wall, draw_ceil_floor
│   ├── bresenham.c                    # ft_bresenham — minimap ray line drawing
│   ├── dda.c                          # ft_dda, ft_dda_minimap
│   ├── dda2.c                         # init_ray_delta_axis, init_ray_step_side_axis, dda_loop
│   ├── game_loop.c                    # game_loop, render_frame — main loop & frame sync
│   ├── key_handler.c                  # keypress, keyrelease, close_handler
│   ├── mini_map.c                     # draw_minimap, draw_player
│   ├── player.c                       # update_player_pos, update_player_dir — movement & collision
│   ├── raycast.c                      # raycast_game (threads), raycast_minimap
│   ├── raycast2.c                     # pre_dda, post_dda, dda_raycast, perpwd_check
│   └── render.c                       # render_frame — frame orchestration & FPS display
├── garbage_collector/
│   ├── gc_features.c                  # gc_mem, gc_malloc, gc_free, gc_full_clean
│   ├── gc_strjoin.c                   # gc_strjoin — GC-aware string join
│   └── gc_utils.c                     # cleanup_all, remove_gc_node
└── cleanup.c                          # Centralized cleanup handlers & safe 
```

### Parsing Pipeline

```
.cub file
   ├─ check_extension()        → validates .cub extension
   ├─ file_alloc               → reads and allocates file content
   ├─ extract_textures()       → NO / SO / WE / EA paths
   ├─ extract_ceilfloor()      → ceiling and floor RGB colors
   ├─ extract_map()            → map grid (char **)
   ├─ parsing_player()         → spawn character (N/S/E/W)
   └─ Validations:
         ✓ empty_file()
         ✓ check_dimensions()
         ✓ enclosed_map()      → check_neigh_boxes() on every '0' cell
         ✓ check_player()      → exactly one spawn
         ✓ invalid_rgb_case_one/two()
         ✓ invalid_textures()
         ✓ extra_data() / is_here()
```

### DDA Algorithm

```
For each column x ∈ [0, winwidth]:

  [pre_dda()]
  camerax       = 2.0 * x / (winwidth - 1.0) - 1   // [-1.0 .. +1.0]
  raydir.x/y    = dirx/y + plane.planex/y * camerax

  [init_ray_delta_axis()]
  dltx = |1 / raydir.x|   (1e30 if raydir.x == 0)
  dlty = |1 / raydir.y|   (1e30 if raydir.y == 0)

  [init_ray_step_side_axis()]
  step.x/y = ±1
  sidex/sidey = initial distance to first grid line

  [dda_loop()]
  while no wall hit:
    if sidex < sidey → sidex += dltx, mapx += step.x, side = 0
    else             → sidey += dlty, mapy += step.y, side = 1
    if map[mapy][mapx] == '1' → hit

  [post_dda()]
  perpwd    = sidex - dltx  (side 0)  |  sidey - dlty  (side 1)
  hitx/hity = pos + raydir * perpwd
  lineheight = winheight / perpwd
  drawstart / drawend  (clamped to screen bounds)
```

### Bresenham Line Algorithm (minimap rays)

```
[init_delta_step()]
delta.x = |end.x - start.x|,  delta.y = |end.y - start.y|
step.x/y = ±1
errfactor = dominant_delta * 2

[ft_bresenham() loop]
put_pixel(start, RAYCLR)
saveerrfac = errfactor
if saveerrfac > -delta.x → errfactor -= delta.y ; start.x += step.x
if saveerrfac <  delta.y → errfactor += delta.x ; start.y += step.y
repeat until start == end
```

### draw_wall — Textured Wall Slice

```
[draw_wall()]
wallx = hit offset on wall face ∈ [0.0 .. 1.0]
  side 0 → wallx = posy + perpwd * raydir.y
  side 1 → wallx = posx + perpwd * raydir.x

get_texture() → selects XPM texture from side + raydir:
  side 0 && raydir.x > 0 → EAST
  side 0 && raydir.x < 0 → WEST
  side 1 && raydir.y > 0 → SOUTH
  side 1 && raydir.y < 0 → NORTH

line.texx = int(wallx * texture->imgwidth)
for line.y ∈ [drawstart .. drawend]:
  put_texture() → put_pixel()
```

### Multithreading

```
Main thread                           Worker threads (×NUMTHREADS)
──────────────────────────────────────────────────────────────────
init_threads() → pthread_create()     Infinite loop:
                                        pthread_barrier_wait(barrierstart)
update_player_pos/dir()               for x ∈ [startx .. endx]:
copy player → thdata[i].thplayer            dda_raycast()
pthread_barrier_wait(barrierstart) ─►       draw_wall()
pthread_barrier_wait(barrierstart) ◄─ pthread_barrier_wait(barrierstart)
draw_minimap() / draw_player()
raycast_minimap()
mlx_put_image_to_window()
mlx_string_put() ← FPS
```

Each thread has its own `t_threaddata` with a local `thplayer` copy → zero data race.

### Garbage Collector

| Call | Role |
|---|---|
| `gc_mem(MALLOC, size, NULL, label)` | Allocate and track pointer |
| `gc_mem(FREE, 0, ptr, label)` | Free a specific pointer |
| `gc_mem(FULLCLEAN, 0, NULL, label)` | Free all allocations of a label |
| `cleanup_all()` | FULLCLEAN on `GEN` + `ENV` |

Internally a linked list of `t_garbage { ptr, label, next }` nodes.
`get_garbage()` exposes a static pointer to the list head.
Any allocation failure triggers `cleanup_all()` + `exit(EXIT_FAILURE)`.

---

## Bonus Features

### Minimap
- Rendered top-left at scale `minimapscl`
- `draw_minimap()` — fills wall cells (`WALLCLR`) and floor cells (`FLOORCLR`)
- `draw_player()` — draws a circle via `put_circle()` at the player's scaled position
- `raycast_minimap()` — casts 10 rays via `ft_dda_minimap()` and traces them in
  `RAYCLR` using `ft_bresenham()`

---

## Resources

### Raycasting & DDA
- [Lode's Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html) — primary
  reference for the DDA algorithm and perspective projection
- [Wolfenstein 3D Black Book](https://fabiensanglard.net/wolf3d/) — historical
  technical breakdown of the original engine
- [Really nice tutorial of cub3D](https://hackmd.io/@nszl/H1LXByIE2)
- [From Flat to Fantastic: How cub3D’s Ray Casting Engine Transforms 2D into 3D](https://medium.com/@elmehdielgarouaz/from-flat-to-fantastic-how-cub3ds-ray-casting-engine-transforms-2d-into-3d-647ff2f7fd4f)

### Bresenham Line Algorithm
- [Wikipedia — Bresenham's line algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm)

### MiniLibX
- [MiniLibX documentation (42)](https://harm-smits.github.io/42docs/libs/minilibx)
- [oceano mlx explained](https://github.com/suspectedoceano/mlx)

### Multithreading
- [POSIX Threads Programming — LLNL](https://hpc-tutorials.llnl.gov/posix/)
- `man pthread_create`, `man pthread_barrier_wait`
