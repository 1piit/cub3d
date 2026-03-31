/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:16:27 by pbride            #+#    #+#             */
/*   Updated: 2026/03/31 17:22:27 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

#include "cub3d.h"
# define MINI_MAP_RATIO 4 //correspond a 1/4 win_height ou win_width
# define MOVE_SPEED 0.06
# define MOVE_SPEED_FPS 4
# define DIR_SPEED 2.5
# define HIT_MARGIN 0.4
# define FOV 0.66
# define PLAYER_CLR 0x00FFFF00
# define RAY_CLR 0x009EE01
# define WALL_CLR 0x00FF0000
# define FLOOR_CLR 0x00000000
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_data	t_data;
typedef struct s_thread_data	t_thread_data;
typedef struct s_axis_f
{
	double	x;
	double	y;
}	t_axf;

typedef struct s_axis_i
{
	int	x;
	int	y;
}	t_axi;

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

typedef struct s_ray
{
	int	draw_start;
	int	draw_end;
	int	line_height;
}	t_ray;

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
	t_axf	ray_dir;
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

typedef struct s_brsh
{
	t_axi	delta;
	t_axi	step;
	int		err_factor;
	int		save_err_fac;
}	t_brsh;

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
	double			delta_time;
	char			*fps;
	//t_img 			tex_img;
	t_img			textures[4];
	t_img			game_img;
	t_player		player;
	t_box			box;
	int				keys[65536];
}	t_game;

//mini_map.c
void	draw_mini_map(t_data *data, char **map);
void	draw_player(t_data *data);

//player.c
void	update_player_pos(t_data *data);
void	update_player_dir(t_data *data);

//dda.c
void	ft_dda(t_data *data, t_thread_data *th_data, t_axf ray_dir, t_box *box);
void	ft_dda_minimap(t_data *data, t_axf ray_dir, t_box *box);
//bresenham.c
void	ft_bresenham(t_data *data, t_axi start, t_axi end);

//player.c
void	init_player_dir(t_data *data, char c);
void	init_player(t_data *data);
void	init_plane(t_data *data, char c);

//3d_scene.c
void	draw_ceilfloor(t_data *data);
void	draw_wall(t_thread_data *th_data, t_data *data, t_ray ray, int i,
			t_box *box);

//raycast.c
void	raycast_mini_map(t_data *data, int nb);
void	*raycast_game(void *arg);
// void	raycast_3d_scene(t_data *data);

//game_utils.c
void	init_game(t_data *data);

//game_utils2.c
void	init_map_len(t_data *data);
int		calculate_scale(t_data *data);
void	update_delta_time(t_data *data);

//player_utils.c
void	init_player_dir(t_data *data, char c);
void	init_plane(t_data *data, char c);
void	init_player(t_data *data);

//key_handler.c
int		close_handler(t_data *data);
int		key_press(int keysymb, t_data *data);
int		key_release(int keysymb, t_data *data);

//render.c
int		render_frame(t_data *data);

//game_loop.c
int		game_loop(t_data *data);

//mlx_utils.c
void	put_pixel(t_img *img, double x, double y, int color);
void	put_square(t_img *img, t_axf axis, int scale, int color);
void	put_circle(t_img *img, t_axf axis, int scale, int color);
void	put_texture(t_data *data, t_ray ray, t_line line, t_img *tex_img);

//utils.c
void	get_screen_size(int *width, int *height);
int		get_real_rgb(int *rgb_components);
t_img	*get_texture(t_data *data, int side, t_axf ray_dir);

#endif
