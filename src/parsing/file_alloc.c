/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:21:31 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/26 18:42:12 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	count_fd_lines(int fd)
{
	char	*line;
	int		nb;

	nb = 0;
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		nb++;
	}
	return (nb);
}
char	**alloc_file_size(char **file_tab, int fd, int fd2)
{
	int	lines;
	int	i;

	i = 0;
	lines = count_fd_lines(fd);
	close(fd);
	file_tab = gc_mem(MALLOC, (sizeof(char *) * (lines + 1)), NULL, GEN);
	if (!file_tab)
		return (NULL);
	while (i < lines)
	{
		file_tab[i] = get_next_line(fd2);
		i++;
	}
	file_tab[i] = NULL;
	close(fd2);
	return (file_tab);
}

t_file	split_file(t_file cubfile, char **file_tab)
{
	cubfile.map = map_part(cubfile.map, file_tab);
	cubfile.ceilfloor = ceilfloor_part(&cubfile, file_tab);
	cubfile.wt_line = gc_mem(MALLOC, (sizeof(char*) * 5), NULL, GEN);
	cubfile.texture_file = gc_mem(MALLOC, sizeof(char*) * 5, NULL, GEN);
	textures_part(cubfile.texture_file, cubfile.wt_line, file_tab);
	return (cubfile);
}