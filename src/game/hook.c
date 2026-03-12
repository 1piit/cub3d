/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:06:17 by pbride            #+#    #+#             */
/*   Updated: 2026/03/12 12:53:06 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	close_handler(t_data *data)
{
	cleanup_all_exit(data, NULL, SUCCESS);
	return (0);
}

int	key_handler(int keysymb, t_data *data)
{
	if (keysymb == XK_w)
		printf("print W - North\n");
	if (keysymb == XK_s)
		printf("print S - South\n");
	if (keysymb == XK_a)
		printf("print A - East\n");
	if (keysymb == XK_d)
		printf("print D - West\n");
	else if (keysymb == XK_Escape)
		close_handler(data);
	return (0);
}
