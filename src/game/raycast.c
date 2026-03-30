/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:19:26 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/26 20:33:57 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	get_real_rgb(int *side)
{
	char	*temp;
	char	*c_side[3];

	c_side[0] = ft_itoa(side[0]);
	c_side[1] = ft_itoa(side[1]);
	c_side[2] = ft_itoa(side[2]);
	temp = gc_strjoin(gc_strjoin(c_side[0], c_side[1], GEN), c_side[2], GEN);
	return (ft_atoi(temp));
}

void	draw_ceilling(t_data *data, int ceilling)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->game.win_height / 2)
	{
		j = 0;
		while (j < data->game.win_width)
		{
			my_mlx_put_pixel(&data->game.game_img, j, i, ceilling);
			j++;
		}
		i++;
	}
}
void	draw_floor(t_data *data, int floor)
{
	int	i;
	int	j;

	i = data->game.win_height / 2;
	while (i < data->game.win_height)
	{
		j = 0;
		while (j < data->game.win_width)
		{
			my_mlx_put_pixel(&data->game.game_img, j, i, floor);
			j++;
		}
		i++;
	}
}
void	draw_ceilfloor(t_data *data)
{
	static int	flag = 0;

	if (!flag)
	{
		data->game.final_ceilling = get_real_rgb(data->cubfile.rgb_c);
		data->game.final_floor = get_real_rgb(data->cubfile.rgb_f);
	}
	flag = 1;
	draw_ceilling(data, data->game.final_ceilling);
	draw_floor(data, data->game.final_floor);
}

void	draw_vlines(t_data *data, int i, int drawS, int drawE, int color)
{


	/* int y;
	if(!flag)
	{
		data->game.final_ceilling = get_real_rgb(data->cubfile.RGB_c);
		data->game.final_floor = get_real_rgb(data->cubfile.RGB_f);
	} */
	if (data->game.box.side == 1)
		color = color / 2;
	// flag = 1;
	// y = 0;
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
}

// void	texture_on_img(t_data *data, t_line *line, )

static void	draw_texture(t_data *data, int draw_start, int draw_end,
		int line_height, int i, float wall_x)
{
	t_line	line;
	int		scale;

	line = (t_line){0};
	line.tex_x = (int)(wall_x * data->game.tex_img.img_width);
	if (line.tex_x >= data->game.tex_img.img_width)
		line.tex_x = data->game.tex_img.img_width - 1;
	line.x = i;
	line.y = draw_start;
	while (line.y < draw_end)
	{
		scale = line.y * data->game.tex_img.line_len - data->game.win_height
			* data->game.tex_img.line_len / 2 + line_height
			* data->game.tex_img.line_len / 2;
		line.tex_y = ((scale * data->game.tex_img.img_width) / line_height)
			/ data->game.tex_img.line_len;
		if (line.tex_y < 0)
			line.tex_y = 0;
		if (line.tex_y >= data->game.tex_img.img_width)
			line.tex_y = data->game.tex_img.img_width - 1;
		data->game.game_img.addr[line.y * data->game.game_img.line_len + line.x
			* (data->game.game_img.bits_per_pixel
				/ 8)] = data->game.tex_img.addr[line.tex_y
			* data->game.tex_img.line_len + line.tex_x
			* (data->game.tex_img.bits_per_pixel / 8)];
		data->game.game_img.addr[line.y * data->game.game_img.line_len + line.x
			* (data->game.game_img.bits_per_pixel / 8)
			+ 1] = data->game.tex_img.addr[line.tex_y
			* data->game.tex_img.line_len + line.tex_x
			* (data->game.tex_img.bits_per_pixel / 8) + 1];
		data->game.game_img.addr[line.y * data->game.game_img.line_len + line.x
			* (data->game.game_img.bits_per_pixel / 8)
			+ 2] = data->game.tex_img.addr[line.tex_y
			* data->game.tex_img.line_len + line.tex_x
			* (data->game.tex_img.bits_per_pixel / 8) + 2];
		line.y++;
	}
}

void	*raycast_game(void *arg)
{
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	int				i;
	float			wall_x;
	t_box			box;
	t_thread_data	*t_data_ptr;
	t_data			*data;

	t_data_ptr = (t_thread_data *)arg;
	data = t_data_ptr->data;
	while (1)
	{
		// Wait for main thread to signal start of the frame
		pthread_barrier_wait(&data->barrier_start);
		if (data->quit_threads)
			break ;
		i = t_data_ptr->start_x;
		while (i < t_data_ptr->end_x)
		{
			t_data_ptr->th_player.camera_x = 2.0 * i
				/ (float)data->game.win_width - 1.0;
			t_data_ptr->th_player.ray_dir_x = t_data_ptr->th_player.dir_x
				+ t_data_ptr->th_player.plane.plane_x
				* t_data_ptr->th_player.camera_x;
			t_data_ptr->th_player.ray_dir_y = t_data_ptr->th_player.dir_y
				+ t_data_ptr->th_player.plane.plane_y
				* t_data_ptr->th_player.camera_x;
			ft_dda(data, &box, t_data_ptr->th_player.ray_dir_x,
				t_data_ptr->th_player.ray_dir_y, &t_data_ptr->th_player);
			lineHeight = (int)(data->game.win_height / box.perp_wd) * 1.3;
			drawStart = -lineHeight / 2 + data->game.win_height / 2;
			drawEnd = lineHeight / 2 + data->game.win_height / 2;
			if (drawEnd >= data->game.win_height)
				drawEnd = data->game.win_height;
			if (drawStart < 0)
				drawStart = 0;
			if (box.side == 0)
				wall_x = t_data_ptr->th_player.pos_y + box.perp_wd
					* t_data_ptr->th_player.ray_dir_y;
			else
				wall_x = t_data_ptr->th_player.pos_x + box.perp_wd
					* t_data_ptr->th_player.ray_dir_x;
			wall_x -= floor(wall_x);
			draw_texture(data, drawStart, drawEnd, lineHeight, i, wall_x);
			i++;
		}
		// Signal main thread that this frame section is done
		pthread_barrier_wait(&data->barrier_start);
	}
	return (NULL);
}
