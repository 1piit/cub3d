/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 16:56:30 by pbride            #+#    #+#             */
/*   Updated: 2025/10/09 16:57:15 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	ft_sitoa(int n, char *n_dst)
{
	int			count;
	long int	nb;
	int			start;

	nb = n;
	count = count_size(nb);
	start = (nb < 0);
	if (nb < 0)
		count++;
	n_dst[count] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		n_dst[0] = '-';
	}
	while (--count >= start)
	{
		n_dst[count] = (nb % 10) + '0';
		nb /= 10;
	}
}
