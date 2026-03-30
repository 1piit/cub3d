/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:42:04 by pbride            #+#    #+#             */
/*   Updated: 2026/03/26 20:29:00 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	render_frame(t_data *data)
{
	update_delta_time(data);
	static int times = 0;
	times++;
	if(times >= 10)
	{
		printf("delta_time=%f\n", 1/data->game.delta_time);
		times = 0;
	}
	draw_ceilfloor(data);
	//get_plane_val(data, data->game.player.plane.plane_x, data->game.player.plane.plane_y);
	
	int i = 0;
	while (i < NUM_THREADS)
	{
		data->thread_data[i].th_player = data->game.player;
		i++;
	}
	// Signal aux threads de commencer la frame
	pthread_barrier_wait(&data->barrier_start);
	// Attendre que tous les threads aient terminé la frame
	pthread_barrier_wait(&data->barrier_start);

	draw_mini_map(data, data->cubfile.map);
	draw_player(data);
	draw_line(data, 10);
	mlx_put_image_to_window(data->game.mlx, data->game.mlx_win,
		data->game.game_img.mlx_img, 0, 0);
	return (1);
}

int	game_loop(t_data *data)
{
	if (data->game.keys[XK_Escape])
		close_handler(data);
	update_player_pos(data);
	update_player_dir(data);
	render_frame(data);
	return (0);
}
