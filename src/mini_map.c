/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:43:18 by pbride            #+#    #+#             */
/*   Updated: 2026/03/02 16:45:01 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	init_mini_map(t_data *data)
{
	t_img	mini_map;

	mini_map.mlx_img = mlx_new_image(data->mlx, 1920, 1080);
	mini_map.addr = mlx_get_data_addr(mini_map.mlx_img,
			&mini_map.bits_per_pixel, &mini_map.line_len, &mini_map.endian);
	data->mini_map = mini_map;
}

void	render_mini_map(t_data *data, char **map)
{
	t_axis	axis;

	axis.y = 0;
	while (map[axis.y])
	{
		axis.x = 0;
		while (map[axis.y][axis.x])
		{
			if (map[axis.y][axis.x] == '1')
				my_mlx_put_square(&data->mini_map, axis, 15, 0x00FF0000);
			if (map[axis.y][axis.x] == 'N')
				my_mlx_put_triangle_no(&data->mini_map, axis, 15, 0x00FFFF00);
			else if (map[axis.y][axis.x] == 'S')
				my_mlx_put_triangle_so(&data->mini_map, axis, 15, 0x00FFFF00);
			else if (map[axis.y][axis.x] == 'W')
				my_mlx_put_triangle_we(&data->mini_map, axis, 15, 0x00FFFF00);
			else if (map[axis.y][axis.x] == 'E')
				my_mlx_put_triangle_ea(&data->mini_map, axis, 15, 0x00FFFF00);
			axis.x++;
		}
		axis.y++;
	}
	mlx_put_image_to_window(data->mlx,
		data->mlx_win,
		data->mini_map.mlx_img, 0, 0);
}
