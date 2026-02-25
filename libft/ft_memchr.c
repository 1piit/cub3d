/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:43:16 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/* #include <stdio.h>
#include<string.h>

int main()
{
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	
	char str[] = "bonjour";

	int *resarr = ft_memchr(arr, 8, sizeof(int)*9);
	char *resstr = ft_memchr(str, 'j', 6);

	int *resarr2 = memchr(arr, 8, sizeof(int)*9);
	char *resstr2 = memchr(str, 'j', 6);

	printf("%d, %s\n", *resarr, resstr);
	printf("%d, %s\n", *resarr2, resstr2);
	return 0;
} */
