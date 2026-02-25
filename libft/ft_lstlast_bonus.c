/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:03:21 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/20 15:40:17 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while ((lst != NULL) && (lst->next != NULL))
	{
		lst = lst->next;
	}
	return (lst);
}

/* int main()
{
	t_list *node1;
	t_list *node2;
	t_list *last;


	node1 = ft_lstnew("bonjour");
	node2 = ft_lstnew("la forme?");

	ft_lstadd_front(&node2, node1);
	last = ft_lstlast(node1);
	printf("%s", (char *)(last->content));

	return (0);
} */

/* int main()
{   
	t_list *elem ;
	t_list *elem2;
	t_list *elem3; 
	t_list *elem4; 
	t_list *val;
	size_t i ;
	
	
	
	elem->next = elem2;
    elem2->next = elem3;
    elem3->next = elem4;
    val = ft_lstlast(elem);
    i = 0;
    content = val->content;
    while (content[i])
        write(1, &(content[i++]), 1);
    write(1, "\n", 1);
    elem->next = NULL;
    val = ft_lstlast(elem);
    content = val->content;
    i = 0;
    while (content[i])
        write(1, &(content[i++]), 1);
    write(1, "\n", 1);
    elem = NULL;
    val = ft_lstlast(elem);
    if (val == NULL)
        write(1, "NULL", 4);
    write(1, "\n", 1);
} */