/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:12:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/09 17:12:36 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_game_img(t_data *data)
{
	data->game_img.mlx_img = mlx_new_image(data->mlx, data->win_width,
			data->win_height);
	data->game_img.addr = mlx_get_data_addr(data->game_img.mlx_img,
			&data->game_img.bits_per_pixel, &data->game_img.line_len,
			&data->game_img.endian);
}
