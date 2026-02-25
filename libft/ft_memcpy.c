/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:09:32 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[50] = "ABCDEFGHI";
	char	str2[50] = "ABCDEFGHI";
	char	src1[50] = "123456789";
	char	src2[50] = "123456789";
	char	*mdfStr1;
	char	*mdfStr2;

	mdfStr1 = ft_memcpy(((void*)0), ((void*)0), 3);
	mdfStr2 = memcpy(((void*)0), ((void*)0), 3);
	printf("str1 after ft_memcpy :%s\n", mdfStr1);
	printf("str2 after memcpy : %s", mdfStr2);
	return (0);
} */
