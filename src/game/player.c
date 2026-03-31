/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:45 by pbride            #+#    #+#             */
/*   Updated: 2026/03/31 17:23:53 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void    move_player_x(t_data *data, double dir_x)
{
    //double    d_time;
    double    new_x;

    //d_time = data->game.delta_time;
	if(1/data->game.delta_time < 5)
    	new_x = data->game.player.pos_x + dir_x * (MOVE_SPEED );
	else
    	new_x = data->game.player.pos_x + dir_x * (MOVE_SPEED_FPS * data->game.delta_time);
    if (dir_x > 0)
    {
        if ((int)(new_x + HIT_MARGIN * 1) < data->game.map_width
        && data->cubfile.map[(int)data->game.player.pos_y] \
    [(int)(new_x + HIT_MARGIN * 1)] != '1' && data->cubfile.map[(int)data->game.player.pos_y] \
    [(int)(new_x + HIT_MARGIN * 1)] != 'F')
            data->game.player.pos_x = new_x;
    }
    else
    {
        if ((int)(new_x + HIT_MARGIN * -1) >= 0
        && data->cubfile.map[(int)data->game.player.pos_y] \
    [(int)(new_x + HIT_MARGIN * -1)] != '1' && data->cubfile.map[(int)data->game.player.pos_y] \
    [(int)(new_x + HIT_MARGIN * -1)] != 'F')
            data->game.player.pos_x = new_x;
    }
}

static void    move_player_y(t_data *data, double dir_y)
{
    //double    d_time;
    double    new_y;
	if(1/data->game.delta_time < 5)
    	new_y = data->game.player.pos_y + dir_y * (MOVE_SPEED );
	else
    	new_y = data->game.player.pos_y + dir_y * (MOVE_SPEED_FPS * data->game.delta_time);
    if (dir_y > 0)
    {
        if ((int)(new_y + HIT_MARGIN * 1) < data->game.map_height
        && data->cubfile.map[(int)(new_y + HIT_MARGIN * 1)] \
    [(int)data->game.player.pos_x] != '1' && data->cubfile.map[(int)(new_y + HIT_MARGIN * 1)] \
    [(int)data->game.player.pos_x] != 'F')
            data->game.player.pos_y = new_y;
    }
    else
    {
        if ((int)(new_y + HIT_MARGIN * -1) >= 0
        && data->cubfile.map[(int)(new_y + HIT_MARGIN * -1)] \
    [(int)data->game.player.pos_x] != '1' && data->cubfile.map[(int)(new_y + HIT_MARGIN * -1)] \
    [(int)data->game.player.pos_x] != 'F')
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

/* void which_line(t_data *data, float ray_dx, float ray_dy)
{
	ft_dda(data, &data->game.box, ray_dx, ray_dy, &data->game.player);
	bresenham(data, (int)(data->game.player.pos_x * data->game.mini_map_scl),
	(int)(data->game.player.pos_y * data->game.mini_map_scl),
	(int)(data->game.box.hit_x * data->game.mini_map_scl),
	(int)(data->game.box.hit_y * data->game.mini_map_scl));
} */

/* void	draw_line(t_data *data, int nb)
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
} */