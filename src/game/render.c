/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 14:07:58 by pbride            #+#    #+#             */
/*   Updated: 2026/03/29 17:08:11 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	render_3d_scene(t_data *data)
{
	draw_ceilfloor(data);
	raycast_3d_scene(data);
}

static void	render_mini_map(t_data *data)
{
	draw_mini_map(data, data->cubfile.map);
	draw_player(data);
	raycast_mini_map(data, 10);
}

int	render_frame(t_data *data)
{
	data->game.fps = ft_itoa((int)(1 / data->game.delta_time));
	update_delta_time(data);
	render_3d_scene(data);
	render_mini_map(data);
	mlx_put_image_to_window(data->game.mlx, data->game.mlx_win,
		data->game.game_img.mlx_img, 0, 0);
	mlx_string_put(data->game.mlx,
		data->game.mlx_win, data->game.win_width - 40, 20,
		PLAYER_CLR, data->game.fps);
	cleanup_fps(data);
	return (0);
}
