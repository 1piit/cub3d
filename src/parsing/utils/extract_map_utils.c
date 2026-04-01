/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:49:52 by pbride            #+#    #+#             */
/*   Updated: 2026/04/01 13:13:46 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	only_space(char *line)
{
	int	i;

	i = 0;
	if (line[0] == '\n')
		return (1);
	while (line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if ((size_t) i != ft_strlen(line))
		return (0);
	return (1);
}

int	line_tester(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'N'
				|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W'
				|| line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
			return (0);
		i++;
	}
	if (only_space(line))
		return (0);
	return (1);
}

char	*null_terminate(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
	return (str);
}

char	**map_fill(int *nb_lines, int start, char **map, char **wf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < start)
		i++;
	map = gc_mem(MALLOC, (sizeof(char *) * (*nb_lines + 1)), NULL, GEN);
	while (i < (*nb_lines) + start)
	{
		map[j] = wf[i];
		printf("tested line is %s\n", map[j]);
		map[j] = null_terminate(map[j]);
		i++;
		j++;
	}
	map[j] = NULL;
	return (map);
}

char	**check_eof(int *nb_lines, int start_map, char **map, char **wf)
{
	int	i;
	int	j;

	i = start_map + *nb_lines;
	while (wf[i])
	{
		j = 0;
		while (wf[i][j])
		{
			if (wf[i][j] != '\n' && !ft_isspace(wf[i][j]) && wf[i][j] != '1'
				&& wf[i][j] != '0' && wf[i][j] != 'S' && wf[i][j] != 'N'
				&& wf[i][j] != 'W' && wf[i][j] != 'E')
				return (
					printf("On this line we found '%c', FAILURE\n", wf[i][j]),
					NULL);
			j++;
		}
		(*nb_lines)++;
		i++;
	}
	return (map_fill(nb_lines, start_map, map, wf));
}
