/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:45 by pbride            #+#    #+#             */
/*   Updated: 2026/03/16 18:27:21 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	update_player_pos(t_data *data)
{
	float	new_axis;
	float	move_speed;

	move_speed = 0.03;
	if (data->game.keys[XK_w] && data->game.player.pos_y > 0)
	{
		new_axis = data->game.player.pos_y - move_speed;
		if (data->cubfile.map[(int)new_axis][(int)data->game.player.pos_x] != '1')
			data->game.player.pos_y -= move_speed;
	}
	else if (data->game.keys[XK_s] && data->game.player.pos_y < data->game.map_height)
	{
		new_axis = data->game.player.pos_y + move_speed;
		if (data->cubfile.map[(int)new_axis + 1][(int)data->game.player.pos_x] != '1')
			data->game.player.pos_y += move_speed;
	}
	else if (data->game.keys[XK_a] && data->game.player.pos_x > 0)
	{
		new_axis = data->game.player.pos_x - move_speed;
		if (data->cubfile.map[(int)data->game.player.pos_y][(int)new_axis] != '1')
			data->game.player.pos_x -= move_speed;
	}
	else if (data->game.keys[XK_d] && data->game.player.pos_x < data->game.map_width)
	{
		new_axis = data->game.player.pos_x + move_speed;
		if (data->cubfile.map[(int)data->game.player.pos_y + 1][(int)new_axis + 1] != '1')
			data->game.player.pos_x += move_speed;
	}
	printf("player.pos_y=%f player.pos_x=%f case=%c\n",
		data->game.player.pos_y, data->game.player.pos_x,
		data->cubfile.map[(int)data->game.player.pos_y][(int)data->game.player.pos_x]
	);
}

void	init_player_pos(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	map = data->cubfile.map;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				data->game.player.pos_x = x;
				data->game.player.pos_y = y;
			}
			x++;
		}
		y++;
	}
}

void	draw_player(t_data *data)
{
	t_axis	axis;

	axis.x = data->game.player.pos_x;
	axis.y = data->game.player.pos_y;
	my_mlx_put_square(&data->game.game_img, axis, data->game.mini_map_scl, 0x00FFFF00);
}
