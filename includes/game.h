/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:16:27 by pbride            #+#    #+#             */
/*   Updated: 2026/03/26 20:29:59 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define MINI_MAP_RATIO 4 //correspond a 1/4 win_height ou win_width
# define MOVE_SPEED 3.5
# define DIR_SPEED 2
# define HIT_MARGIN 0.2 //bonne margin pour eviter des bugs dans les coins des murs
# define FOV 0.66
# define PLAYER_COLOR 0x00FFFF00

typedef struct s_data	t_data;

typedef struct s_axis
{
	float	x;
	float	y;
}	t_axis;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		img_width;
	int		img_height;
	int		win_width;
	int		win_height;
}	t_img;

typedef struct s_line
{
	int	x;
	int	y;
	int	tex_x;
	int	tex_y;
}	t_line;

typedef struct t_plane
{
	float	plane_x;
	float	plane_y;
}	t_plane;

typedef struct s_player
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
	float	radian;
	float	dir_radian;
	float	step;
	float	ray_dir_x;
	float	ray_dir_y;
	float	camera_x;
	t_plane	plane;
}	t_player;

typedef struct s_box
{
	float	perp_wd;
	float	side_x;
	float	side_y;
	float	dltx;
	float	dlty;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	float	hit_x;
	float	hit_y;
}	t_box;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	int				sn_wall;
	int				ew_wall;
	int				final_ceilling;
	int				final_floor;
	int				mini_map_scl;
	int				map_width;
	int				map_height;
	int				win_width;
	int				win_height;
	struct timeval	time_last;
	float			delta_time;
	t_img			tex_img;
	t_img			game_img;
	t_player		player;
	t_box			box;
	int				keys[65536];
}	t_game;

//mini_map.c
void	init_map_len(t_data *data);
void	draw_mini_map(t_data *data, char **map);

//player.c
void	update_player_pos(t_data *data);
void	update_player_dir(t_data *data);

//dda.c
void	ft_dda(t_data *data, t_box *box, float ray_dx, float ray_dy, t_player *player);

//bresenham.c
void bresenham(t_data *data, int start_x, int start_y, int end_x, int end_y);

// void	update_player_plane(t_data *data);
void	init_player_dir(t_data *data, char c);
void	init_player(t_data *data);
void	init_plane(t_data *data, char c);
void	draw_line(t_data *data, int nb);
void	get_plane_val(t_data *data, float x, float y);
void	draw_player(t_data *data);

//raycast.c
void *raycast_game(void *arg);
void draw_ceilfloor(t_data *data);
void which_line(t_data *data, float ray_dir_x, float ray_dir_y);

//game_utils.c
void	init_game(t_data *data);

//game_utils2.c
int	calculate_scale(t_data *data);

//player_utils.c
void	move_player_x(t_data *data, float dir_x);
void	move_player_y(t_data *data, float dir_y);
void	init_player_dir(t_data *data, char c);
void	init_plane(t_data *data, char c);
void	init_player(t_data *data);

//key_handler.c
int		close_handler(t_data *data);
int		key_press(int keysymb, t_data *data);
int		key_release(int keysymb, t_data *data);

//game_loop.c
int		game_loop(t_data *data);

//mlx_utils.c
void	my_mlx_put_pixel(t_img *img, int x, int y, int color);
void	my_mlx_put_square(t_img *img, t_axis axis, int scale, int color);
void	my_put_circle(t_img *img, t_axis axis, int scale, int color);

//utils.c
void	get_screen_size(int *width, int *height);
void	update_delta_time(t_data *data);

#endif
