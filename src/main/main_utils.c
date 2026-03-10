/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:04:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/09 16:10:55 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_args(int ac)
{
	if (ac != 2)
		exit(0);
}

void	init_structs(t_file *cubfile, char *file_arg)
{
	cubfile->save_file = file_arg;
	cubfile->ceilfloor = NULL;
	cubfile->map = NULL;
	// cubfile->texture_file = NULL;
}

void	init_data(t_data *data)
{
	*data = (t_data){0};
	get_screen_size(&data->win_width, &data->win_height);
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, data->win_width,
			data->win_height - 70, "cub3D - P2P");
}
