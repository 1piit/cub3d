/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:19:26 by ptricaud          #+#    #+#             */
/*   Updated: 2026/04/01 12:08:00 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	raycast_mini_map(t_data *data, int nb)
{
	int		i;
	double	camera_x;
	t_axf	ray_dir;
	t_axi	start;
	t_axi	end;

	i = 0;
	while (i < nb)
	{
		camera_x = 2 * i / (double)(nb - 1) - 1;
		ray_dir.x = data->game.player.dir_x + data->game.player.plane.plane_x
			* camera_x;
		ray_dir.y = data->game.player.dir_y + data->game.player.plane.plane_y
			* camera_x;
		ft_dda_minimap(data, ray_dir, &data->game.box);
		start.x = (int)(data->game.player.pos_x * data->game.mini_map_scl);
		start.y = (int)(data->game.player.pos_y * data->game.mini_map_scl);
		end.x = (int)(data->game.box.hit_x * data->game.mini_map_scl);
		end.y = (int)(data->game.box.hit_y * data->game.mini_map_scl);
		ft_bresenham(data, start, end);
		i++;
	}
}

void	*raycast_game(void *arg)
{
	t_box			box;
	int				i;
	t_thread_data	*t_data_ptr;
	t_data			*data;

	t_data_ptr = (t_thread_data *)arg;
	data = t_data_ptr->data;
	while (1)
	{
		pthread_barrier_wait(&data->barrier_start);
		if (data->quit_threads)
			break ;
		i = t_data_ptr->start_x;
		while (i < t_data_ptr->end_x)
		{
			dda_raycast(data, t_data_ptr, &box, i);
			if (perp_wd_check(&i, box))
				continue ;
			post_dda(t_data_ptr, data, box);
			draw_wall(t_data_ptr, data, i, &box);
			i++;
		}
		pthread_barrier_wait(&data->barrier_start);
	}
	return (NULL);
}
