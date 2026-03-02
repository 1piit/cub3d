/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:28:02 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t siz)
{
	size_t	i;

	i = 0;
	while (src[i] && i + 1 < siz)
	{
		dst[i] = src[i];
		i++;
	}
	if (siz > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

/* #include <stdio.h>

int	main(void)
{
	char str[50] = "";
	ft_strlcpy(((void *)0), ((void *)0), 10);
	printf("%s", str);
} */