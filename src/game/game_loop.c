/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:42:04 by pbride            #+#    #+#             */
/*   Updated: 2026/03/24 18:02:22 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	render_frame(t_data *data)
{
	// int i = 0;
	draw_ceilfloor(data);
	//get_plane_val(data, data->game.player.plane.plane_x, data->game.player.plane.plane_y);
	raycast_game(data);
	draw_mini_map(data, data->cubfile.map);
	draw_player(data);
	draw_line(data, 2580);
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
