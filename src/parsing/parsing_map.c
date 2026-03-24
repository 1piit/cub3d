/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 20:23:08 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/09 17:35:37 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void check_dimensions(int *flag, t_file cubfile)
{
    int i;
    int j;
    
    i = 0;
    while(cubfile.map && cubfile.map[i])
    {
        j = 0;
        while(cubfile.map[i][j])
        {
            if(cubfile.map[i][j] == '0' || cubfile.map[i][j] == 'W' || cubfile.map[i][j] == 'E' || cubfile.map[i][j] == 'S' || cubfile.map[i][j] == 'N')
                return;          
            j++;
        }
        i++;
    }
    *flag = 1;    
}
void check_player(int *flag, t_file cubfile)
{
    int i;
    int player;
    int j;

    player = 0;
    i = 0;
    while(cubfile.map && cubfile.map[i])
    {
        j = 0;
        while(cubfile.map[i][j])
        {
            if(cubfile.map[i][j] == 'W' || cubfile.map[i][j] == 'E' || cubfile.map[i][j] == 'S' || cubfile.map[i][j] == 'N')
                 player++;
            j++;  
        }
        i++;
    }
    if(player)
    {
        if(player > 1)
        {
            *flag = 1;
            return;
        }
        return;
    }
    *flag = 1;
}

