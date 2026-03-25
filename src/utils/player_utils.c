/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:58:08 by pbride            #+#    #+#             */
/*   Updated: 2026/03/25 22:44:35 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	move_player_x(t_data *data, double dir_x)
{
	double	d_time;
	double	new_x;

	d_time = data->game.delta_time;
	new_x = data->game.player.pos_x + dir_x * (MOVE_SPEED * d_time);
	if (dir_x > 0)
	{
		if (data->cubfile.map[(int)data->game.player.pos_y][(int)(new_x + HIT_MARGIN * 1)] != '1')
			data->game.player.pos_x = new_x;
	}
	else
	{
		if (data->cubfile.map[(int)data->game.player.pos_y][(int)(new_x + HIT_MARGIN * -1)] != '1')
			data->game.player.pos_x = new_x;
	}
}

void	move_player_y(t_data *data, double dir_y)
{
	double	d_time;
	double	new_y;

	d_time = data->game.delta_time;
	new_y = data->game.player.pos_y + dir_y * (MOVE_SPEED * d_time);
	if (dir_y > 0)
	{
		if (data->cubfile.map[(int)(new_y + HIT_MARGIN * 1)][(int)data->game.player.pos_x] != '1')
			data->game.player.pos_y = new_y;
	}
	else
	{
		if (data->cubfile.map[(int)(new_y + HIT_MARGIN * -1)][(int)data->game.player.pos_x] != '1')
			data->game.player.pos_y = new_y;
	}
}

void	init_player_dir(t_data *data, char c)
{
	if (c == 'N')
	{
		data->game.player.radian = (3 * M_PI) / 2;
		data->game.player.dir_y = sin(data->game.player.radian);
	}
	else if (c == 'S')
	{
		data->game.player.radian = M_PI / 2;
		data->game.player.dir_y = sin(data->game.player.radian);
	}
	else if (c == 'E')
	{
		data->game.player.radian = 0;
		data->game.player.dir_x = cos(data->game.player.radian);
	}
	else if (c == 'W')
	{
		data->game.player.radian = M_PI;
		data->game.player.dir_x = cos(data->game.player.radian);
	}
}

void	init_plane(t_data *data, char c)
{
	if (c == 'N')
	{
		data->game.player.plane.plane_x = FOV;
		data->game.player.plane.plane_y = 0;
	}
	else if (c == 'S')
	{
		data->game.player.plane.plane_x = -FOV;
		data->game.player.plane.plane_y = 0;
	}
	else if (c == 'E')
	{
		data->game.player.plane.plane_x = 0;
		data->game.player.plane.plane_y = FOV;
	}
	else if (c == 'W')
	{
		data->game.player.plane.plane_x = 0;
		data->game.player.plane.plane_y = -FOV;
	}
}

void	init_player(t_data *data)
{
	char	**map;
	int		y;
	int		x;

	data->game.player = (t_player){0};
	map = data->cubfile.map;
	y = 0;
	while (map && map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
			|| map[y][x] == 'W' || map[y][x] == 'E')
			{
				init_player_dir(data, map[y][x]);
				init_plane(data, map[y][x]);
				data->game.player.pos_x = x /* + 0.5 */;
				data->game.player.pos_y = y /* + 0.5 */;
			}
			x++;
		}
		y++;
	}
}
