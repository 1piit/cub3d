/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:43:40 by pbride            #+#    #+#             */
/*   Updated: 2026/03/31 15:34:09 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	get_screen_size(int *width, int *height)
{
	Display	*dpy;
	int		screen;

	dpy = XOpenDisplay(NULL);
	if (!dpy)
	{
		perror("Error: cannot open X display\n");
		*width = 1920;
		*height = 1080;
		return ;
	}
	screen = DefaultScreen(dpy);
	*width = DisplayWidth(dpy, screen);
	*height = DisplayHeight(dpy, screen);
	XCloseDisplay(dpy);
}

int	get_real_rgb(int *rgb_components)
{
	return ((rgb_components[0] << 16)
		| (rgb_components[1] << 8)
		| rgb_components[2]);
}

t_img	*get_texture(t_data *data, int side, t_axf ray_dir)
{
	if (side == 0 && ray_dir.x > 0)
		return (&data->game.textures[EAST]);
	if (side == 0 && ray_dir.x < 0)
		return (&data->game.textures[WEST]);
	if (side == 1 && ray_dir.y > 0)
		return (&data->game.textures[SOUTH]);
	return (&data->game.textures[NORTH]);
}
