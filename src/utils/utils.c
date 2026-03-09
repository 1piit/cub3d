/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:43:40 by pbride            #+#    #+#             */
/*   Updated: 2026/03/09 15:59:35 by pbride           ###   ########.fr       */
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
