/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:45 by pbride            #+#    #+#             */
/*   Updated: 2026/03/17 18:14:23 by ptricaud         ###   ########.fr       */
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

void	init_player_dir(t_data *data, char c)
{
	if (c == 'N')
	{
		data->game.player.dir_y = data->game.player.pos_y - 1;
		data->game.player.dir_x = data->game.player.pos_x;
	}
	else if (c == 'S')
	{
		data->game.player.dir_y = data->game.player.pos_y + 1;
		data->game.player.dir_x = data->game.player.pos_x;
	}
	else if (c == 'E')
	{
		data->game.player.dir_y = data->game.player.pos_y;
		data->game.player.dir_x = data->game.player.pos_x + 1;
	}
	else if (c == 'W')
	{
		data->game.player.dir_y = data->game.player.pos_y;
		data->game.player.dir_x = data->game.player.pos_x - 1;
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
	double	deltaY = data->game.player.dir_y - data->game.player.pos_y;
	double	deltaX = data->game.player.dir_x - data->game.player.pos_x;
	
	int flag = 0;
	
	if(!flag)
	{
		printf("\n\n\n%f && %f\n\n\n", deltaY, deltaX);
		flag = 1;
	}
	double	pixelX = data->game.player.pos_x;
	double	pixelY = data->game.player.pos_y;
	int	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	while (pixels)
	{
		my_mlx_put_pixel(&data->game.game_img, 
			data->game.player.pos_x * data->game.mini_map_scl + pixelX , 
			data->game.player.pos_y * data->game.mini_map_scl + pixelY, 0x0009EE01);
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
