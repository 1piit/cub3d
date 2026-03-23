/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 13:54:45 by pbride            #+#    #+#             */
/*   Updated: 2026/03/23 15:27:09 by ptricaud         ###   ########.fr       */
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
				data->game.player.pos_x = x /* + 0.5 */;
				data->game.player.pos_y = y /* + 0.5 */;
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

	//plane_loop(data);
}
//static int chiant = 0;
// faudra quand meme aller voir en detail l algo bresenham pour etre bien capable d expliquer tout ca
void bresenham(t_data *data, int start_x, int start_y, int end_x, int end_y)
{
	int dx;
	int dy;
	int step_x;
	int step_y;
	int err_factor;
	int save_err;
	dx = abs(end_x - start_x);
	dy = abs(end_y - start_y); 
	if(start_x < end_x)
		step_x = 1;
	else
		step_x = -1;
	if(start_y < end_y)
		step_y = 1;
	else
		step_y = -1;
	if(dx > dy)
		err_factor = dx / 2;
	else
		err_factor = -dy / 2;

	while(1)
	{
		if (start_x >= 0 && start_x < data->game.map_width * data->game.mini_map_scl 
			&& start_y >= 0 && start_y < data->game.map_height * data->game.mini_map_scl)
            my_mlx_put_pixel(&data->game.game_img, start_x, start_y, 0x009EE01);
		//printf("%d\n", chiant++);
		if(start_x == end_x && start_y == end_y)
			break;
		save_err = err_factor;
		if(save_err > -dx)
		{
			err_factor -= dy;
			start_x += step_x;
		}
		if(save_err < dy)
		{
			err_factor += dx;
			start_y += step_y;
		}
	}
}
void which_line(t_data *data, double ray_dx, double ray_dy)
{
	int map_x;
	int map_y;
	double side_dstx;
	double side_dsty;
	double rho_dstx;
	double rho_dsty;
	double perp_wd;
	/* double pixel_x;
	double pixel_y; */
	int step_x;
	int step_y;
	int hit = 0;
	int side;
	double hit_x;
	double hit_y;

	map_x = data->game.player.pos_x;
	map_y = data->game.player.pos_y;
	if(!ray_dx)
		rho_dstx = 1e30;
	else
		rho_dstx = fabs(1/ray_dx);
	if(!ray_dy)
		rho_dsty = 1e30;
	else
		rho_dsty = fabs(1/ray_dy);
	if(ray_dx < 0)
	{
		step_x = -1;
		side_dstx = (data->game.player.pos_x - map_x) * rho_dstx;
	}
	else
	{
		step_x = 1;
		side_dstx = (map_x + 1 - data->game.player.pos_x) * rho_dstx;
	}
	if(ray_dy < 0)
	{
		step_y = -1;
		side_dsty = (data->game.player.pos_y - map_y) * rho_dsty;
	}
	else
	{
		step_y = 1;
		side_dsty = (map_y + 1 - data->game.player.pos_y) * rho_dsty;
	}
	while(!hit)
	{
		if(side_dstx < side_dsty)
		{
			side_dstx += rho_dstx;
			map_x += step_x;
			side = 0;
		}
		else
		{
			side_dsty += rho_dsty;
			map_y += step_y;
			side = 1;
		}
		if (map_x < 0 || map_x >= data->game.map_width || 
            map_y < 0 || map_y >= data->game.map_height)
            break;
		if(data->cubfile.map[map_y][map_x] == '1')
			hit = 1;
	}
    if (side == 0)
        perp_wd = (side_dstx - rho_dstx);
    else
    {
		perp_wd = (side_dsty - rho_dsty);
	}	
	hit_x = data->game.player.pos_x + ray_dx * perp_wd;
	hit_y = data->game.player.pos_y + ray_dy * perp_wd;
	bresenham(data, (int)(data->game.player.pos_x * data->game.mini_map_scl) /* + data->game.mini_map_scl / 2 */, 
	(int)(data->game.player.pos_y * data->game.mini_map_scl) /* + data->game.mini_map_scl / 2 */, 
		(int)(hit_x * data->game.mini_map_scl) /* + data->game.mini_map_scl / 2 */, 
		(int)(hit_y * data->game.mini_map_scl) /* + data->game.mini_map_scl / 2 */);
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

	axis.x = data->game.player.pos_x - 0.5;
	axis.y = data->game.player.pos_y - 0.5;
	my_mlx_put_square(&data->game.game_img, axis, data->game.mini_map_scl, 0x00FFFF00);
}
