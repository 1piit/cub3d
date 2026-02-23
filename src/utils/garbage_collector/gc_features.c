/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_features.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 15:42:22 by althorel          #+#    #+#             */
/*   Updated: 2026/02/23 13:59:10 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

t_garbage	**get_garbage(void)
{
	static t_garbage *garbage = NULL;

	return (&garbage);
}
void	cleanup_all(void)
{
	gc_mem(FULL_CLEAN, 0, NULL, GEN);
	gc_mem(FULL_CLEAN, 0, NULL, ENV);
}

void	*gc_free(t_garbage **garb, void *ptr, t_label label)
{
	t_garbage	*cur;
	t_garbage	*prev;

	cur = *garb;
	prev = NULL;
	while (cur)
	{
		if (cur->ptr == ptr && cur->label == label)
		{
			if (cur->ptr)
				free(cur->ptr);
			if (prev)
				prev->next = cur->next;
			else
				*garb = cur->next;
			free(cur);
			return (NULL);
		}
		prev = cur;
		cur = cur->next;
	}
	return (NULL);
}

/* static void	remove_gc_node(t_garbage **garb, t_garbage *cur, t_garbage *prev)
{
	if(garb && *garb)
	{
		if (cur->ptr)
			free(cur->ptr);
		if (prev)
			prev->next = cur->next;
		else
			*garb = cur->next;
	}
	free(cur);
} */
static void	remove_gc_node(t_garbage **garb, t_garbage *cur, t_garbage *prev, t_garbage *tmp)
{
    if(garb && *garb)
    {
        if (cur->ptr)
            free(cur->ptr);
        if (prev)
            prev->next = tmp;
        else
            *garb = tmp;
    }
    free(cur);
}

static void	*gc_full_clean(t_garbage **garb, t_label label)
{
	t_garbage	*cur;
	t_garbage	*tmp;
	t_garbage	*prev;

	cur = *garb;
	prev = NULL;
	while (cur)
	{
		tmp = cur->next;
		if (cur->label == label)
		{
			remove_gc_node(garb, cur, prev, tmp);
			cur = tmp;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return (NULL);
}

void	*gc_malloc(t_garbage **garbage, size_t size, void *ptr, t_label label)
{
	t_garbage	*new;

	new = ft_calloc(1, sizeof(t_garbage));
	if (!new)
		return (perror("malloc"), cleanup_all(),
			exit(EXIT_FAILURE), NULL);
	if (ptr)
		new->ptr = ptr;
	else
		new->ptr = ft_calloc(1, size);
	if (!new->ptr)
		return (perror("malloc"), cleanup_all(),
			exit(EXIT_FAILURE), NULL);
	new->label = label;
	if (*garbage)
	{
		new->next = *garbage;
		*garbage = new;
	}
	else if (*garbage == NULL)
	{
		new->next = NULL;
		*garbage = new;
	}
	return (new->ptr);
}

void	*gc_mem(t_mem type, size_t size, void *ptr, t_label label)
{
	t_garbage	**garb;

	
	garb = get_garbage();
	if (type == MALLOC)
		return (gc_malloc(garb, size, ptr, label));
	else if (type == FULL_CLEAN && garb)
	{
		return (gc_full_clean(garb, label));
	}
	else if (type == FREE && garb && *garb)
		return (gc_free(garb, ptr, label));
	return (NULL);
}
