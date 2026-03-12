/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:04:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/12 14:37:49 by pbride           ###   ########.fr       */
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

void	init_data(t_data *data, int ac, char **av)
{
	init_parsing(data, ac, av);
	init_game(data);
}
