/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:42:04 by pbride            #+#    #+#             */
/*   Updated: 2026/03/25 20:43:12 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	render_frame(t_data *data)
{
	t_time *time;

	time = get_time_ms();
	draw_ceilfloor(data);
	//get_plane_val(data, data->game.player.plane.plane_x, data->game.player.plane.plane_y);
	raycast_game(data);
	draw_mini_map(data, data->cubfile.map);
	draw_player(data);
	draw_line(data, 10);
	mlx_put_image_to_window(data->game.mlx, data->game.mlx_win,
		data->game.game_img.mlx_img, 0, 0);
	gettimeofday(&time->c_time, NULL);
	return (1);
}

int	game_loop(t_data *data)
{
	static int nb_calls = 0;
	t_time *time;

	long long diff_ms;
	time = get_time_ms();
	//usleep(100);
	if (data->game.keys[XK_Escape])
		close_handler(data);
	update_player_pos(data);
	update_player_dir(data);
	//update_player_plane(data);
	if(render_frame(data))
		nb_calls++;
	diff_ms = (time->c_time.tv_sec - time->s_time.tv_sec) * 1000;
    diff_ms += (time->c_time.tv_usec - time->s_time.tv_usec) / 1000;
	if(diff_ms >= 1000)
	{
		printf("%dFPS\n", nb_calls);
		nb_calls = 0;
		gettimeofday(&time->s_time, NULL);
	}
	return (0);
}
