/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 16:39:38 by pbride            #+#    #+#             */
/*   Updated: 2026/03/02 16:44:11 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	my_mlx_put_triangle_no(t_img *img, t_axis axis, int scale, int color)
{
	int	py;
	int	px;
	int	width;
	int	x_start;
	int	x_end;

	py = 0;
	while (py < scale)
	{
		width = py + 1;
		x_start = (scale / 2) - (width / 2);
		x_end = x_start + width;
		px = x_start;
		while (px < x_end)
		{
			my_mlx_put_pixel(img,
				axis.x * scale + px,
				axis.y * scale + py,
				color);
				px++;
		}
		py++;
	}
}

void	my_mlx_put_triangle_so(t_img *img, t_axis axis, int scale, int color)
{
	int	py;
	int	px;
	int	width;
	int	x_start;
	int	x_end;

	py = 0;
	while (py < scale)
	{
		width = scale - py;
		x_start = (scale / 2) - (width / 2);
		x_end = x_start + width;
		px = x_start;
		while (px < x_end)
		{
			my_mlx_put_pixel(img,
				axis.x * scale + px,
				axis.y * scale + py,
				color);
				px++;
		}
		py++;
	}
}

void	my_mlx_put_triangle_we(t_img *img, t_axis axis, int scale, int color)
{
	int	py;
	int	px;
	int	width;
	int	y_start;
	int	y_end;

	px = 0;
	while (px < scale)
	{
		width = px + 1;
		y_start = (scale / 2) - (width / 2);
		y_end = y_start + width;
		py = y_start;
		while (py < y_end)
		{
			my_mlx_put_pixel(img,
				axis.x * scale + px,
				axis.y * scale + py,
				color);
				py++;
		}
		px++;
	}
}

void	my_mlx_put_triangle_ea(t_img *img, t_axis axis, int scale, int color)
{
	int	py;
	int	px;
	int	width;
	int	y_start;
	int	y_end;

	px = 0;
	while (px < scale)
	{
		width = scale - px;
		y_start = (scale / 2) - (width / 2);
		y_end = y_start + width;
		py = y_start;
		while (py < y_end)
		{
			my_mlx_put_pixel(img,
				axis.x * scale + px,
				axis.y * scale + py,
				color);
				py++;
		}
		px++;
	}
}
