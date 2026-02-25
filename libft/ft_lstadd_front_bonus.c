/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:57:07 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
/*
int	main(void)
{
	t_list	*start;
	t_list	*node1;
	t_list	*node2;
	t_list	*node3;
	t_list	*test;

	start = NULL;
	// t_list *start = ft_lstnew("start");
	node1 = ft_lstnew("node1");
	node2 = ft_lstnew("node2");
	node3 = ft_lstnew("node3");
	ft_lstadd_front(&start, node3);
	ft_lstadd_front(&start, node2);
	ft_lstadd_front(&start, node1);
	// printf("%s\n", (char *)liste->content);
	// printf("%s\n", (char *)node1->content);
	// printf("%s\n", (char *)node1->next->content);
	test = node1;
	while (test != NULL)
	{
		printf("%s\n", (char *)test->content);
		test = test->next;
	}
	// printf("%s\n", (char *)test->content);
}
*/