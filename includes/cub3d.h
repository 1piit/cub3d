/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 11:30:14 by pbride            #+#    #+#             */
/*   Updated: 2026/03/29 16:17:50 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define BUFFER_SIZE 42
# define SUCCESS 0
# define ERROR 1
# include <stdbool.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <mlx.h>
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/time.h>

# include "get_next_line.h"
# include "libft.h"
# include "garb.h"
# include "parsing.h"
# include "game.h"

# define M_PI	3.14159265358979323846

typedef struct s_data
{
	t_game	game;
	t_file	cubfile;
}	t_data;

//main_utils.c
void	check_args(int ac);
void	init_data(t_data *data, int ac, char **av);

//cleanup.c
void	cleanup_fps(t_data *data);
void	cleanup_all_data(t_data *data);
void	cleanup_all_exit(t_data *data, char *msg, int err_code);

#endif
