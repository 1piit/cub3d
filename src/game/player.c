/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:45 by pbride            #+#    #+#             */
/*   Updated: 2026/03/20 12:22:14 by ptricaud         ###   ########.fr       */
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
	double fov = 0.66;
	
	move_speed = 0.05;
	if(data->game.keys[XK_Right] || data->game.keys[XK_Left])
	{
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
		data->game.player.plane.plane_x = -data->game.player.dir_y * fov;
		data->game.player.plane.plane_y = data->game.player.dir_x * fov;
	}
	printf("player.dir_y=%f player.dir_x=%f\n", data->game.player.dir_x, data->game.player.dir_y);
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

void init_plane(t_data *data, char c)
{
	double fov = 0.66;
	if (c == 'N')
	{
		data->game.player.plane.plane_x = fov;
		data->game.player.plane.plane_y = 0;
	}
	else if (c == 'S')
	{
		data->game.player.plane.plane_x = -fov;
		data->game.player.plane.plane_y = 0;
	}
	else if (c == 'E')
	{
		data->game.player.plane.plane_x = 0;
		data->game.player.plane.plane_y = fov;
	}
	else if (c == 'W')
	{
		data->game.player.plane.plane_x = 0;
		data->game.player.plane.plane_y = -fov;
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
				data->game.player.pos_x = x;
				data->game.player.pos_y = y;
			}
			x++;
		}
		y++;
	}
}
void plane_loop(t_data *data)
{
	int pixels;
	double delta_x;
	double delta_y;
	
	delta_x = (data->game.player.plane.end_x[0] - data->game.player.plane.end_x[1]);
	delta_y = (data->game.player.plane.end_y[0] - data->game.player.plane.end_y[1]);
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
    while (pixels)
    {
        my_mlx_put_pixel(&data->game.game_img, data->game.player.plane.end_x[1], data->game.player.plane.end_y[1], 0x003399FF);
        data->game.player.plane.end_x[1] += delta_x;
        data->game.player.plane.end_y[1] += delta_y;
        --pixels;
    }
}
void	get_plane_val(t_data *data, double x, double y)
{
    int	scl = data->game.mini_map_scl;
    data->game.player.plane.plane_x_start = (data->game.player.dir_x * scl) + data->game.player.pos_x * scl + scl / 2;
    data->game.player.plane.plane_y_start = (data->game.player.dir_y * scl) + data->game.player.pos_y * scl + scl / 2;
    data->game.player.plane.end_x[0] = data->game.player.plane.plane_x_start + x * scl;
    data->game.player.plane.end_y[0] = data->game.player.plane.plane_y_start + y * scl;
	data->game.player.plane.end_x[1] = data->game.player.plane.plane_x_start - x * scl;
    data->game.player.plane.end_y[1] = data->game.player.plane.plane_y_start - y * scl;

	plane_loop(data);
}
void which_line(t_data *data, double ray_dx, double ray_dy)
{
	int hit = 0;
	double cur_x = data->game.player.pos_x;
	double cur_y = data->game.player.pos_y;
	double pixel_x;
	double pixel_y;
	double step = 0.05;
	int x_pos;
	int y_pos;
	while(!hit)
	{
		cur_x += ray_dx * step;
		cur_y += ray_dy * step;
		x_pos = (int)cur_x;
		y_pos = (int)cur_y;
        if (x_pos < 0 || x_pos >= data->game.map_width)
            break;
        if (y_pos < 0 || y_pos >= data->game.map_height)
            break;
		if(data->cubfile.map[y_pos][x_pos] == '1')
		{
			hit = 1;
			continue;
		}
		pixel_x = cur_x * data->game.mini_map_scl + data->game.mini_map_scl / 2;
		pixel_y = cur_y * data->game.mini_map_scl + data->game.mini_map_scl / 2;
		my_mlx_put_pixel(&data->game.game_img, pixel_x, pixel_y, 0x0009EE01);
	}
}

void	draw_line(t_data *data, int nb)
{
	int i = 0;
	double camera_x;
	double ray_dir_x;
	double ray_dir_y;
	while (i < nb)
    {
        camera_x = 2 * i / (double)(nb - 1) - 1;

        ray_dir_x = data->game.player.dir_x + data->game.player.plane.plane_x * camera_x;
        ray_dir_y = data->game.player.dir_y + data->game.player.plane.plane_y * camera_x;
		which_line(data, ray_dir_x, ray_dir_y);
        i++;
    }
}

void	draw_player(t_data *data)
{
	t_axis	axis;

	axis.x = data->game.player.pos_x;
	axis.y = data->game.player.pos_y;
	my_mlx_put_square(&data->game.game_img, axis, data->game.mini_map_scl, 0x00FFFF00);
}
