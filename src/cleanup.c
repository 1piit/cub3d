/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:42:03 by pierreb           #+#    #+#             */
/*   Updated: 2026/03/11 11:34:56 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

void    cleanup_all(t_data *data)
{
    gc_mem(FULL_CLEAN, 0, NULL, GEN);
    if (data->game_img.mlx_img)
    {
        mlx_destroy_img(data->mlx, data->game_img.mlx_img);
        data->game_img.mlx_img = NULL;
    }
    if (data->mlx_win)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        data->mlx_win = NULL;     
    }
    if (data->mlx)
    {
        free(data->mlx);
        data->mlx = NULL;
    }
}

void    cleanup_all_exit(t_data *data, char *err_msg, int code)
{
    if (err_msg)
        perror(err_msg);
    cleanup_all(data);
    exit(code);
}
