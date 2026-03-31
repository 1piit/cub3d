/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:37:25 by pbride            #+#    #+#             */
/*   Updated: 2026/03/27 10:38:18 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	left_side(char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j] == 'F')
			j++;
		if (temp[i][j] == '0' || temp[i][j] == 'S' || temp[i][j] == 'N'
			|| temp[i][j] == 'E' || temp[i][j] == 'W')
			return (0);
		i++;
	}
	return (1);
}

int	right_side(char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (temp[i])
	{
		j = ft_strlen(temp[i]) - 1;
		while (j != 0 && (temp[i][j] == 'F'))
			j--;
		if (temp[i][j] == '0' || temp[i][j] == 'S' || temp[i][j] == 'N'
			|| temp[i][j] == 'E' || temp[i][j] == 'W')
			return (0);
		i++;
	}
	return (1);
}

int	top_side(char **temp)
{
	int	j;

	j = 0;
	while (temp && temp[0] && temp[0][j])
	{
		if (temp[0][j] == '0' || temp[0][j] == 'S' || temp[0][j] == 'N'
			|| temp[0][j] == 'E' || temp[0][j] == 'W')
			return (0);
		j++;
	}
	return (1);
}

int	bottom_side(char **temp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (temp[i])
		i++;
	if (i)
		i--;
	while (temp
		&& temp[i]
		&& temp[i][j]
		&& j < (int)ft_strlen(temp[i]))
	{
		if (temp[i][j] == '0' || temp[i][j] == 'S' || temp[i][j] == 'N'
			|| temp[i][j] == 'E' || temp[i][j] == 'W')
			return (0);
		j++;
	}
	return (1);
}

int	edges_first(char **temp)
{
	if (!left_side(temp) || !right_side(temp) || !top_side(temp)
		|| !bottom_side(temp))
		return (0);
	return (1);
}
