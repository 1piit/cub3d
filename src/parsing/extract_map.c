/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:24:58 by ptricaud          #+#    #+#             */
/*   Updated: 2026/04/01 13:21:49 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static char	**parse_map_line(char **map, char **wf, t_map_part *map_part, int i)
{
	if (wf[i][0] == '1' || wf[i][0] == '0' || (wf[i][0] == ' '
		|| (wf[i][0] > 10 && wf[i][0] <= 13)))
	{
		if (line_tester((wf[i])))
			map_part->nb_lines++;
		else
		{
			if (!map_part->nb_lines)
				map_part->start++;
		}
	}
	else if (wf[i][0] == '\n' && map_part->nb_lines)
		return (check_eof(&map_part->nb_lines, map_part->start, map, wf));
	else
		map_part->start++;
	return (NULL);
}

char	**map_part(char **map, char **wf)
{
	int			i;
	t_map_part	map_part;
	char		**parsed_map;

	i = 0;
	map_part.start = 0;
	map_part.nb_lines = 0;
	while (wf && wf[i])
	{
		parsed_map = parse_map_line(map, wf, &map_part, i);
		if (parsed_map)
			return (parsed_map);
		i++;
	}
	return (map_fill(&map_part.nb_lines, map_part.start, map, wf));
}
