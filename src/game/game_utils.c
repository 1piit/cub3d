/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:12:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/12 12:46:23 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	init_window(t_data *data)
{
	get_screen_size(&data->win_width, &data->win_height);
	data->mlx_win = mlx_new_window(data->mlx, data->win_width,
			data->win_height - 70, "cub3D - P2P");
	if (!data->mlx_win)
		cleanup_all_exit(data, "mlx new window", 1);
}

static void	init_game_img(t_data *data)
{
	data->game_img = (t_img){0};
	data->game_img.mlx_img = mlx_new_image(data->mlx, data->win_width,
			data->win_height);
	if (!data->game_img.mlx_img)
		cleanup_all_exit(data, "mlx new image", 1);
	data->game_img.addr = mlx_get_data_addr(data->game_img.mlx_img,
			&data->game_img.bits_per_pixel, &data->game_img.line_len,
			&data->game_img.endian);
	if (!data->game_img.addr)
		cleanup_all_exit(data, "mlx get data addr", 1);
}

static void	init_hook(t_data *data)
{
	mlx_key_hook(data->mlx_win, key_handler, data);
	mlx_hook(data->mlx_win, 17, 0, close_handler, data);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		cleanup_all_exit(data, "mlx init", 1);
	init_window(data);
	init_game_img(data);
	init_hook(data);
}
