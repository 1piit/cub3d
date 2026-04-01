/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:45 by pbride            #+#    #+#             */
/*   Updated: 2026/04/01 12:11:10 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	move_player_x(t_data *data, double dir_x)
{
	double	new_x;

	if (1 / data->game.delta_time < 5)
		new_x = data->game.player.pos_x + dir_x * (MOVE_SPEED);
	else
		new_x = data->game.player.pos_x + dir_x * (MOVE_SPEED_FPS
				* data->game.delta_time);
	if (dir_x > 0)
	{
		if ((int)(new_x + HIT_MARGIN * 1) < data->game.map_width
			&& data->cubfile.map[(int)data->game.player.pos_y][(int)(new_x
				+ HIT_MARGIN * 1)] != '1'
			&& data->cubfile.map[(int)data->game.player.pos_y][(int)(new_x
				+ HIT_MARGIN * 1)] != 'F')
			data->game.player.pos_x = new_x;
	}
	else
	{
		if ((int)(new_x + HIT_MARGIN * -1) >= 0
			&& data->cubfile.map[(int)data->game.player.pos_y][(int)(new_x
				+ HIT_MARGIN * -1)] != '1'
			&& data->cubfile.map[(int)data->game.player.pos_y][(int)(new_x
				+ HIT_MARGIN * -1)] != 'F')
			data->game.player.pos_x = new_x;
	}
}

static void	move_player_y(t_data *data, double dir_y)
{
	double	new_y;

	if (1 / data->game.delta_time < 5)
		new_y = data->game.player.pos_y + dir_y * (MOVE_SPEED);
	else
		new_y = data->game.player.pos_y + dir_y * (MOVE_SPEED_FPS
				* data->game.delta_time);
	if (dir_y > 0)
	{
		if ((int)(new_y + HIT_MARGIN * 1) < data->game.map_height
			&& data->cubfile.map[(int)(new_y + HIT_MARGIN
				* 1)][(int)data->game.player.pos_x] != '1'
			&& data->cubfile.map[(int)(new_y + HIT_MARGIN
				* 1)][(int)data->game.player.pos_x] != 'F')
			data->game.player.pos_y = new_y;
	}
	else
	{
		if ((int)(new_y + HIT_MARGIN * -1) >= 0 && data->cubfile.map[(int)(new_y
				+ HIT_MARGIN * -1)][(int)data->game.player.pos_x] != '1'
			&& data->cubfile.map[(int)(new_y + HIT_MARGIN *
				-1)][(int)data->game.player.pos_x] != 'F')
			data->game.player.pos_y = new_y;
	}
}

void	update_player_pos(t_data *data)
{
	if (data->game.keys[XK_w])
	{
		move_player_x(data, data->game.player.dir_x);
		move_player_y(data, data->game.player.dir_y);
	}
	if (data->game.keys[XK_s])
	{
		move_player_x(data, -data->game.player.dir_x);
		move_player_y(data, -data->game.player.dir_y);
	}
	if (data->game.keys[XK_a])
	{
		move_player_x(data, -data->game.player.plane.plane_x);
		move_player_y(data, -data->game.player.plane.plane_y);
	}
	if (data->game.keys[XK_d])
	{
		move_player_x(data, data->game.player.plane.plane_x);
		move_player_y(data, data->game.player.plane.plane_y);
	}
}

void	update_player_dir(t_data *data)
{
	float	d_time;

	d_time = data->game.delta_time;
	if (data->game.keys[XK_Right] || data->game.keys[XK_Left])
	{
		if (data->game.keys[XK_Left])
			data->game.player.radian -= (DIR_SPEED * d_time);
		else if (data->game.keys[XK_Right])
			data->game.player.radian += (DIR_SPEED * d_time);
		data->game.player.dir_x = cos(data->game.player.radian);
		data->game.player.dir_y = sin(data->game.player.radian);
		data->game.player.plane.plane_x = -data->game.player.dir_y * FOV;
		data->game.player.plane.plane_y = data->game.player.dir_x * FOV;
	}
}
