/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:42:04 by pbride            #+#    #+#             */
/*   Updated: 2026/03/12 19:26:22 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	render_frame(t_data *data)
{
	printf("render_next_frame\n");
	draw_mini_map(data, data->cubfile.map);
	mlx_put_image_to_window(data->game.mlx, data->game.mlx_win,
		data->game.game_img.mlx_img, 0, 0);
	return (0);
}

int	game_loop(t_data *data)
{
	sleep(1);
	if (data->game.keys[XK_w])
		printf("print W - North\n");
	else if (data->game.keys[XK_s])
		printf("print S - South\n");
	else if (data->game.keys[XK_a])
		printf("print A - East\n");
	else if (data->game.keys[XK_d])
		printf("print D - West\n");
	else if (data->game.keys[XK_Escape])
		close_handler(data);
	render_frame(data);
	return (0);
}
