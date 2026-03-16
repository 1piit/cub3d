/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:45 by pbride            #+#    #+#             */
/*   Updated: 2026/03/16 16:24:44 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	update_player_pos(t_data *data)
{
	float	new_axis;

	if (data->game.keys[XK_w] && data->game.player.pos_y > 0)
	{
		new_axis = data->game.player.pos_y - 0.1;
		if (data->cubfile.map[(int)new_axis][(int)data->game.player.pos_x] != '1')
			data->game.player.pos_y -= 0.1;
	}
	else if (data->game.keys[XK_s] && data->game.player.pos_y < data->game.map_height)
	{
		new_axis = data->game.player.pos_y + 0.1;
		if (data->cubfile.map[(int)new_axis][(int)data->game.player.pos_x] != '1')
			data->game.player.pos_y += 0.1;
	}
	else if (data->game.keys[XK_a] && data->game.player.pos_x > 0)
	{
		new_axis = data->game.player.pos_x - 0.1;
		if (data->cubfile.map[(int)(int)data->game.player.pos_y][(int)new_axis] != '1')
			data->game.player.pos_x -= 0.1;
	}
	else if (data->game.keys[XK_d] && data->game.player.pos_x < data->game.map_width)
	{
		new_axis = data->game.player.pos_x + 0.1;
		if (data->cubfile.map[(int)(int)data->game.player.pos_y][(int)new_axis] != '1')
			data->game.player.pos_x += 0.1;
	}
}

void	init_player_pos(t_data *data)
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
			if (map[axis.y][axis.x] == 'N' || map[axis.y][axis.x] == 'S'
			|| map[axis.y][axis.x] == 'W' || map[axis.y][axis.x] == 'E')
			{
				data->game.player.pos_x = axis.x;
				data->game.player.pos_y = axis.y;
			}
			axis.x++;
		}
		axis.y++;
	}
}

void	draw_player(t_data *data)
{
	t_axis	axis;

	axis.x = data->game.player.pos_x;
	axis.y = data->game.player.pos_y;
	my_mlx_put_square(&data->game.game_img, axis, data->game.mini_map_scl, 0x00FFFF00);
}
