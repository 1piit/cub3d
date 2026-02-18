/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:10:19 by pbride            #+#    #+#             */
/*   Updated: 2025/10/10 19:25:28 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		return (free(str), NULL);
	new_line = ft_strchr(str, '\n');
	if (!new_line)
		return (free(str), NULL);
	new_stash = ft_strdup(new_line + 1);
	free(str);
	return (new_stash);
}

char	*ft_read_line(char *str, int fd)
{
	char		*buffer;
	int			bytes_read;

	buffer = (char *) malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (free(str), NULL);
	bytes_read = 1;
	while (!ft_has_newline(str) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(str), free(buffer), str = NULL, NULL);
		else if (bytes_read == 0 && (!str || str[0] == 0))
			return (free(str), free(buffer), str = NULL, NULL);
		buffer[bytes_read] = '\0';
		str = ft_strjoin_free(str, buffer);
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd == -1 && stash)
	{
		free(stash);
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
