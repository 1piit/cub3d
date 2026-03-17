/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:45 by pbride            #+#    #+#             */
/*   Updated: 2026/03/17 19:48:29 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	update_player_pos(t_data *data)
{
	double	new_axis;
	double	move_speed;

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

void	update_player_dir(t_data *data)
{
	double	move_speed;

	move_speed = 0.05;
	if (data->game.keys[XK_Left])
	{
		data->game.player.radian -= move_speed;
	}
	else if (data->game.keys[XK_Right])
	{
		data->game.player.radian += move_speed;
	}
	data->game.player.dir_x = cos(data->game.player.radian);
	data->game.player.dir_y = sin(data->game.player.radian);
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
				data->game.player.pos_x = x;
				data->game.player.pos_y = y;
			}
			x++;
		}
		y++;
	}
}

void	draw_line(t_data *data)
{
	int		scl = data->game.mini_map_scl;

	double	pixelX = data->game.player.pos_x * scl + scl / 2;
	double	pixelY = data->game.player.pos_y * scl + scl / 2;

	double	deltaX = data->game.player.dir_x;
	double	deltaY = data->game.player.dir_y;

	int		pixels = scl;

	while (pixels)
	{
		my_mlx_put_pixel(&data->game.game_img, pixelX, pixelY, 0x0009EE01);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}

void	draw_player(t_data *data)
{
	t_axis	axis;

	axis.x = data->game.player.pos_x;
	axis.y = data->game.player.pos_y;
	my_mlx_put_square(&data->game.game_img, axis, data->game.mini_map_scl, 0x00FFFF00);
}
