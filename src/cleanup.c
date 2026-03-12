/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:42:03 by pierreb           #+#    #+#             */
/*   Updated: 2026/03/12 14:40:06 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	cleanup_all_data(t_data *data)
{
	gc_mem(FULL_CLEAN, 0, NULL, GEN);
	if (data->game.game_img.mlx_img)
	{
		mlx_destroy_image(data->game.mlx, data->game.game_img.mlx_img);
		data->game.game_img.mlx_img = NULL;
	}
	if (data->game.mlx_win)
	{
		mlx_destroy_window(data->game.mlx, data->game.mlx_win);
		data->game.mlx_win = NULL;
	}
	if (data->game.mlx)
	{
		mlx_destroy_display(data->game.mlx);
		free(data->game.mlx);
		data->game.mlx = NULL;
	}
}

void	cleanup_all_exit(t_data *data, char *err_msg, int code)
{
	if (err_msg)
		perror(err_msg);
	cleanup_all_data(data);
	exit(code);
}
