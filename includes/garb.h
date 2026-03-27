/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 19:03:09 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/27 11:16:25 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARB_H
# define GARB_H

# include <stddef.h>

typedef enum e_mem
{
	MALLOC,
	FREE,
	FULL_CLEAN,
}						t_mem;

typedef enum e_label
{
	GEN,
	ENV
}						t_label;

typedef struct s_garbage
{
	void				*ptr;
	t_label				label;
	struct s_garbage	*next;
}						t_garbage;

/* gc_features.c */
void		*gc_mem(t_mem type, size_t size, void *ptr, t_label label);
void		*gc_free(t_garbage **garb, void *ptr, t_label label);
void		*gc_malloc(t_garbage **garbage, size_t size, void *ptr, \
t_label label);
t_garbage	**get_garbage(void);

/*gc_utils.c */
void		remove_gc_node(t_garbage **garb, t_garbage *cur, t_garbage *prev, \
t_garbage *tmp);
void		cleanup_all(void);

#endif
