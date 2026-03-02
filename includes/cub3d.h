/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:30:14 by pbride            #+#    #+#             */
/*   Updated: 2026/03/02 16:45:53 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 42
# include <stdbool.h>
# include <stdio.h>
# include <mlx.h>

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
	t_img	mini_map;
}	t_data;

//main_utils.c
void	check_args(int ac);
void	init_structs(t_file *cubfile, char *file_arg);
void	init_data(t_data *data);

//mini_map.c
void	init_mini_map(t_data *data);
void	render_mini_map(t_data *data, char **map);

//mlx_utils.c
void	my_mlx_put_pixel(t_img *img, int x, int y, int color);
void	my_mlx_put_square(t_img *img, t_axis axis, int scale, int color);

//mlx_utils_2.c
void	my_mlx_put_triangle_no(t_img *img, t_axis axis, int scale, int color);
void	my_mlx_put_triangle_so(t_img *img, t_axis axis, int scale, int color);
void	my_mlx_put_triangle_we(t_img *img, t_axis axis, int scale, int color);
void	my_mlx_put_triangle_ea(t_img *img, t_axis axis, int scale, int color);

#endif
