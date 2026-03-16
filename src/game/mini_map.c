/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:43:18 by pbride            #+#    #+#             */
/*   Updated: 2026/03/16 16:26:34 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_map_len(t_data *data)
{
	char	**map;
	t_axis	axis;

	map = data->cubfile.map;
	axis.y = 0;
	while (map[axis.y])
	{
		axis.x = 0;
		while (map[axis.y][axis.x])
		{
			if (data->game.map_width < axis.x)
				data->game.map_width = axis.x;
			axis.x++;
		}
		if (data->game.map_height < axis.y)
				data->game.map_height = axis.y;
		axis.y++;
	}
}

void	draw_mini_map(t_data *data, char **map)
{
	t_axis	axis;

	axis.y = 0;
	while (map[axis.y])
	{
		axis.x = 0;
		while (map[axis.y][axis.x])
		{
			if (map[axis.y][axis.x] == '1' || map[axis.y][axis.x] == 'F')
				my_mlx_put_square(&data->game.game_img, axis, data->game.mini_map_scl, 0x00FF0000);
			if (map[axis.y][axis.x] == '0' || map[axis.y][axis.x] == 'N' || map[axis.y][axis.x] == 'S'
			|| map[axis.y][axis.x] == 'W' || map[axis.y][axis.x] == 'E')
				my_mlx_put_square(&data->game.game_img, axis, data->game.mini_map_scl, 0x00000000);
			axis.x++;
		}
		axis.y++;
	}
}
