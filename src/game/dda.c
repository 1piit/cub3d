/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:22:16 by pbride            #+#    #+#             */
/*   Updated: 2026/03/27 09:04:11 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	init_ray_delta_axis(t_data *data, t_axf ray_dir)
{
	if (!ray_dir.x)
		data->game.box.dltx = 1e30;
	else
		data->game.box.dltx = fabs(1 / ray_dir.x);
	if (!ray_dir.y)
		data->game.box.dlty = 1e30;
	else
		data->game.box.dlty = fabs(1 / ray_dir.y);
}

static void	init_ray_step_side_axis(t_data *data, t_axf ray_dir, t_axi *step)
{
	if (ray_dir.x < 0)
	{
		step->x = -1;
		data->game.box.side_x = (data->game.player.pos_x - \
data->game.box.map_x) * data->game.box.dltx;
	}
	else
	{
		step->x = 1;
		data->game.box.side_x = (data->game.box.map_x + 1 - \
data->game.player.pos_x) * data->game.box.dltx;
	}
	if (ray_dir.y < 0)
	{
		step->y = -1;
		data->game.box.side_y = (data->game.player.pos_y - \
data->game.box.map_y) * data->game.box.dlty;
	}
	else
	{
		step->y = 1;
		data->game.box.side_y = (data->game.box.map_y + 1 - \
data->game.player.pos_y) * data->game.box.dlty;
	}
}

static void	dda_loop(t_data *data, t_axi *step, int hit)
{
	while (!hit)
	{
		if (data->game.box.side_x < data->game.box.side_y)
		{
			data->game.box.side_x += data->game.box.dltx;
			data->game.box.map_x += step->x;
			data->game.box.side = 0;
		}
		else
		{
			data->game.box.side_y += data->game.box.dlty;
			data->game.box.map_y += step->y;
			data->game.box.side = 1;
		}
		if (data->game.box.map_x < 0
			|| data->game.box.map_x >= data->game.map_width
			|| data->game.box.map_y < 0
			|| data->game.box.map_y >= data->game.map_height)
			break ;
		if (data->cubfile.map[data->game.box.map_y][data->game.box.map_x] == \
'1')
			hit = 1;
	}
}

void	ft_dda(t_data *data, t_axf ray_dir)
{
	t_axi	step;
	int		hit;

	data->game.box.map_x = data->game.player.pos_x;
	data->game.box.map_y = data->game.player.pos_y;
	init_ray_delta_axis(data, ray_dir);
	init_ray_step_side_axis(data, ray_dir, &step);
	hit = 0;
	dda_loop(data, &step, hit);
	if (data->game.box.side == 0)
		data->game.box.perp_wd = (data->game.box.side_x - data->game.box.dltx);
	else
	{
		data->game.box.perp_wd = (data->game.box.side_y - data->game.box.dlty);
	}
	data->game.box.hit_x = data->game.player.pos_x + ray_dir.x * \
data->game.box.perp_wd;
	data->game.box.hit_y = data->game.player.pos_y + ray_dir.y * \
data->game.box.perp_wd;
}
