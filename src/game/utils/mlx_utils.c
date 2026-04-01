/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:58:11 by pbride            #+#    #+#             */
/*   Updated: 2026/04/01 15:04:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	put_pixel(t_img *img, double x, double y, int color)
{
	char	*dest;
	int		offset;

	if (x < 0 || y < 0 || x > img->win_width - 1 || y > img->win_height - 1)
		return ;
	offset = ((int)y * img->line_len + (int)x * (img->bits_per_pixel / 8));
	dest = img->addr + offset;
	*(unsigned int *)dest = color;
}

void	put_square(t_img *img, t_axf axis, int scale, int color)
{
	int	px;
	int	py;

	px = 0;
	while (px < scale)
	{
		py = 0;
		while (py < scale)
		{
			put_pixel(img,
				axis.x * scale + px,
				axis.y * scale + py,
				color);
			py++;
		}
		px++;
	}
}

void	put_circle(t_img *img, t_axf axis, int radius, int scale)
{
	int	px;
	int	py;

	py = -radius;
	while (py <= radius)
	{
		px = -radius;
		while (px <= radius)
		{
			if (px * px + py * py <= radius * radius)
				put_pixel(img,
					(axis.x * scale + scale / 2) + px,
					(axis.y * scale + scale / 2) + py,
					PLAYER_CLR);
			px++;
		}
		py++;
	}
}

void	put_texture(t_data *data, t_ray ray, t_line line, t_img *texture)
{
	int	scale;
	int	dst_offset;
	int	src_offset;

	scale = line.y * texture->line_len - data->game.win_height * \
texture->line_len / 2 + ray.line_height * \
texture->line_len / 2;
	line.tex_y = ((scale * texture->img_width) / ray.line_height) / \
texture->line_len;
	if (line.tex_y < 0)
		line.tex_y = 0;
	if (line.tex_y >= texture->img_width)
		line.tex_y = texture->img_width - 1;
	dst_offset = line.y * data->game.game_img.line_len + line.x * \
	(data->game.game_img.bits_per_pixel / 8);
	src_offset = line.tex_y * texture->line_len + line.tex_x * \
	(texture->bits_per_pixel / 8);
	data->game.game_img.addr[dst_offset] = texture->addr[src_offset];
	data->game.game_img.addr[dst_offset + 1] = texture->addr[src_offset + 1];
	data->game.game_img.addr[dst_offset + 2] = texture->addr[src_offset + 2];
}
