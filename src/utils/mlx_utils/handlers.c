/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_escape.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:43:03 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/11 17:03:45 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_do_key_autorepeaton(data->mlx);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	exit(0);
	return (0);
}
int handle_key(int keysym, t_data *data)
{
    if(keysym == XK_Escape)
    {
		handle_close(data);
	}
	// which_key(keysym, data);
	return 0;
}

/* int	handle_release(int keysym, t_data *data)
{
	if (keysym == XK_d)
		data->dx -= 1;
	if (keysym == XK_r)
		data->dx -= 1;
	if (keysym == XK_a)
		data->dx += 1;
	if (keysym == XK_s)
		data->dy -= 1;
	if (keysym == XK_w)
		data->dy += 1;
	return (0);
} */
