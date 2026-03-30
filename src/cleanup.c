/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:42:03 by pierreb           #+#    #+#             */
/*   Updated: 2026/03/26 19:35:30 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	cleanup_all_data(t_data *data)
{
	int i = 0;
	if (data->quit_threads == 0) // Prevents running if not even initialised maybe, actually quit_threads is better just as a trigger. But wait, what if init_threads hasn't run? Let's check threads[0]
	{
		data->quit_threads = 1;
		if (data->threads[0]) // Quick check if threads were created
		{
			pthread_barrier_wait(&data->barrier_start);
			while (i < NUM_THREADS)
			{
				pthread_join(data->threads[i], NULL);
				i++;
			}
			pthread_barrier_destroy(&data->barrier_start);
			pthread_barrier_destroy(&data->barrier_end);
		}
	}
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
