/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:04:53 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = new;
	else
		*lst = new;
}

/* int main()
{
	t_list *node1;
	t_list *node2;
	t_list *node3;

	node1 = ft_lstnew("bonjour\n");
	node2 = ft_lstnew("la forme?\n");
	node3 = ft_lstnew("go brr brr\n");

	ft_lstadd_front(&node2, node1);
	printf("%s", (char *)ft_lstlast(node1)->content);
	ft_lstadd_back(&node1, node3);
	printf("%s", (char *)ft_lstlast(node1)->content);


	return (0);
} */