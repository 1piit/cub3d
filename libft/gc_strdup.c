/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 14:52:13 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/23 15:09:32 by ptricaud         ###   ########.fr       */
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