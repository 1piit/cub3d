/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 12:18:32 by pbride            #+#    #+#             */
/*   Updated: 2025/05/05 13:53:51 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	cc;
	size_t	i;

	cc = (char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == cc)
			return ((char *)(str + i));
		i++;
	}
	if (str[i] == cc)
		return ((char *)(str + i));
	return (NULL);
}
