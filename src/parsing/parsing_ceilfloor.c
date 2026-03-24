/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ceilfloor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:32:24 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/06 17:09:21 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../includes/cub3d.h"

void invalid_rgb_case_one(int *flag, int RGB_c[3], int RGB_f[3])
{
    int i;
    
    i = 0;
    if(!RGB_c || !RGB_f)
    {
        *flag = 1;
        return;   
    }
    while(i < 3)
    {   
       if(RGB_c[i] < 0 || RGB_f[i] < 0)
        {
            *flag = 1;
            return;
        }
        i++;
    }
}
int count_values(char *str)
{
    int i;
    int nb;
    // int commas;
    
    // commas = 0;
    nb = 0;
    i = 0;
    while(str && str[i] && str[i] != '\n')
    {
        while(!ft_isdigit(str[i]))
        {
            if(str[i] == '\0' || str[i] == '\n')
                break;
            i++;
        }
        if(ft_isdigit(str[i]))
            nb++;
        while(ft_isdigit(str[i]))
            i++;
    }
    return nb;
    
}
int check_sign(char *ceilfloor)
{
    int i;
    int limit;
    
    i = 0;
    while(ceilfloor && ceilfloor[i])
    {
        limit = 0;
        while(ceilfloor[i] == '-' || ceilfloor[i] == '+')
        {
            i++;
            limit++;
        }
        if(limit > 1)
            return 0;
        i++;
    }
    return 1;
}
void invalid_rgb_case_two(int *flag, char **ceilfloor)
{
    int i;

    i = 0;
    if(ceilfloor && (count_values(ceilfloor[0]) != 3 || count_values(ceilfloor[1]) != 3))
    {
        *flag = 1;
        return;
    }
    while(ceilfloor && ceilfloor[i])
    {
        if(!check_sign(ceilfloor[i]))
        {
            *flag = 1;
            return;
        }
        i++;
    }
}
