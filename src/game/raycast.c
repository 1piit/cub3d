/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:19:26 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/26 17:36:32 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	raycast_mini_map(t_data *data, int nb)
{
	int		i;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;

	i = 0;
	while (i < nb)
	{
		camera_x = 2 * i / (double)(nb - 1) - 1;
		ray_dir_x = data->game.player.dir_x + \
data->game.player.plane.plane_x * camera_x;
		ray_dir_y = data->game.player.dir_y + \
data->game.player.plane.plane_y * camera_x;
		ft_dda(data, ray_dir_x, ray_dir_y);
		ft_bresenham(data,
			(int)(data->game.player.pos_x * data->game.mini_map_scl),
			(int)(data->game.player.pos_y * data->game.mini_map_scl),
			(int)(data->game.box.hit_x * data->game.mini_map_scl),
			(int)(data->game.box.hit_y * data->game.mini_map_scl));
		i++;
	}
}

void	raycast_3d_scene(t_data *data)
{
	t_ray	ray;
	int		i;

	i = 0;
	while (i < data->game.win_width)
	{
		data->game.player.camera_x = 2.0 * i / \
(double)data->game.win_width - 1.0;
		data->game.player.ray_dir_x = data->game.player.dir_x + \
data->game.player.plane.plane_x * data->game.player.camera_x;
		data->game.player.ray_dir_y = data->game.player.dir_y + \
data->game.player.plane.plane_y * data->game.player.camera_x;
		ft_dda(data, data->game.player.ray_dir_x, data->game.player.ray_dir_y);
		ray.line_height = (int)(data->game.win_height / data->game.box.perp_wd);
		ray.draw_start = -ray.line_height / 2 + data->game.win_height / 2;
		ray.draw_end = ray.line_height / 2 + data->game.win_height / 2;
		if (ray.draw_end >= data->game.win_height)
			ray.draw_end = data->game.win_height - 1;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		draw_wall(data, ray, i);
		i++;
	}
}
