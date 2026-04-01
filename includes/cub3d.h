/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:30:14 by pbride            #+#    #+#             */
/*   Updated: 2026/04/01 11:13:53 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 42
# define SUCCESS 0
# define ERROR 1
# define M_PI 3.14159265358979323846
# define NUM_THREADS 100

# include "game.h"
# include "garb.h"
# include "get_next_line.h"
# include "libft.h"
# include "parsing.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_thread_data
{
	int					start_x;
	int					end_x;
	t_data				*data;
	t_plane				th_plane;
	t_player			th_player;
	t_ray				ray;
}						t_thread_data;

struct					s_data
{
	t_game				game;
	t_file				cubfile;
	pthread_barrier_t	barrier_start;
	pthread_barrier_t	barrier_end;
	int					quit_threads;
	pthread_t			threads[NUM_THREADS];
	t_thread_data		thread_data[NUM_THREADS];
};

typedef struct s_time
{
	struct timeval		s_time;
	struct timeval		c_time;
}						t_time;
// main_utils.c
void					check_args(int ac);
void					init_data(t_data *data, int ac, char **av);
t_time					*get_time_ms(void);

// cleanup.c
void					cleanup_fps(t_data *data);
void					cleanup_all_data(t_data *data);
void					cleanup_all_exit(t_data *data, char *msg, int err_code);

#endif
