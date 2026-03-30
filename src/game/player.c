/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:45 by pbride            #+#    #+#             */
/*   Updated: 2026/03/26 19:35:30 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

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
	if(data->game.keys[XK_Right] || data->game.keys[XK_Left])
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
	//printf("player.dir_y=%f player.dir_x=%f\n", data->game.player.dir_x, data->game.player.dir_y);
}

void which_line(t_data *data, float ray_dx, float ray_dy)
{
	ft_dda(data, &data->game.box, ray_dx, ray_dy, &data->game.player);
	bresenham(data, (int)(data->game.player.pos_x * data->game.mini_map_scl),
	(int)(data->game.player.pos_y * data->game.mini_map_scl),
	(int)(data->game.box.hit_x * data->game.mini_map_scl),
	(int)(data->game.box.hit_y * data->game.mini_map_scl));
}

void	draw_line(t_data *data, int nb)
{
	int 	i;
	float	camera_x;
	float	ray_dir_x;
	float	ray_dir_y;

	i = 0;
	while (i < nb)
	{
		camera_x = 2 * i / (float)(nb - 1) - 1;
		ray_dir_x = data->game.player.dir_x + data->game.player.plane.plane_x * camera_x;
		ray_dir_y = data->game.player.dir_y + data->game.player.plane.plane_y * camera_x;
		which_line(data, ray_dir_x, ray_dir_y);
		i++;
	}
}

void	draw_player(t_data *data)
{
	t_axis	axis;

	axis.x = data->game.player.pos_x - 0.5;
	axis.y = data->game.player.pos_y - 0.5;
	my_put_circle(&data->game.game_img, axis,
		data->game.mini_map_scl / 2,
		data->game.mini_map_scl);
}


/* void plane_loop(t_data *data)
{
	int pixels;
	float delta_x;
	float delta_y;

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
} */
/* void	get_plane_val(t_data *data, float x, float y)
{
    int	scl = data->game.mini_map_scl;
    data->game.player.plane.plane_x_start = (data->game.player.dir_x * scl) + data->game.player.pos_x * scl + scl / 2;
    data->game.player.plane.plane_y_start = (data->game.player.dir_y * scl) + data->game.player.pos_y * scl + scl / 2;
    data->game.player.plane.end_x[0] = data->game.player.plane.plane_x_start + x * scl;
    data->game.player.plane.end_y[0] = data->game.player.plane.plane_y_start + y * scl;
	data->game.player.plane.end_x[1] = data->game.player.plane.plane_x_start - x * scl;
    data->game.player.plane.end_y[1] = data->game.player.plane.plane_y_start - y * scl;

	plane_loop(data);
} */
//static int chiant = 0;
