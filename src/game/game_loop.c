/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:42:04 by pbride            #+#    #+#             */
/*   Updated: 2026/03/23 15:29:32 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	render_frame(t_data *data)
{
	// int i = 0;
	//printf("render_next_frame\n");
	// double delta_x = (data->game.player.plane.end_x[0] - data->game.player.plane.end_x[1]);
	// double delta_y = (data->game.player.plane.end_y[0] - data->game.player.plane.end_y[1]);
	draw_mini_map(data, data->cubfile.map);
	draw_player(data);
	get_plane_val(data, data->game.player.plane.plane_x, data->game.player.plane.plane_y);
	draw_line(data, 2580);
/* 	while( data->game.player.radian < 0.66 && data->game.player.radian > -0.66)
	{
		data->game.player.radian += 0.01;
	} */
	//raycast_game(data);
	mlx_put_image_to_window(data->game.mlx, data->game.mlx_win,
		data->game.game_img.mlx_img, 0, 0);
	return (0);
}

int	game_loop(t_data *data)
{
	usleep(100);
	if (data->game.keys[XK_Escape])
		close_handler(data);
	update_player_pos(data);
	update_player_dir(data);
	//update_player_plane(data);
	render_frame(data);
	return (0);
}
