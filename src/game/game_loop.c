/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:42:04 by pbride            #+#    #+#             */
/*   Updated: 2026/04/01 12:11:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	render_frame(t_data *data)
{
	int	i;

	data->game.fps = ft_itoa((int)(1 / data->game.delta_time));
	update_delta_time(data);
	draw_ceilfloor(data);
	i = 0;
	while (i < NUM_THREADS)
	{
		data->thread_data[i].th_player = data->game.player;
		i++;
	}
	pthread_barrier_wait(&data->barrier_start);
	pthread_barrier_wait(&data->barrier_start);
	draw_mini_map(data, data->cubfile.map);
	draw_player(data);
	raycast_mini_map(data, 10);
	mlx_put_image_to_window(data->game.mlx, data->game.mlx_win,
		data->game.game_img.mlx_img, 0, 0);
	mlx_string_put(data->game.mlx, data->game.mlx_win, data->game.win_width
		- 40, 20, PLAYER_CLR, data->game.fps);
	cleanup_fps(data);
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
