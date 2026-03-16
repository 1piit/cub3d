/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:43:18 by pbride            #+#    #+#             */
/*   Updated: 2026/03/16 17:40:02 by pbride           ###   ########.fr       */
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

void	draw_mini_map(t_data *data, char **map)
{
	int		y;
	int		x;
	t_axis	axis;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			axis.y = y;
			axis.x = x;
			if (map[y][x] == '1' || map[y][x] == 'F')
				my_mlx_put_square(&data->game.game_img, axis, data->game.mini_map_scl, 0x00FF0000);
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'W' || map[y][x] == 'E')
				my_mlx_put_square(&data->game.game_img, axis, data->game.mini_map_scl, 0x00000000);
			x++;
		}
		y++;
	}
}
