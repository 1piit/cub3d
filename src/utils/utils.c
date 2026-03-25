/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:43:40 by pbride            #+#    #+#             */
/*   Updated: 2026/03/25 22:20:54 by pbride           ###   ########.fr       */
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

void	update_delta_time(t_data *data)
{
	struct timeval	now;
	long			elapsed_us;

	gettimeofday(&now, NULL);
	elapsed_us = (now.tv_sec - data->game.time_last.tv_sec) * 1000000 + (now.tv_usec - data->game.time_last.tv_usec);
	data->game.delta_time = elapsed_us / 1000000.0;  // en secondes
	data->game.time_last = now;
}
