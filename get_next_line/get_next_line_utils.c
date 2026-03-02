/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:18:23 by pbride            #+#    #+#             */
/*   Updated: 2026/02/23 14:06:05 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_substr_light(char const *s, size_t len)
{
	char	*subs;
	size_t	i;

	if (!s)
		return (NULL);
	subs = gc_mem(MALLOC, ((len + 1) * sizeof(char)), NULL, GEN);
	// subs = (char *) malloc((len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	i = 0;
	while (i < len)
	{
		subs[i] = s[i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}

static char	*ft_strjoin(char *joins, const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	while (s1 != NULL && s1[i])
	{
		joins[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 != NULL && s2[j])
	{
		joins[i + j] = s2[j];
		j++;
	}
	joins[i + j] = '\0';
	return (joins);
}

char	*ft_strjoin_free(const char *s1, char const *s2)
{
	char	*joins;
	int		s1_size;

	if (!s2)
		return (NULL);
	if (s1)
		s1_size = ft_strlen(s1);
	else
		s1_size = 0;
	joins = gc_mem(MALLOC, (s1_size + ft_strlen(s2) + 1) * sizeof(char), NULL, GEN);
	//joins = (char *) malloc((s1_size + ft_strlen(s2) + 1) * sizeof(char));
	if (!joins)
		return (NULL);
	joins = ft_strjoin(joins, s1, s2);
	gc_mem(FREE, 0, (char *)s1, GEN);
	/* free((char *) s1); */
	return (joins);
}
