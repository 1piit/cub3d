/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 17:12:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/31 16:28:05 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static void	init_window(t_data *data)
{
	get_screen_size(&data->game.win_width, &data->game.win_height);
	data->game.mlx_win = mlx_new_window(data->game.mlx, data->game.win_width,
			data->game.win_height - 70, "cub3D - P2P");
	if (!data->game.mlx_win)
		cleanup_all_exit(data, "mlx new window", 1);
}

static void	init_game_img(t_data *data)
{
	data->game.game_img = (t_img){0};
	/* data->game.ew_wall = 0x0CE9389;
	data->game.sn_wall = 0x0CD6E5B; */
	data->game.game_img.win_width = data->game.win_width;
	data->game.game_img.win_height = data->game.win_height;
	data->game.game_img.mlx_img = mlx_new_image(data->game.mlx,
			data->game.win_width, data->game.win_height);
	if (!data->game.game_img.mlx_img)
		cleanup_all_exit(data, "mlx new image", 1);
	data->game.game_img.addr = mlx_get_data_addr(data->game.game_img.mlx_img,
			&data->game.game_img.bits_per_pixel, &data->game.game_img.line_len,
			&data->game.game_img.endian);
	if (!data->game.game_img.addr)
		cleanup_all_exit(data, "mlx get data addr", 1);
}

static void	init_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->game.textures[i] = (t_img){0};
		data->game.textures[i].mlx_img = mlx_xpm_file_to_image(data->game.mlx,
				data->cubfile.texture_file[i],
				&data->game.textures[i].img_width,
				&data->game.textures[i].img_height);
		if (!data->game.textures[i].mlx_img)
			cleanup_all_exit(data, "mlx xpm file to image", 1);
		data->game.textures[i].addr = mlx_get_data_addr(
				data->game.textures[i].mlx_img,
				&data->game.textures[i].bits_per_pixel,
				&data->game.textures[i].line_len,
				&data->game.textures[i].endian);
		if (!data->game.textures[i].addr)
			cleanup_all_exit(data, "mlx get data addr", 1);
		i++;
	}
}

static void	init_hooks(t_data *data)
{
	mlx_hook(data->game.mlx_win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->game.mlx_win, KeyRelease, KeyReleaseMask, key_release, data);
	mlx_hook(data->game.mlx_win, DestroyNotify, 0, close_handler, data);
	mlx_loop_hook(data->game.mlx, game_loop, data);
}

void init_threads(t_data *data)
{
	int i;
	int width_per_thread;
	
	// Init synchronisation
	pthread_barrier_init(&data->barrier_start, NULL, NUM_THREADS + 1);
	data->quit_threads = 0;

    width_per_thread = data->game.win_width / NUM_THREADS;
    i = 0;
	
    while (i < NUM_THREADS)
    {
        data->thread_data[i].data = data;
        data->thread_data[i].start_x = i * width_per_thread;
        if (i == NUM_THREADS - 1)
            data->thread_data[i].end_x = data->game.win_width;
        else
            data->thread_data[i].end_x = (i + 1) * width_per_thread;

        pthread_create(&data->threads[i], NULL, raycast_game, &data->thread_data[i]);
        i++;
    }
}

void	init_game(t_data *data)
{
	data->game = (t_game){0};
	data->game.mlx = mlx_init();
	if (!data->game.mlx)
		cleanup_all_exit(data, "mlx init", 1);
	gettimeofday(&data->game.time_last, NULL);
	init_window(data);
	init_map_len(data);
	data->game.mini_map_scl = calculate_scale(data);
	init_game_img(data);
	init_textures(data);
	init_player(data);
	init_threads(data);
	init_hooks(data);
}
