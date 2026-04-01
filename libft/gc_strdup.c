/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:52:13 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/27 11:27:13 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*gc_strdup(const char *s, t_label label)
{
	char	*str;
	size_t	len;

	len = ft_strlen(s);
	str = gc_mem(MALLOC, sizeof(*str) * (len + 1), NULL, label);
	if (!str)
		return (NULL);
	if (str)
	{
		ft_strlcpy(str, s, len + 1);
		return (str);
	}
	else
		return (0);
}
