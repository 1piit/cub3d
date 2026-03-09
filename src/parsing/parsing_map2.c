/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:57:02 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/09 19:17:47 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int left_side(char **temp)
{
    int i;
    int j;
    i = 0;
    
    while(temp[i])
    {
        j = 0;
        while(temp[i][j] == 'F')
            j++;
        if(temp[i][j] == '0' || temp[i][j] == 'S' || temp[i][j] == 'N' 
            || temp[i][j] == 'E' || temp[i][j] == 'W')
            return 0;
        i++; 
    }
    return 1;
}
int right_side(char **temp)
{
    int i;
    int j;
    
    i = 0;
    while(temp[i])
    {
        j = ft_strlen(temp[i]) - 1;
        while( j!= 0 && (temp[i][j] == 'F'))
            j--;
        if(temp[i][j] == '0' || temp[i][j] == 'S' || temp[i][j] == 'N' 
            || temp[i][j] == 'E' || temp[i][j] == 'W')
            return 0;
        i++;
    }
    return 1;
}
int top_side(char **temp)
{
    int j;
    
    j = 0;
    while(temp && temp[0] && temp[0][j])
    {
        if(temp[0][j] == '0' || temp[0][j] == 'S' || temp[0][j] == 'N' 
            || temp[0][j] == 'E' || temp[0][j] == 'W')
            return 0;
        j++;
    }
        
    return 1;
}
int bottom_side(char **temp)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while(temp[i])
        i++;
    if(i)    
        i--;
    while(temp 
        && temp[i] 
        && temp[i][j] 
        && j < (int)ft_strlen(temp[i]))
    {
        if(temp[i][j] == '0' || temp[i][j] == 'S' || temp[i][j] == 'N' 
            || temp[i][j] == 'E' || temp[i][j] == 'W')
            return 0;
        j++;
    }
    return 1;
}
int edges_first(char **temp)
{
    if(!left_side(temp) || !right_side(temp) || !top_side(temp) || !bottom_side(temp))
        return 0;
    return 1;
}
int check_neighboxes(int i, int j, char **temp)
{
    if(temp[i][j+1] != 'F' && temp[i][j-1] != 'F' && temp[i+1][j] != 'F' && temp[i-1][j] != 'F')
        return 0;
    return 1;
}
void check_enclosed(char **temp, int *flag)
{
    int i;
    int j;
    int limit;
    
    i = 1;
    while(temp && temp[0] && temp[i])
    {
        j = 1;
        limit = ft_strlen(temp[i]) - 1;
        while(temp[i][j])
        {
            if(temp[i][j] == '0' && j != limit)
            {
                if(check_neighboxes(i, j, temp))
                {
                    *flag = 1;
                    return;
                }
            }
            j++;
        }
        if(!temp[i+2])
            break;
        i++;
    }
}
void enclosed_map(int *flag, char **map)
{
    char **temp;
    int i;
    int longest;
    
    i = 0;
    temp = temp_map(map, &longest);
    if(!edges_first(temp))
    {
        *flag = 1;
        return;
    }
    while(temp[i])
    {
        printf("%s\n", temp[i]);
        i++;
    }
    check_enclosed(temp, flag);
}