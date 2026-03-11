/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:43:18 by pbride            #+#    #+#             */
/*   Updated: 2026/03/11 11:36:30 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	calculate_scale(t_data *data, char **map)
{
	int	len;
	int	i;
	int	j;
	int	scale;

	len = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > len)
			len = j;
		i++;
	}
	scale = data->win_width / len * 0.4;
	if (scale == 0)
		scale = 1;
	return (scale);
}


void	draw_mini_map(t_data *data, char **map)
{
	int		scl;
	t_axis	axis;

	scl = calculate_scale(data, map);
	axis.y = 0;
	while (map[axis.y])
	{
		axis.x = 0;
		while (map[axis.y][axis.x])
		{
			if (map[axis.y][axis.x] == '1' || map[axis.y][axis.x] == 'F')
				my_mlx_put_square(&data->game_img, axis, scl, 0x00FF0000);
			if (map[axis.y][axis.x] == 'N')
				my_mlx_put_triangle_no(&data->game_img, axis, scl, 0x00FFFF00);
			else if (map[axis.y][axis.x] == 'S')
				my_mlx_put_triangle_so(&data->game_img, axis, scl, 0x00FFFF00);
			else if (map[axis.y][axis.x] == 'W')
				my_mlx_put_triangle_we(&data->game_img, axis, scl, 0x00FFFF00);
			else if (map[axis.y][axis.x] == 'E')
				my_mlx_put_triangle_ea(&data->game_img, axis, scl, 0x00FFFF00);
			axis.x++;
		}
		axis.y++;
	}
}
