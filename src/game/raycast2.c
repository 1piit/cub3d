/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 12:05:33 by ptricaud          #+#    #+#             */
/*   Updated: 2026/04/01 12:10:48 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	post_dda(t_thread_data *th_data, t_data *data, t_box box)
{
	th_data->ray.line_height = (int)(data->game.win_height / box.perp_wd);
	th_data->ray.draw_start = -th_data->ray.line_height / 2
		+ data->game.win_height / 2;
	th_data->ray.draw_end = th_data->ray.line_height / 2 + data->game.win_height
		/ 2;
	if (th_data->ray.draw_end >= data->game.win_height)
		th_data->ray.draw_end = data->game.win_height - 1;
	if (th_data->ray.draw_start < 0)
		th_data->ray.draw_start = 0;
}

void	pre_dda(t_box *box, t_thread_data *th_data, t_data *data, int i)
{
	(*box) = (t_box){0};
	th_data->th_player.camera_x = 2.0 * i / (float)data->game.win_width - 1.0;
	th_data->th_player.ray_dir.x = th_data->th_player.dir_x
		+ th_data->th_player.plane.plane_x * th_data->th_player.camera_x;
	th_data->th_player.ray_dir.y = th_data->th_player.dir_y
		+ th_data->th_player.plane.plane_y * th_data->th_player.camera_x;
}

void	dda_raycast(t_data *data, t_thread_data *th_data, t_box *box, int i)
{
	pre_dda(box, th_data, data, i);
	ft_dda(data, th_data, th_data->th_player.ray_dir, box);
}

int	perp_wd_check(int *i, t_box box)
{
	if (box.perp_wd <= 0)
	{
		(*i)++;
		return (1);
	}
	return (0);
}
