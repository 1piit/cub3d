/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:43:18 by pbride            #+#    #+#             */
/*   Updated: 2026/02/26 17:54:58 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_mini_map(t_data *data)
{
	t_img	mini_map;

	mini_map = data->mini_map;
	mini_map.mlx_img = mlx_new_image(data->mlx, 1920, 1080);
	mini_map.addr = mlx_get_data_addr(mini_map.mlx_img,
			&mini_map.bits_per_pixel, &mini_map.line_len, &mini_map.endian);
	
}
