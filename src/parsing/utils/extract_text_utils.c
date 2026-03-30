/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_text_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 10:24:05 by pbride            #+#    #+#             */
/*   Updated: 2026/03/27 10:25:06 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	blank_skipper(char **str, int i)
{
	if (!str || !*str || !str[i])
		return (i);
	while (*str[i] && (*str[i] == ' ' || (*str[i] <= 13 && *str[i] >= 9)))
	{
		(*str)++;
		i++;
	}
	return (i);
}

int	ft_isspace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	wt_line_getter(char **wt_line, int *index, char *wf, const char *dir)
{
	wf = ft_strnstr(wf, dir, ft_strlen(wf));
	if (wf == NULL)
		return (0);
	if (!ft_strncmp(wf, dir, 2))
	{
		wt_line[*index] = gc_strdup(wf, GEN);
		(*index)++;
		return (1);
	}
	return (0);
}

int	textures_getter(char **texture_file, int *index, char *wf, char *dir)
{
	int	i;
	int	last;

	if (!wf)
		return (0);
	i = 0;
	wf = ft_strnstr(wf, dir, ft_strlen(wf));
	if (!wf)
		return (0);
	while (ft_isalnum(wf[i]))
		i++;
	while (ft_isspace(wf[i]))
		i++;
	texture_file[*index] = gc_strdup(&wf[i], GEN);
	i = 0;
	while (texture_file[i])
	{
		last = ft_strlen(texture_file[i]);
		if (texture_file[i][last - 1] == '\n')
			texture_file[i][last - 1] = '\0';
		i++;
	}
	(*index)++;
	return (1);
}
