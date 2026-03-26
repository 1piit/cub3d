/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:16:27 by pbride            #+#    #+#             */
/*   Updated: 2026/03/25 20:38:03 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# define MINI_MAP_RATIO 4 //correspond a 1/4 win_height ou win_width
# define MOVE_SPEED 0.07
# define HIT_MARGIN 0.4 //bonne margin pour eviter des bugs dans les coins des murs
# define FOV 0.66
# define PLAYER_COLOR 0x00FFFF00

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
	int		win_width;
	int		win_height;
}	t_img;

typedef struct t_plane
{
	double 	plane_x;
	double plane_x_start;
	double 	plane_y;
	double	plane_y_start;
	double 	end_x[2];
	double  end_y[2];
} 	t_plane;

typedef struct s_player
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	radian;
	double  dir_radian;
	double 	step;
	double ray_dir_x;
	double ray_dir_y;
	double	camera_x;
	t_plane plane;
}	t_player;

typedef struct s_box
{
	double perp_wd;
	double side_x;
	double side_y;
	double dltx;
	double dlty;
	int map_x;
	int map_y;
	int step_x;
	int step_y;
	int side;
	double hit_x;
	double hit_y;
} t_box;
typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	int			sn_wall;
	int			ew_wall;
	int			mini_map_scl;
	int			map_width;
	int			map_height;
	int			win_width;
	int			win_height;
	int			final_ceilling;
	int			final_floor;
	t_img		game_img;
	t_player	player;
	t_box		box;
	int			keys[65536];
}	t_game;

//mini_map.c
void	init_map_len(t_data *data);
void	draw_mini_map(t_data *data, char **map);

//player.c
void	update_player_pos(t_data *data);
void	update_player_dir(t_data *data);

//dda.c
void	ft_dda(t_data *data, double ray_dx, double ray_dy);

//bresenham.c
void bresenham(t_data *data, int start_x, int start_y, int end_x, int end_y);

// void	update_player_plane(t_data *data);
void	init_player_dir(t_data *data, char c);
void	init_player(t_data *data);
void	init_plane(t_data *data, char c);
void	draw_line(t_data *data, int nb);
void	get_plane_val(t_data *data, double x, double y);
void	draw_player(t_data *data);

//raycast.c
void raycast_game(t_data *data);
void draw_ceilfloor(t_data *data);
void which_line(t_data *data, double ray_dir_x, double ray_dir_y);

//game_utils.c
void	init_game(t_data *data);

//game_utils2.c
int	calculate_scale(t_data *data);

//player_utils.c
void	move_player_x(t_data *data, double dir_x);
void	move_player_y(t_data *data, double dir_y);
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

#endif
