/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:58:11 by pbride            #+#    #+#             */
/*   Updated: 2026/03/23 14:35:41 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	my_mlx_put_pixel(t_img *img, double x, double y, int color)
{
	char	*dest;
	int		offset;

	offset = ((int)y * img->line_len + (int)x * (img->bits_per_pixel / 8));
	dest = img->addr + offset;
	*(unsigned int *)dest = color;
}

void	my_mlx_put_square(t_img *img, t_axis axis, int scale, int color)
{
	int	px;
	int	py;

	px = 0;
	printf("INITIAL x is --> %f, y is --> %f\n", axis.x, axis.y);
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
