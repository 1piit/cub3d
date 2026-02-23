/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:09:32 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_len_min(const char *dst, size_t siz)
{
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (dstlen > siz)
		return (siz);
	else
		return (dstlen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	len;
	size_t	lendst;

	len = ft_len_min(dst, siz);
	lendst = ft_strlen(dst);
	i = 0;
	while (src[i] != '\0' && i + lendst < siz - 1 && siz > 0)
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (ft_strlen(src) + len);
}

/* #include <stdio.h>
#include <bsd/string.h>

int	main(void)
{
	char dst1[50] = "12345";
	char src1[50] = "";

	char dst2[50] = "12345";
	char src2[50] = "";

	size_t size = 2;

	printf("ft_strlcat : %zu\n", ft_strlcat(dst1, src1, size));
	printf("%s\n", dst1);

	printf("   strlcat : %zu\n", strlcat(dst2, src2, size));
	printf("%s\n", dst2);
} */