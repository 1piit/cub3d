/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:32:33 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*new;

	new = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = (*f)(i, s[i]);
		i++;
	}
	new[i] = '\0';
	return (new);
}
/* char	to_upper_odd(unsigned int i, char c)
{
	if (i % 2 == 0)
		return (c);
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
#include <stdio.h>

int	main(void)
{
	char *original;
	char *modified;

	original = "bonjour le monde!";
	modified = ft_strmapi(original, to_upper_odd);

	printf("Modifié  : %s\n", modified);
	free(modified);
	return (0);
} */