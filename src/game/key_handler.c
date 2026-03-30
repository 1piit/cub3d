/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:06:17 by pbride            #+#    #+#             */
/*   Updated: 2026/03/27 11:09:57 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	close_handler(t_data *data)
{
	cleanup_all_exit(data, NULL, SUCCESS);
	return (0);
}

int	key_press(int keysymb, t_data *data)
{
	data->game.keys[keysymb] = 1;
	return (0);
}

int	key_release(int keysymb, t_data *data)
{
	data->game.keys[keysymb] = 0;
	return (0);
}
