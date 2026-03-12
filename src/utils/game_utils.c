/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:12:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/12 19:30:43 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	init_window(t_data *data)
{
	get_screen_size(&data->game.win_width, &data->game.win_height);
	data->game.mlx_win = mlx_new_window(data->game.mlx, data->game.win_width,
			data->game.win_height - 70, "cub3D - P2P");
	if (!data->game.mlx_win)
		cleanup_all_exit(data, "mlx new window", 1);
}

static void	init_game_img(t_data *data)
{
	data->game.game_img = (t_img){0};
	data->game.game_img.mlx_img = mlx_new_image(data->game.mlx, data->game.win_width,
			data->game.win_height);
	if (!data->game.game_img.mlx_img)
		cleanup_all_exit(data, "mlx new image", 1);
	data->game.game_img.addr = mlx_get_data_addr(data->game.game_img.mlx_img,
			&data->game.game_img.bits_per_pixel, &data->game.game_img.line_len,
			&data->game.game_img.endian);
	if (!data->game.game_img.addr)
		cleanup_all_exit(data, "mlx get data addr", 1);
}

static void	init_hooks(t_data *data)
{
	mlx_hook(data->game.mlx_win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->game.mlx_win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(data->game.mlx_win, DestroyNotify, 0, close_handler, data);
	mlx_loop_hook(data->game.mlx, game_loop, data);
}

void	init_game(t_data *data)
{
	data->game.mlx = mlx_init();
	if (!data->game.mlx)
		cleanup_all_exit(data, "mlx init", 1);
	init_window(data);
	init_game_img(data);
	init_hooks(data);
}
