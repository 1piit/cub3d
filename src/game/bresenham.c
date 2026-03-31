/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:26:19 by pbride            #+#    #+#             */
/*   Updated: 2026/03/27 09:19:52 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	init_delta_step(t_brsh *brsh_data, t_axi start, t_axi end)
{
	brsh_data->delta.x = abs(end.x - start.x);
	brsh_data->delta.y = abs(end.y - start.y);
	if (start.x < end.x)
		brsh_data->step.x = 1;
	else
		brsh_data->step.x = -1;
	if (start.y < end.y)
		brsh_data->step.y = 1;
	else
		brsh_data->step.y = -1;
	if (brsh_data->delta.x > brsh_data->delta.y)
		brsh_data->err_factor = brsh_data->delta.x / 2;
	else
		brsh_data->err_factor = -brsh_data->delta.y / 2;
}

void	ft_bresenham(t_data *data, t_axi start, t_axi end)
{
	t_brsh	brsh_data;

	init_delta_step(&brsh_data, start, end);
	while (1)
	{
		if (start.x >= 0
			&& start.x < data->game.map_width * data->game.mini_map_scl
			&& start.y >= 0
			&& start.y < data->game.map_height * data->game.mini_map_scl)
			put_pixel(&data->game.game_img, start.x, start.y, RAY_CLR);
		if (start.x == end.x && start.y == end.y)
			break ;
		brsh_data.save_err_fac = brsh_data.err_factor;
		if (brsh_data.save_err_fac > -brsh_data.delta.x)
		{
			brsh_data.err_factor -= brsh_data.delta.y;
			start.x += brsh_data.step.x;
		}
		if (brsh_data.save_err_fac < brsh_data.delta.y)
		{
			brsh_data.err_factor += brsh_data.delta.x;
			start.y += brsh_data.step.y;
		}
	}
}
