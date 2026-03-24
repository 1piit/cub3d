/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 18:34:24 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/09 17:36:36 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int *find_longest(int *lengths, int *longest)
{
    int i;


    *longest = 0;
    i = 0;
    while(lengths[i] != -1)
    {
        if(lengths[i] > *longest)
            *longest = lengths[i];
        i++;
    }
    return longest;
}
int *find_lengths(char **map)
{
    int i;
    int *lengths;

    i = 0;
    while(map && map[i])
        i++;
    lengths = gc_mem(MALLOC, (sizeof(int) * (i + 1)), NULL, GEN);
    i = 0;
    while(map && map[i])
    {
        lengths[i] = ft_strlen(map[i]);
        i++;
    }
    lengths[i] = -1;
    return lengths;
}
/* void fill_mid_void(char **temp, int map_len, int longest)
{
    int i;
    int j;
    
    i = 0;
    while(i < map_len)
    {
        j = 0;
        while(temp[i][j] == 'X' || temp[i][j] == 'F')
            j++;
        printf("we are on this char -->%c | we are on this line -->%d <=>%s\n", temp[i][j], i, temp[i]);
        while((temp[i][j] == 'S' || temp[i][j] == 'N' || temp[i][j] == 'W' || temp[i][j] == 'E' || temp[i][j] == '1' || temp[i][j] == '0') && j < longest)
        {
            j++;
        }
        while(ft_isspace(temp[i][j]))
        {
            temp[i][j] = 'X';
            j++;
        }
        i++;
    }
} */
/* void fill_left_void(char **temp, int map_len)
{
    int i;
    int j;
    
    i = 0;
    while(i < map_len)
    {
        j = 0;
        while(temp[i][j] != '1' && temp[i][j] != '0')
        {
            temp[i][j] = 'X';
            j++;
        }
        i++;        
    }
} */
/* void fill_right_void(char **temp, int*lengths, int map_len)
{
    int i;
    int j;
    int longest;


    longest = find_longest(lengths);
    
    i = 0;
    while(i < map_len)
    {
        j = 0;

        while(j < longest && temp[i][j] && temp[i][j] != 'F')
            j++;

        while(j < longest && temp[i][j])
        {
            temp[i][j] = 'X';
            j++;
        }
        i++;
    }
} */
static char *ft_strcpy_tmap(char *map, char *temp)
{
    int i;
    i = 0;

    while(map && map[i] != '\0')
    {
        if (ft_isspace(map[i]))
            temp[i] = 'F';
        else
            temp[i] = map[i];
        i++;
    }
    return temp;
}
char **fill_temp_map(char **map, char **temp, int longest)
{
    int i;
    
    i = 0;
    while(map && map[i])
    {
        temp[i] = gc_mem(MALLOC, (sizeof(char) * longest) + 1, NULL, GEN);
        ft_memset(temp[i], 'F', longest);
        temp[i] = ft_strcpy_tmap(map[i], temp[i]);
        temp[i][longest] = '\0';
        i++;
    }
/*     i = 0;
    while(i < map_len)
        printf("%s\n", temp[i++]); */
    /*     i = 0;
    fill_left_void(temp, map_len);
    i = 0;
    printf("\n--------------------------------\n");
    printf("At this stage, temp_map has only been been filled on its left side: \n\n");
    while(i < map_len)
        printf("%s\n", temp[i++]);
    i = 0;
    fill_mid_void(temp, map_len, longest);
    printf("\n--------------------------------\n");
    printf("At this stage, temp_map has (eventually) been filled in the middle : \n\n");
    while(i < map_len)
        printf("%s\n", temp[i++]);
    fill_right_void(temp, lengths, map_len);
    i = 0;
    printf("\n--------------------------------\n");
    printf("At this stage, temp_map has been filled on both sides : \n\n");
    while(i < map_len)
        printf("%s\n", temp[i++]); */
    return temp;
}
char **temp_map( char **map, int *longest)
{
    int *lengths;
    char **temp;
    int map_len;

    map_len = 0;
    while(map && map[map_len])
        map_len++;
    lengths = find_lengths(map);
    longest = find_longest(lengths, longest);
    temp = gc_mem(MALLOC, (sizeof(char*) * (map_len + 1)), NULL, GEN);
    temp[map_len] = NULL;
    temp = fill_temp_map(map, temp, *longest);
    return temp;
}