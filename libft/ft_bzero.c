/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:09:32 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}

/* #include <stdio.h>
#include <strings.h>

int	main(void)
{
	int arr[3] = {15,1,2};
	char str[] = "Bonjour la forme ?";
	
	int arr2[3] = {15,1,2};
	char str2[] = "Bonjour la forme ?";
	
	ft_bzero(str, 5);
	ft_bzero(arr, sizeof(int)*2);
	
	bzero(str2, 2);
	bzero(arr2, sizeof(int)*2);

	printf("%s\n", str);
	printf("%d,%d,%d", arr[0],arr[1],arr[2]);

	printf("%s\n", str2);
	printf("%d,%d,%d", arr2[0],arr2[1],arr2[2]);


	return (0);
} */