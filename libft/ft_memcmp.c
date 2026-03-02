/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:03:50 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && ((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
		i++;
	if (i < n)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
/* 
#include <stdio.h>

int main()
{
    int arr1[] = {1,2,3,4,5};
    int arrcmp1[] = {1,2,3,8,5};
    
    int arr2[] = {1,2,3,4,5};
    int arrcmp2[] = {1,2,3,8,5};

    unsigned char str1[] = "yassas";
    unsigned char strcmp1[] = "yazssas";
    
    unsigned char str2[] = "yassas";
    unsigned char strcmp2[] = "yass\ts";

    char test1 = '\200';
    unsigned char test2 = '\200';
    printf("%d | %d\n", test1, test2);

int resarr1 = ft_memcmp(arr1, arrcmp1, sizeof(int)*5);
int resarr2 = memcmp(arr1, arrcmp1, sizeof(int)*5);



int resstr1 = ft_memcmp(str1, strcmp1, 6);
int resstr2 = memcmp(str1, strcmp1, 6);    

printf("ft_memcmp : %d \n", resstr1);

printf("memcmp : %d \n", resstr2);

printf("COMPARE : %d %d\n" );
} */
