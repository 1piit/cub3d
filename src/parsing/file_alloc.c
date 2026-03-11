/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:21:31 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/03 18:07:03 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int blank_line(char *str)
{
	int i;
	i = 0;
	while(str[i])
	{
		if(!(str[i] == ' ' || ((str[i] >= 9) && (str[i] <= 13))))
			return 0;
		i++;
	}
	return 1;
}
int	count_fd_lines(int fd, t_file *cubfile)
{
	char	*line;
	int		nb;
	int minus;

	nb = 0;
	line = get_next_line(fd);
	minus = 0;
	while (line)
	{
		line = get_next_line(fd);
		if(line && blank_line(line))
			minus++;
		nb++;
	}
	cubfile->used_lines = nb - minus;
	printf("Total of lines --> %d || used lines --> %d\n", nb, cubfile->used_lines);
	return (nb);
}
char	**alloc_file_size(t_file *cubfile, char **file_tab, int fd, int fd2)
{
	int	lines;
	int	i;

	i = 0;
	lines = count_fd_lines(fd, cubfile);
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