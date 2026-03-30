/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:42:04 by pbride            #+#    #+#             */
/*   Updated: 2026/03/26 14:26:12 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	game_loop(t_data *data)
{
	if (data->game.keys[XK_Escape])
		close_handler(data);
	update_player_pos(data);
	update_player_dir(data);
	render_frame(data);
	return (0);
}
