/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:22:16 by pbride            #+#    #+#             */
/*   Updated: 2026/03/26 19:35:30 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_dda(t_data *data, t_box *box, float ray_dx, float ray_dy, t_player *player)
{
	int step_x;
	int step_y;
	int hit = 0;

	box->map_x = player->pos_x;
	box->map_y = player->pos_y;
	if(!ray_dx)
		box->dltx = 1e30;
	else
		box->dltx = fabs(1/ray_dx);
	if(!ray_dy)
		box->dlty = 1e30;
	else
		box->dlty = fabs(1/ray_dy);
	if(ray_dx < 0)
	{
		step_x = -1;
		box->side_x = (player->pos_x - box->map_x) * box->dltx;
	}
	else
	{
		step_x = 1;
		box->side_x = (box->map_x + 1 - player->pos_x) * box->dltx;
	}
	if(ray_dy < 0)
	{
		step_y = -1;
		box->side_y = (player->pos_y - box->map_y) * box->dlty;
	}
	else
	{
		step_y = 1;
		box->side_y = (box->map_y + 1 - player->pos_y) * box->dlty;
	}
	while(!hit)
	{
		if(box->side_x < box->side_y)
		{
			box->side_x += box->dltx;
			box->map_x += step_x;
			box->side = 0;
		}
		else
		{
			box->side_y += box->dlty;
			box->map_y += step_y;
			box->side = 1;
		}
		if (box->map_x < 0 || box->map_x >= data->game.map_width ||
            box->map_y < 0 || box->map_y >= data->game.map_height)
            break;
		if(data->cubfile.map[box->map_y][box->map_x] == '1')
			hit = 1;
	}
    if (box->side == 0)
        box->perp_wd = (box->side_x - box->dltx);
    else
    {
		box->perp_wd = (box->side_y - box->dlty);
	}
	box->hit_x = player->pos_x + ray_dx * box->perp_wd;
	box->hit_y = player->pos_y + ray_dy * box->perp_wd;
}
