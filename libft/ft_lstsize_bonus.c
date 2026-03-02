/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 14:33:41 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	size_t	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

/* int main()
{
	t_list *node1;
	t_list *node2;

	node1 = ft_lstnew("bonjour");
	node2 = ft_lstnew("la forme?");

	ft_lstadd_front(&node2, node1);
	printf("%d\n", ft_lstsize(node1));
	printf("%s %s\n", (char *)node1->content, (char *)node1->next->content);

	return (0);
} */