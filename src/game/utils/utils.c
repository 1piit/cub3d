/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:43:40 by pbride            #+#    #+#             */
/*   Updated: 2026/04/01 13:30:33 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	get_real_rgb(int *rgb_components)
{
	return ((rgb_components[0] << 16)
		| (rgb_components[1] << 8)
		| rgb_components[2]);
}

t_img	*get_texture(t_data *data, int side, t_axf ray_dir)
{
	if (side == 0 && ray_dir.x > 0)
		return (&data->game.txt[EAST]);
	if (side == 0 && ray_dir.x < 0)
		return (&data->game.txt[WEST]);
	if (side == 1 && ray_dir.y > 0)
		return (&data->game.txt[SOUTH]);
	return (&data->game.txt[NORTH]);
}
