/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 11:12:20 by pbride            #+#    #+#             */
/*   Updated: 2026/03/27 11:14:05 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void	remove_gc_node(t_garbage **garb, t_garbage *cur, t_garbage *prev, \
t_garbage *tmp)
{
	if (cur->ptr)
		free(cur->ptr);
	if (prev)
		prev->next = tmp;
	else
		*garb = tmp;
	free(cur);
}

void	cleanup_all(void)
{
	gc_mem(FULL_CLEAN, 0, NULL, GEN);
	gc_mem(FULL_CLEAN, 0, NULL, ENV);
}
