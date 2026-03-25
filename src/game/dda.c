/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:22:16 by pbride            #+#    #+#             */
/*   Updated: 2026/03/25 02:23:18 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_dda(t_data *data, double ray_dx, double ray_dy)
{
	int step_x;
	int step_y;
	int hit = 0;

	data->game.box.map_x = data->game.player.pos_x;
	data->game.box.map_y = data->game.player.pos_y;
	if(!ray_dx)
		data->game.box.dltx = 1e30;
	else
		data->game.box.dltx = fabs(1/ray_dx);
	if(!ray_dy)
		data->game.box.dlty = 1e30;
	else
		data->game.box.dlty = fabs(1/ray_dy);
	if(ray_dx < 0)
	{
		step_x = -1;
		data->game.box.side_x = (data->game.player.pos_x - data->game.box.map_x) * data->game.box.dltx;
	}
	else
	{
		step_x = 1;
		data->game.box.side_x = (data->game.box.map_x + 1 - data->game.player.pos_x) * data->game.box.dltx;
	}
	if(ray_dy < 0)
	{
		step_y = -1;
		data->game.box.side_y = (data->game.player.pos_y - data->game.box.map_y) * data->game.box.dlty;
	}
	else
	{
		step_y = 1;
		data->game.box.side_y = (data->game.box.map_y + 1 - data->game.player.pos_y) * data->game.box.dlty;
	}
	while(!hit)
	{
		if(data->game.box.side_x < data->game.box.side_y)
		{
			data->game.box.side_x += data->game.box.dltx;
			data->game.box.map_x += step_x;
			data->game.box.side = 0;
		}
		else
		{
			data->game.box.side_y += data->game.box.dlty;
			data->game.box.map_y += step_y;
			data->game.box.side = 1;
		}
		if (data->game.box.map_x < 0 || data->game.box.map_x >= data->game.map_width ||
            data->game.box.map_y < 0 || data->game.box.map_y >= data->game.map_height)
            break;
		if(data->cubfile.map[data->game.box.map_y][data->game.box.map_x] == '1')
			hit = 1;
	}
    if (data->game.box.side == 0)
        data->game.box.perp_wd = (data->game.box.side_x - data->game.box.dltx);
    else
    {
		data->game.box.perp_wd = (data->game.box.side_y - data->game.box.dlty);
	}
	data->game.box.hit_x = data->game.player.pos_x + ray_dx * data->game.box.perp_wd;
	data->game.box.hit_y = data->game.player.pos_y + ray_dy * data->game.box.perp_wd;
}
