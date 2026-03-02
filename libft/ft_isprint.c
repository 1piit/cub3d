/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:20:07 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && 126 >= c)
		return (1);
	else
		return (0);
}

/* #include <stdio.h>

int	main(void)
{
	char *str;
	int i;

	i = 0;
	str = "lgobigt42";

	while (str[i])
	{
		printf("%d", ft_isprint(str[i]));
		i++;
	}
	return (0);
} */