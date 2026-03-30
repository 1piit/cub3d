/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:43:18 by pbride            #+#    #+#             */
/*   Updated: 2026/03/27 09:20:24 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	draw_mini_map(t_data *data, char **map)
{
	int		y;
	int		x;
	t_axf	axis;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			axis.y = y;
			axis.x = x;
			if (map[y][x] == '1' || map[y][x] == 'F')
				put_square(&data->game.game_img, axis,
					data->game.mini_map_scl, WALL_CLR);
			if (map[y][x] == '0' || map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'W' || map[y][x] == 'E')
				put_square(&data->game.game_img, axis,
					data->game.mini_map_scl, FLOOR_CLR);
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	t_axf	axis;

	axis.x = data->game.player.pos_x - 0.5;
	axis.y = data->game.player.pos_y - 0.5;
	put_circle(&data->game.game_img, axis,
		data->game.mini_map_scl / 2,
		data->game.mini_map_scl);
}
