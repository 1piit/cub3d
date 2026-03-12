/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:30:14 by pbride            #+#    #+#             */
/*   Updated: 2026/03/12 12:53:03 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 42
# define SUCCESS 0
# define ERROR 1
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>

# include "parsing.h"
# include "get_next_line.h"
# include "garb.h"
# include "libft.h"

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

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		win_width;
	int		win_height;
	t_img	game_img;
}	t_data;

//main_utils.c
void	check_args(int ac);
void	init_structs(t_file *cubfile, char *file_arg);

//mini_map.c
void	draw_mini_map(t_data *data, char **map);

//game_utils.c
void	init_game(t_data *data);

//hook.c
int		close_handler(t_data *data);
int		key_handler(int keysymb, t_data *data);

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

//cleanup.c
void	cleanup_all_data(t_data *data);
void	cleanup_all_exit(t_data *data, char *msg, int err_code);

#endif
