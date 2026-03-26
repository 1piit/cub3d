/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:16:27 by pbride            #+#    #+#             */
/*   Updated: 2026/03/26 18:21:39 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define MINI_MAP_RATIO 4 //correspond a 1/4 win_height ou win_width
# define MOVE_SPEED 3.5
# define DIR_SPEED 2.5
# define HIT_MARGIN 0.4
# define FOV 0.66
# define PLAYER_COLOR 0x00FFFF00
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_data	t_data;

typedef struct s_axis
{
	double	x;
	double	y;
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

typedef struct s_ray
{
	int	draw_start;
	int	draw_end;
	int	line_height;
}	t_ray;

typedef struct t_plane
{
	double	plane_x;
	double	plane_x_start;
	double	plane_y;
	double	plane_y_start;
	double	end_x[2];
	double	end_y[2];
}	t_plane;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	radian;
	double	dir_radian;
	double	step;
	double	ray_dir_x;
	double	ray_dir_y;
	double	camera_x;
	t_plane	plane;
}	t_player;

typedef struct s_box
{
	double	perp_wd;
	double	side_x;
	double	side_y;
	double	dltx;
	double	dlty;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	double	hit_x;
	double	hit_y;
}	t_box;

typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	int				sn_wall;
	int				ew_wall;
	int				mini_map_scl;
	int				map_width;
	int				map_height;
	int				win_width;
	int				win_height;
	struct timeval	time_last;
	double			delta_time;
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
void	ft_dda(t_data *data, double ray_dx, double ray_dy);

//bresenham.c
void	ft_bresenham(t_data *data, int start_x, int start_y, \
int end_x, int end_y);

//player.c
void	init_player_dir(t_data *data, char c);
void	init_player(t_data *data);
void	init_plane(t_data *data, char c);

//3d_scene.c
void	draw_ceilfloor(t_data *data);
void	draw_wall(t_data *data, t_ray ray, int i);

//raycast.c
void	raycast_mini_map(t_data *data, int nb);
void	raycast_3d_scene(t_data *data);

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
void	put_square(t_img *img, t_axis axis, int scale, int color);
void	put_circle(t_img *img, t_axis axis, int scale, int color);
void	put_texture(t_data *data, t_ray ray, t_line line, t_img *tex_img);

//utils.c
void	get_screen_size(int *width, int *height);
int		get_real_rgb(int *side);
t_img	*get_texture(t_data *data);

#endif
