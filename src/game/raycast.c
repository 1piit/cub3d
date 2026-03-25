/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:19:26 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/25 21:16:02 by pbride           ###   ########.fr       */
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
	temp = ft_strjoin(ft_strjoin(c_side[0], c_side[1]), c_side[2]);
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
	int ceilling;
	int floor;

	ceilling = get_real_rgb(data->cubfile.rgb_c);
	floor = get_real_rgb(data->cubfile.rgb_f);
	draw_ceilling(data, ceilling);
	draw_floor(data, floor);
}

void draw_vlines(t_data *data, int i, int drawS, int drawE, int color)
{

	if (data->game.box.side == 1)
		color = color / 2;
	while (drawS != drawE)
	{
		my_mlx_put_pixel(&data->game.game_img, i, drawS, color);
		drawS++;
	}
}

//void	texture_on_img(t_data *data, t_line *line, )

static void	draw_texture(t_data *data, int draw_start, int draw_end, int line_height, int i)
{
	double	wall_x;
	t_line	line;
	int		scale;

	if (data->game.box.side == 0)
		wall_x = data->game.player.pos_y + data->game.box.perp_wd * data->game.player.ray_dir_y;
	else
		wall_x = data->game.player.pos_x + data->game.box.perp_wd * data->game.player.ray_dir_x;
	wall_x -= floor(wall_x);
	line = (t_line){0};
	line.tex_x = (int)(wall_x * data->game.tex_img.img_width);
	if (line.tex_x >= data->game.tex_img.img_width)
		line.tex_x = data->game.tex_img.img_width - 1;
	line.x = i;
	line.y = draw_start;
	while (line.y < draw_end)
	{
		scale = line.y * data->game.tex_img.line_len - data->game.win_height * data->game.tex_img.line_len / 2 + line_height * data->game.tex_img.line_len / 2;
		line.tex_y = ((scale * data->game.tex_img.img_width) / line_height) / data->game.tex_img.line_len;
		if (line.tex_y < 0)
			line.tex_y = 0;
		if (line.tex_y >= data->game.tex_img.img_width)
			line.tex_y = data->game.tex_img.img_width - 1;
		data->game.game_img.addr[line.y * data->game.game_img.line_len + line.x * (data->game.game_img.bits_per_pixel / 8)] = data->game.tex_img.addr[line.tex_y * data->game.tex_img.line_len + line.tex_x * (data->game.tex_img.bits_per_pixel / 8)];
		data->game.game_img.addr[line.y * data->game.game_img.line_len + line.x * (data->game.game_img.bits_per_pixel / 8) + 1] = data->game.tex_img.addr[line.tex_y * data->game.tex_img.line_len + line.tex_x * (data->game.tex_img.bits_per_pixel / 8) + 1];
		data->game.game_img.addr[line.y * data->game.game_img.line_len + line.x * (data->game.game_img.bits_per_pixel / 8) + 2] = data->game.tex_img.addr[line.tex_y * data->game.tex_img.line_len + line.tex_x * (data->game.tex_img.bits_per_pixel / 8) + 2];
		line.y++;
	}
}

void raycast_game(t_data *data)
{
	int lineHeight;
	int drawStart;
	int drawEnd;
	//int ratio;
	//int color = 0x0CE9389;
	int i;
	i = 0;
	//ratio = data->img.win_height / 2;
	while(i < data->game.win_width)
	{
		data->game.player.camera_x = 2.0 * i / (double)data->game.win_width - 1.0;
		data->game.player.ray_dir_x = data->game.player.dir_x + data->game.player.plane.plane_x * data->game.player.camera_x;
		data->game.player.ray_dir_y = data->game.player.dir_y + data->game.player.plane.plane_y * data->game.player.camera_x;
		ft_dda(data, data->game.player.ray_dir_x, data->game.player.ray_dir_y);
		lineHeight = (int)(data->game.win_height/data->game.box.perp_wd);
		drawStart = -lineHeight / 2 + data->game.win_height / 2;
		drawEnd = lineHeight / 2 + data->game.win_height / 2;
		if(drawEnd >= data->game.win_height)
			drawEnd = data->game.win_height - 1;
		if(drawStart < 0)
			drawStart = 0;
		//draw_vlines(data, i, drawStart, drawEnd, color);
		draw_texture(data, drawStart, drawEnd, lineHeight, i);
		i++;
	}
}
