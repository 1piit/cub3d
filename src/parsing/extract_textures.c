/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:26:08 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/27 11:01:07 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	bf_wt_line(char **wt_line, char *wf)
{
	static int	index = 0;

	if (wt_line_getter(wt_line, &index, wf, "NO"))
		return ;
	else if (wt_line_getter(wt_line, &index, wf, "SO"))
		return ;
	else if (wt_line_getter(wt_line, &index, wf, "EA"))
		return ;
	else if (wt_line_getter(wt_line, &index, wf, "WE"))
		return ;
	return ;
}

static void	bf_textures_getter(char **texture_file, char *wf)
{
	static int	index = 0;

	if (textures_getter(texture_file, &index, wf, "NO"))
		return ;
	else if (textures_getter(texture_file, &index, wf, "SO"))
		return ;
	else if (textures_getter(texture_file, &index, wf, "EA"))
		return ;
	else if (textures_getter(texture_file, &index, wf, "WE"))
		return ;
	return ;
}

void	textures_part(char **texture_file, char **wt_line, char **wf)
{
	int		i;
	int		j;
	char	*current_line;

	i = 0;
	while (wf[i])
	{
		j = 0;
		current_line = wf[i];
		bf_wt_line(wt_line, current_line);
		bf_textures_getter(texture_file, current_line);
		i++;
		while (texture_file[j] && wt_line[j])
		{
			if (texture_file[3] && wt_line[3])
				return ;
			j++;
		}
	}
	return ;
}
