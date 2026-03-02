/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:58:11 by pbride            #+#    #+#             */
/*   Updated: 2026/03/02 12:48:18 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	my_mlx_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dest;
	int		offset;

	offset = (y * img->line_len + x * (img->bits_per_pixel / 8));
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
