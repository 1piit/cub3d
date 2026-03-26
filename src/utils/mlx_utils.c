/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:58:11 by pbride            #+#    #+#             */
/*   Updated: 2026/03/25 20:21:19 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	my_mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;
	int		offset;

	if(x < 0 || y < 0 || x > img->win_width - 1 || y > img->win_height - 1)
		return;
	offset = ((int)y * img->line_len + (int)x * (img->bits_per_pixel / 8));
	dest = img->addr + offset;
	*(unsigned int *)dest = color;
}

void	my_mlx_put_square(t_img *img, t_axis axis, int scale, int color)
{
	int	px;
	int	py;

	px = 0;
	while (px < scale)
	{
		py = 0;
		while (py < scale)
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

void	my_put_circle(t_img *img, t_axis axis, int radius, int scale)
{
	int px;
	int py;

	py = -radius;
	while (py <= radius)
	{
		px = -radius;
		while (px <= radius)
		{
			if (px * px + py * py <= radius * radius)
				my_mlx_put_pixel(img,
					(axis.x * scale + scale / 2) + px,
					(axis.y * scale + scale / 2) + py,
					PLAYER_COLOR);
			px++;
		}
		py++;
	}
}
