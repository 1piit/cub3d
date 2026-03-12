/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:16:27 by pbride            #+#    #+#             */
/*   Updated: 2026/03/12 15:41:46 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

typedef struct s_data t_data;

typedef struct s_axis
{
	int	x;
	int	y;
}	t_axis;

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	//int		width;
	//int		height;
}	t_img;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	t_img	game_img;
}	t_game;

//mini_map.c
void	draw_mini_map(t_data *data, char **map);

//game_utils.c
void	init_game(t_data *data);

//hook.c
int		close_handler(t_data *data);
int		key_handler(int keysymb, t_data *data);

//game_loop.c
void	game_loop(t_data *data);

//mlx_utils.c
void	my_mlx_put_pixel(t_img *img, int x, int y, int color);
void	my_mlx_put_square(t_img *img, t_axis axis, int scale, int color);

//mlx_utils_2.c
void	my_mlx_put_triangle_no(t_img *img, t_axis axis, int scale, int color);
void	my_mlx_put_triangle_so(t_img *img, t_axis axis, int scale, int color);
void	my_mlx_put_triangle_we(t_img *img, t_axis axis, int scale, int color);
void	my_mlx_put_triangle_ea(t_img *img, t_axis axis, int scale, int color);

//utils.c
void	get_screen_size(int *width, int *height);

#endif
