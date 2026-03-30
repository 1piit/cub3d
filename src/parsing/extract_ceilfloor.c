/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_ceilfloor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:26:15 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/27 09:49:03 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_ceilfloor_lines(char **ceilling, char **floor, char **wf, \
t_file *cubfile)
{
	unsigned int	i;

	i = 0;
	while (*floor == NULL)
	{
		*floor = look_char(wf[i], 'F');
		if (*floor && !check_format(*floor, 'F'))
			*floor = NULL;
		if (cubfile->used_lines == (i))
			break ;
		i++;
	}
	i = 0;
	while (!*ceilling)
	{
		*ceilling = look_char(wf[i], 'C');
		if (*ceilling && !check_format(*ceilling, 'C'))
			*ceilling = NULL;
		if (cubfile->used_lines == i)
			break ;
		i++;
	}
	if (!*floor || !*ceilling)
		return (0);
	return (1);
}

char	**ceilfloor_part(t_file *cubfile, char **wf)
{
	char	*floor;
	char	*ceilling;

	cubfile->rgb_f = gc_mem(MALLOC, (sizeof(int) * 3), NULL, GEN);
	cubfile->rgb_c = gc_mem(MALLOC, (sizeof(int) * 3), NULL, GEN);
	ceilling = NULL;
	floor = NULL;
	cubfile->ceilfloor = gc_mem(MALLOC, sizeof(char *) * 3, NULL, GEN);
	if (!get_ceilfloor_lines(&ceilling, &floor, wf, cubfile))
		return (NULL);
	get_values(cubfile->rgb_f, floor);
	get_values(cubfile->rgb_c, ceilling);
	cubfile->ceilfloor[0] = gc_strdup(floor, GEN);
	cubfile->ceilfloor[1] = gc_strdup(ceilling, GEN);
	cubfile->ceilfloor[2] = NULL;
	return (cubfile->ceilfloor);
}
