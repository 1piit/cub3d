/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:10:19 by pbride            #+#    #+#             */
/*   Updated: 2026/02/23 15:06:18 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_has_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_extract_line(char *str)
{
	char	*line;
	char	*new_line;
	size_t	len;

	if (!str)
		return (NULL);
	new_line = ft_strchr(str, '\n');
	if (new_line)
		len = new_line - str + 1;
	else
		len = ft_strlen(str);
	line = ft_substr_light(str, len);
	return (line);
}

char	*ft_update_stash(char *str)
{
	char	*new_line;
	char	*new_stash;

	if (!str)
		return ((gc_mem(FREE, 0, str, GEN)), NULL);
	new_line = ft_strchr(str, '\n');
	if (!new_line)
		return ((gc_mem(FREE, 0, str, GEN)), NULL);
	new_stash = gc_strdup(new_line + 1, GEN);
	(gc_mem(FREE, 0, str, GEN));
	/* free(str) */;
	return (new_stash);
}

char	*ft_read_line(char *str, int fd)
{
	char		*buffer;
	int			bytes_read;
	
	buffer = gc_mem(MALLOC, (BUFFER_SIZE + 1), NULL, GEN);
	// buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return ((gc_mem(FREE, 0, str, GEN)), NULL);
	bytes_read = 1;
	while (!ft_has_newline(str) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return ((gc_mem(FREE, 0, str, GEN)), (gc_mem(FREE, 0, buffer, GEN)),NULL);
		else if (bytes_read == 0 && (!str || str[0] == 0))
			return ((gc_mem(FREE, 0, str, GEN)), (gc_mem(FREE, 0, buffer, GEN)),NULL);
		buffer[bytes_read] = '\0';
		str = ft_strjoin_free(str, buffer);
	}
	gc_mem(FREE, 0, buffer, GEN);
/* 	free(buffer);
 */	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd == -1 && stash)
	{
		gc_mem(FREE, 0, stash, GEN);
		/* free(stash); */
		stash = NULL;
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_read_line(stash, fd);
	line = ft_extract_line(stash);
	stash = ft_update_stash(stash);
	return (line);
}
