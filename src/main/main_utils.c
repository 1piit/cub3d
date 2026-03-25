/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 16:04:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/25 18:46:51 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_args(int ac)
{
	if (ac != 2)
		exit(0);
}

void	init_data(t_data *data, int ac, char **av)
{
	init_parsing(data, ac, av);
	int i = 0;
	while (data->cubfile.texture_file[i])
	{
		printf("texture %d = %s\n", i, data->cubfile.texture_file[i]);
		i++;
	}
	init_game(data);
}
