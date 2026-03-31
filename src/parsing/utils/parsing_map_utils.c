/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:34:24 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/27 10:55:09 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

static int	*find_longest(int *lengths, int *longest)
{
	int	i;

	*longest = 0;
	i = 0;
	while (lengths[i] != -1)
	{
		if (lengths[i] > *longest)
			*longest = lengths[i];
		i++;
	}
	return (longest);
}

static int	*find_lengths(char **map)
{
	int	i;
	int	*lengths;

	i = 0;
	while (map && map[i])
		i++;
	lengths = gc_mem(MALLOC, (sizeof(int) * (i + 1)), NULL, GEN);
	i = 0;
	while (map && map[i])
	{
		lengths[i] = ft_strlen(map[i]);
		i++;
	}
	lengths[i] = -1;
	return (lengths);
}

static char	*ft_strcpy_tmap(char *map, char *temp)
{
	int	i;

	i = 0;
	while (map && map[i] != '\0')
	{
		if (ft_isspace(map[i]))
			temp[i] = 'F';
		else
			temp[i] = map[i];
		i++;
	}
	return (temp);
}

static char	**fill_temp_map(char **map, char **temp, int longest)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		temp[i] = gc_mem(MALLOC, (sizeof(char) * longest) + 1, NULL, GEN);
		ft_memset(temp[i], 'F', longest);
		temp[i] = ft_strcpy_tmap(map[i], temp[i]);
		temp[i][longest] = '\0';
		i++;
	}
	return (temp);
}

char	**temp_map( char **map, int *longest)
{
	int		*lengths;
	char	**temp;
	int		map_len;

	map_len = 0;
	while (map && map[map_len])
		map_len++;
	lengths = find_lengths(map);
	longest = find_longest(lengths, longest);
	temp = gc_mem(MALLOC, (sizeof(char *) * (map_len + 1)), NULL, GEN);
	temp[map_len] = NULL;
	temp = fill_temp_map(map, temp, *longest);
	return (temp);
}
