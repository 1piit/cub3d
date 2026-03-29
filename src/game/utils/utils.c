/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:43:40 by pbride            #+#    #+#             */
/*   Updated: 2026/03/29 16:06:05 by pbride           ###   ########.fr       */
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

t_img	*get_texture(t_data *data)
{
	if (data->game.box.side == 0 && data->game.player.ray_dir.x > 0)
		return (&data->game.textures[EAST]);
	if (data->game.box.side == 0 && data->game.player.ray_dir.x < 0)
		return (&data->game.textures[WEST]);
	if (data->game.box.side == 1 && data->game.player.ray_dir.y > 0)
		return (&data->game.textures[SOUTH]);
	return (&data->game.textures[NORTH]);
}
