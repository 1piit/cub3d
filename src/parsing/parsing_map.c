/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:57:02 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/27 10:40:21 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_dimensions(int *flag, t_file cubfile)
{
	int	i;
	int	j;

	i = 0;
	while (cubfile.map && cubfile.map[i])
	{
		j = 0;
		while (cubfile.map[i][j])
		{
			if (cubfile.map[i][j] == '0' || cubfile.map[i][j] == 'W'
				|| cubfile.map[i][j] == 'E' || cubfile.map[i][j] == 'S'
				|| cubfile.map[i][j] == 'N')
				return ;
			j++;
		}
		i++;
	}
	*flag = 1;
}

static int	check_neighboxes(int i, int j, char **temp)
{
	if (temp[i][j + 1] != 'F' && temp[i][j - 1] != 'F'
		&& temp[i + 1][j] != 'F' && temp[i - 1][j] != 'F')
		return (0);
	return (1);
}

static void	check_enclosed(char **temp, int *flag)
{
	int	i;
	int	j;
	int	limit;

	i = 1;
	while (temp && temp[0] && temp[i])
	{
		j = 1;
		limit = ft_strlen(temp[i]) - 1;
		while (temp[i][j])
		{
			if (temp[i][j] == '0' && j != limit)
			{
				if (check_neighboxes(i, j, temp))
				{
					*flag = 1;
					return ;
				}
			}
			j++;
		}
		if (!temp[i + 2])
			break ;
		i++;
	}
}

void	enclosed_map(int *flag, char **map)
{
	char	**temp;
	int		i;
	int		longest;

	i = 0;
	temp = temp_map(map, &longest);
	if (!edges_first(temp))
	{
		*flag = 1;
		return ;
	}
	while (temp[i])
	{
		printf("%s\n", temp[i]);
		i++;
	}
	check_enclosed(temp, flag);
}
