/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 02:22:16 by pbride            #+#    #+#             */
/*   Updated: 2026/04/01 12:23:25 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	ft_dda(t_data *data, t_thread_data *th_data, t_axf ray_dir, t_box *box)
{
	t_axi	step;
	int		hit;

	box->map_x = th_data->th_player.pos_x;
	box->map_y = th_data->th_player.pos_y;
	init_ray_delta_axis(box, ray_dir);
	init_ray_step_side_axis(th_data, ray_dir, &step, box);
	hit = 0;
	dda_loop(data, &step, hit, box);
	if (box->side == 0)
		box->perp_wd = (box->side_x - box->dltx);
	else
		box->perp_wd = (box->side_y - box->dlty);
	box->hit_x = th_data->th_player.pos_x + ray_dir.x * box->perp_wd;
	box->hit_y = th_data->th_player.pos_y + ray_dir.y * box->perp_wd;
}

void	ft_dda_minimap(t_data *data, t_axf ray_dir, t_box *box)
{
	t_axi	step;
	int		hit;

	box->map_x = data->game.player.pos_x;
	box->map_y = data->game.player.pos_y;
	init_ray_delta_axis(box, ray_dir);
	init_ray_step_side_axis_mini(data, ray_dir, &step, box);
	hit = 0;
	dda_loop(data, &step, hit, box);
	if (box->side == 0)
		box->perp_wd = (box->side_x - box->dltx);
	else
		box->perp_wd = (box->side_y - box->dlty);
	box->hit_x = data->game.player.pos_x + ray_dir.x * box->perp_wd;
	box->hit_y = data->game.player.pos_y + ray_dir.y * box->perp_wd;
}
