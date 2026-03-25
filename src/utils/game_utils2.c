/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:19:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/25 02:45:02 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

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
