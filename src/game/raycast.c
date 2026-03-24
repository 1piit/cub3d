/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 16:19:26 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/24 15:17:09 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int get_real_rgb(int *side)
{
    char *temp;
    char *c_side[3];
    c_side[0] = ft_itoa(side[0]);
    c_side[1] = ft_itoa(side[1]);
    c_side[2] = ft_itoa(side[2]);
    temp = ft_strjoin(ft_strjoin(c_side[0], c_side[1]), c_side[2]);
    return (ft_atoi(temp));
}
void draw_ceilling(t_data *data, int ceilling)
{
    int i;
    int j;
    i = 0;
    while(i < data->game.win_height / 2)
    {
        j = 0;
        while(j  <  data->game.win_width)
        {
            my_mlx_put_pixel(&data->game.game_img, j, i, ceilling);
            j++;
        }
        i++;
    }
}
void draw_floor(t_data *data, int floor)
{
    int i;
    int j;
    i = data->game.win_height / 2;
    while(i < data->game.win_height)
    {
        j = 0;
        while(j  <  data->game.win_width)
        {
            my_mlx_put_pixel(&data->game.game_img, j, i, floor);
            j++;
        }
        i++;
    }
}
void draw_ceilfloor(t_data *data)
{
    int ceilling;
    int floor;

    ceilling = get_real_rgb(data->cubfile.RGB_c);
    floor = get_real_rgb(data->cubfile.RGB_f);
    draw_ceilling(data, ceilling);
    draw_floor(data, floor);
}

void draw_vlines(t_data *data, int i, int drawS, int drawE, int color)
{

    if (data->game.box.side == 1) 
    {
        color = color / 2;
    }
    while(drawS != drawE)
    {
        my_mlx_put_pixel(&data->game.game_img, i, drawS, color);
        drawS++;   
    }
}
void raycast_game(t_data *data)
{
    int lineHeight;
    int drawStart;
    int drawEnd;
    int ratio;
    int color = 0x0CE9389;
    int i;
    i = 0;
    ratio = data->game.win_height / 2;
    lineHeight = (int)(ratio/data->game.box.perp_wd);
    drawStart = -lineHeight / 2 + ratio / 2;
    drawEnd = lineHeight / 2 + ratio / 2;
    if(drawEnd >= ratio)
        drawEnd = ratio - 1;
    if(drawStart < 0)
        drawStart = 0;
    while(i < data->game.win_width)
    {
        draw_vlines(data, i, drawStart, drawEnd, color);
        i++;
    }
}
