/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:26:19 by pbride            #+#    #+#             */
/*   Updated: 2026/03/26 17:32:25 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

// faudra quand meme aller voir en detail l algo bresenham pour etre bien capable d expliquer tout ca
void ft_bresenham(t_data *data, int start_x, int start_y, int end_x, int end_y)
{
	int dx;
	int dy;
	int step_x;
	int step_y;
	int err_factor;
	int save_err;
	dx = abs(end_x - start_x);
	dy = abs(end_y - start_y);
	if(start_x < end_x)
		step_x = 1;
	else
		step_x = -1;
	if(start_y < end_y)
		step_y = 1;
	else
		step_y = -1;
	if(dx > dy)
		err_factor = dx / 2;
	else
		err_factor = -dy / 2;

	while(1)
	{
		if (start_x >= 0 && start_x < data->game.map_width * data->game.mini_map_scl
			&& start_y >= 0 && start_y < data->game.map_height * data->game.mini_map_scl)
			put_pixel(&data->game.game_img, start_x, start_y, 0x009EE01);
		if(start_x == end_x && start_y == end_y)
			break;
		save_err = err_factor;
		if(save_err > -dx)
		{
			err_factor -= dy;
			start_x += step_x;
		}
		if(save_err < dy)
		{
			err_factor += dx;
			start_y += step_y;
		}
	}
}
