/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 13:45:10 by pbride            #+#    #+#             */
/*   Updated: 2026/03/26 13:47:27 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_map_len(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	map = data->cubfile.map;
	y = 0;
	while (map[(int)y])
	{
		x = 0;
		while (map[(int)y][(int)x])
		{
			if (data->game.map_width < x)
				data->game.map_width = x;
			x++;
		}
		if (data->game.map_height < y)
			data->game.map_height = y;
		y++;
	}
}

int	calculate_scale(t_data *data)
{
	int	scale;
	int	map_len;
	int	minimap_len;

	if (data->game.map_width > data->game.map_height)
	{
		map_len = data->game.map_width;
		minimap_len = data->game.win_width / MINI_MAP_RATIO;
	}
	else
	{
		map_len = data->game.map_height;
		minimap_len = data->game.win_height / MINI_MAP_RATIO;
	}
	scale = minimap_len / map_len;
	if (scale == 0)
		scale = 1;
	return (scale);
}

void	update_delta_time(t_data *data)
{
	struct timeval	now;
	long			elapsed_us;

	gettimeofday(&now, NULL);
	elapsed_us = (now.tv_sec - data->game.time_last.tv_sec) \
* 1000000 + (now.tv_usec - data->game.time_last.tv_usec);
	data->game.delta_time = elapsed_us / 1000000.0;
	data->game.time_last = now;
}
