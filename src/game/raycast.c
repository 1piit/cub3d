/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:19:26 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/26 16:43:03 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int get_real_rgb(int *side)
{
	char *temp;
	char *c_side[3];

	c_side[0] = ft_itoa(side[0]);
	c_side[1] = ft_itoa(side[1]);
	c_side[2] = ft_itoa(side[2]);
	temp = gc_strjoin(gc_strjoin(c_side[0], c_side[1], GEN), c_side[2], GEN);
	return (ft_atoi(temp));
}

void draw_ceilling(t_data *data, int ceilling)
{
	int i;
	int j;
	i = 0;
	while(i < data->game.win_height / 2)
	{
		j = 0;
		while(j  <  data->game.win_width)
		{
			my_mlx_put_pixel(&data->game.game_img, j, i, ceilling);
			j++;
		}
		i++;
	}
}
void draw_floor(t_data *data, int floor)
{
	int i;
	int j;

	i = data->game.win_height / 2;
	while(i < data->game.win_height)
	{
		j = 0;
		while(j < data->game.win_width)
		{
			my_mlx_put_pixel(&data->game.game_img, j, i, floor);
			j++;
		}
		i++;
	}
}
void draw_ceilfloor(t_data *data)
{
	static int flag = 0;

	if(flag == 0)
	{
		data->game.final_ceilling = get_real_rgb(data->cubfile.RGB_c);
		data->game.final_floor = get_real_rgb(data->cubfile.RGB_f);
	}
	flag++;
	draw_ceilling(data, data->game.final_ceilling);
	draw_floor(data, data->game.final_floor);
}

void draw_vlines(t_data *data, int i, int drawS, int drawE, int color)
{
	/* int y;
	static int flag = 0;
	if(!flag)
	{
		data->game.final_ceilling = get_real_rgb(data->cubfile.RGB_c);
		data->game.final_floor = get_real_rgb(data->cubfile.RGB_f);
	} */
	if (data->game.box.side == 1)
		color = color / 2;
	//flag = 1;
	//y = 0;
	/* while(y < drawS)
	{
		my_mlx_put_pixel(&data->game.game_img, i, y, data->game.final_ceilling);
		y++;
	} */
	while (drawS != drawE)
	{
		my_mlx_put_pixel(&data->game.game_img, i, drawS, color);
		drawS++;
	}
	/* while(y < data->game.win_height)
	{
		my_mlx_put_pixel(&data->game.game_img, i ,y, data->game.final_floor);
		y++;
	} */
}
void raycast_game(t_data *data)
{
	int lineHeight;
	int drawStart;
	int drawEnd;
	//int ratio;
	int color = 0x0CE9389;
	int i;
	i = 0;
	//ratio = data->img.win_height / 2;
	while(i < data->game.win_width)
	{
		data->game.player.camera_x = 2.0 * i / (double)data->game.win_width - 1.0;
		data->game.player.ray_dir_x = data->game.player.dir_x + data->game.player.plane.plane_x * data->game.player.camera_x;
		data->game.player.ray_dir_y = data->game.player.dir_y + data->game.player.plane.plane_y * data->game.player.camera_x;
		ft_dda(data, data->game.player.ray_dir_x, data->game.player.ray_dir_y);
		lineHeight = (int)(data->game.win_height/data->game.box.perp_wd) * 1.2;
		drawStart = -lineHeight / 2 + data->game.win_height / 2;
		drawEnd = lineHeight / 2 + data->game.win_height / 2;
		if(drawEnd >= data->game.win_height)
			drawEnd = data->game.win_height;
		if(drawStart < 0)
			drawStart = 0;
		draw_vlines(data, i, drawStart, drawEnd, color);
		i++;
	}
}
