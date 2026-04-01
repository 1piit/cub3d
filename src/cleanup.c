/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:42:03 by pierreb           #+#    #+#             */
/*   Updated: 2026/04/01 12:28:18 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	cleanup_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->game.txt[i].mlx_img != NULL)
		{
			mlx_destroy_image(data->game.mlx, data->game.txt[i].mlx_img);
			data->game.txt[i].mlx_img = NULL;
		}
		i++;
	}
}

static void	cleanup_threads(t_data *data)
{
	int	i;

	i = 0;
	if (data->quit_threads == 0)
	{
		data->quit_threads = 1;
		if (data->threads[0])
		{
			pthread_barrier_wait(&data->barrier_start);
			while (i < NUM_THREADS)
			{
				pthread_join(data->threads[i], NULL);
				i++;
			}
			pthread_barrier_destroy(&data->barrier_start);
		}
	}
}

void	cleanup_fps(t_data *data)
{
	if (data->game.fps != NULL)
	{
		free(data->game.fps);
		data->game.fps = NULL;
	}
}

void	cleanup_all_data(t_data *data)
{
	cleanup_threads(data);
	gc_mem(FULL_CLEAN, 0, NULL, GEN);
	cleanup_textures(data);
	if (data->game.game_img.mlx_img != NULL)
	{
		mlx_destroy_image(data->game.mlx, data->game.game_img.mlx_img);
		data->game.game_img.mlx_img = NULL;
	}
	if (data->game.mlx_win != NULL)
	{
		mlx_destroy_window(data->game.mlx, data->game.mlx_win);
		data->game.mlx_win = NULL;
	}
	if (data->game.mlx != NULL)
	{
		mlx_destroy_display(data->game.mlx);
		free(data->game.mlx);
		data->game.mlx = NULL;
	}
}

void	cleanup_all_exit(t_data *data, char *err_msg, int code)
{
	if (err_msg != NULL)
		perror(err_msg);
	cleanup_all_data(data);
	exit(code);
}
