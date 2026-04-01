/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:12:13 by ptricaud          #+#    #+#             */
/*   Updated: 2026/04/01 12:21:44 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_ray_delta_axis(t_box *box, t_axf ray_dir)
{
	if (!ray_dir.x)
		box->dltx = 1e30;
	else
		box->dltx = fabs(1 / ray_dir.x);
	if (!ray_dir.y)
		box->dlty = 1e30;
	else
		box->dlty = fabs(1 / ray_dir.y);
}

void	init_ray_step_side_axis(t_thread_data *th_data, t_axf ray_dir,
		t_axi *step, t_box *box)
{
	if (ray_dir.x < 0)
	{
		step->x = -1;
		box->side_x = (th_data->th_player.pos_x - box->map_x) * box->dltx;
	}
	else
	{
		step->x = 1;
		box->side_x = (box->map_x + 1 - th_data->th_player.pos_x) * box->dltx;
	}
	if (ray_dir.y < 0)
	{
		step->y = -1;
		box->side_y = (th_data->th_player.pos_y - box->map_y) * box->dlty;
	}
	else
	{
		step->y = 1;
		box->side_y = (box->map_y + 1 - th_data->th_player.pos_y) * box->dlty;
	}
}

void	init_ray_step_side_axis_mini(t_data *data, t_axf ray_dir,
		t_axi *step, t_box *box)
{
	if (ray_dir.x < 0)
	{
		step->x = -1;
		box->side_x = (data->game.player.pos_x - box->map_x) * box->dltx;
	}
	else
	{
		step->x = 1;
		box->side_x = (box->map_x + 1 - data->game.player.pos_x) * box->dltx;
	}
	if (ray_dir.y < 0)
	{
		step->y = -1;
		box->side_y = (data->game.player.pos_y - box->map_y) * box->dlty;
	}
	else
	{
		step->y = 1;
		box->side_y = (box->map_y + 1 - data->game.player.pos_y) * box->dlty;
	}
}

void	dda_loop(t_data *data, t_axi *step, int hit, t_box *box)
{
	while (!hit)
	{
		if (box->side_x < box->side_y)
		{
			box->side_x += box->dltx;
			box->map_x += step->x;
			box->side = 0;
		}
		else
		{
			box->side_y += box->dlty;
			box->map_y += step->y;
			box->side = 1;
		}
		if (box->map_x < 0 || box->map_x >= data->game.map_width
			|| box->map_y < 0 || box->map_y >= data->game.map_height)
			break ;
		if (data->cubfile.map[box->map_y][box->map_x] == '1')
			hit = 1;
	}
}
