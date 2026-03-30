/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:23:08 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/27 11:08:19 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_nb_of_player(int *flag, int player)
{
	if (player)
	{
		if (player > 1)
		{
			*flag = 1;
			return (1);
		}
		return (1);
	}
	return (0);
}

void	check_player(int *flag, t_file cubfile)
{
	int	i;
	int	player;
	int	j;

	player = 0;
	i = 0;
	while (cubfile.map && cubfile.map[i])
	{
		j = 0;
		while (cubfile.map[i][j])
		{
			if (cubfile.map[i][j] == 'W' || cubfile.map[i][j] == 'E'
				|| cubfile.map[i][j] == 'S' || cubfile.map[i][j] == 'N')
				player++;
			j++;
		}
		i++;
	}
	if (check_nb_of_player(flag, player))
		return ;
	*flag = 1;
}
