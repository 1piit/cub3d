/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:42:04 by pbride            #+#    #+#             */
/*   Updated: 2026/03/12 18:54:16 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	render_next_frame(t_data *data)
{
	(void)data;
	sleep(1);
	printf("render_next_frame\n");
	return (0);
}

void	game_loop(t_data *data)
{
	draw_mini_map(data, data->cubfile.map);
	mlx_put_image_to_window(data->game.mlx, data->game.mlx_win,
		data->game.game_img.mlx_img, 0, 0);
	mlx_loop_hook(data->game.mlx, render_next_frame, &data);
	mlx_loop(data->game.mlx);
}
