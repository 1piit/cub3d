/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:12:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/11 11:24:36 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_game_img(t_data *data)
{
	data->game_img = (t_img){0};
	data->game_img.mlx_img = mlx_new_image(data->mlx, data->win_width,
			data->win_height);
	if (!data->game_img.mlx_img)
		err_cleanup_exit(data, "mlx new image", 1);
	data->game_img.addr = mlx_get_data_addr(data->game_img.mlx_img,
			&data->game_img.bits_per_pixel, &data->game_img.line_len,
			&data->game_img.endian);
	if (!data->game_img.addr)
		err_cleanup_exit(data, "mlx get data addr", 1);
}
