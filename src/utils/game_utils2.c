/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 15:19:00 by pbride            #+#    #+#             */
/*   Updated: 2026/03/24 17:59:12 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	calculate_scale(t_data *data, char **map)
{
	int	len;
	int	i;
	int	j;
	int	scale;

	len = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > len)
			len = j;
		i++;
	}
	scale = data->game.win_width / len * 0.4;
	if (scale == 0)
		scale = 1;
	return (scale);
}
