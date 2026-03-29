/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_scene.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:57:53 by pbride            #+#    #+#             */
/*   Updated: 2026/03/29 17:09:53 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	draw_ceilling(t_data *data, int ceilling)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->game.win_height / 2)
	{
		j = 0;
		while (j < data->game.win_width)
		{
			put_pixel(&data->game.game_img, j, i, ceilling);
			j++;
		}
		i++;
	}
}

static void	draw_floor(t_data *data, int floor)
{
	int	i;
	int	j;

	i = data->game.win_height / 2;
	while (i < data->game.win_height)
	{
		j = 0;
		while (j < data->game.win_width)
		{
			put_pixel(&data->game.game_img, j, i, floor);
			j++;
		}
		i++;
	}
}

void	draw_ceilfloor(t_data *data)
{
	int	ceilling;
	int	floor;

	ceilling = get_real_rgb(data->cubfile.rgb_c);
	floor = get_real_rgb(data->cubfile.rgb_f);
	draw_ceilling(data, ceilling);
	draw_floor(data, floor);
}

void	draw_wall(t_data *data, t_ray ray, int i)
{
	double	wall_x;
	t_line	line;
	t_img	*texture;

	if (data->game.box.side == 0)
		wall_x = data->game.player.pos_y + data->game.box.perp_wd * \
data->game.player.ray_dir.y;
	else
		wall_x = data->game.player.pos_x + data->game.box.perp_wd * \
data->game.player.ray_dir.x;
	wall_x -= floor(wall_x);
	texture = get_texture(data);
	line = (t_line){0};
	line.tex_x = (int)(wall_x * texture->img_width);
	if (line.tex_x >= texture->img_width)
		line.tex_x = texture->img_width - 1;
	line.x = i;
	line.y = ray.draw_start;
	while (line.y < ray.draw_end)
	{
		put_texture(data, ray, line, texture);
		line.y++;
	}
}
