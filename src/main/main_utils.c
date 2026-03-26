/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:04:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/25 18:41:07 by ptricaud         ###   ########.fr       */
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
	t_time *time;

	time = get_time_ms();
	gettimeofday(&time->s_time, NULL);
	gettimeofday(&time->c_time, NULL);
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
t_time *get_time_ms(void)
{
	static t_time time;

	return (&time);
}