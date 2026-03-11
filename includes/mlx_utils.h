/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:08:51 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/11 17:03:19 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int handle_key(int keysym, t_data *data);
int	handle_close(t_data *data);
int	handle_release(int keysym, t_data *data);