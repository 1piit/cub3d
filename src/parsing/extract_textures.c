/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:26:08 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/24 19:28:07 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void blank_skipper(char **str, int i)
{
    while(*str[i] && (*str[i] == ' ' || (*str[i] <= 13 && *str[i] >= 9)))
    {
        (*str)++;
        i++;
    }
    return;
}

void wt_line_getter(char **wt_line, char *wf)
{
    if(ft_strnstr(wf, "NO", 2))
        wt_line[0] = gc_strdup(wf, GEN);
    else if(ft_strnstr(wf, "SO", 2))
        wt_line[1] = gc_strdup(wf, GEN);
    else if(ft_strnstr(wf, "WE", 2))
        wt_line[2] = gc_strdup(wf, GEN);
    else if(ft_strnstr(wf, "EA", 2))
        wt_line[3] = gc_strdup(wf, GEN);
}
void textures_getter(char **texture_file, char *wf)
{
    if(ft_strnstr(wf, "./", 2) || ft_strnstr(wf, "/", 1))
        texture_file[0] = gc_strdup(++wf, GEN);
    else if(ft_strnstr(wf, "./", 2) || ft_strnstr(wf, "/", 1))
        texture_file[1] = gc_strdup(++wf, GEN);
    else if(ft_strnstr(wf, "./", 2) || ft_strnstr(wf, "/", 1))
        texture_file[2] = gc_strdup(++wf, GEN);
    else if(ft_strnstr(wf, "./", 2) || ft_strnstr(wf, "/", 1))
        texture_file[3] = gc_strdup(++wf, GEN);
}
char **textures_part(char **texture_file, char **wt_line, char **wf)
{
    int i;
    int j;
    int k;

    i = 0;
    wt_line = gc_mem(MALLOC, (sizeof(char*) * 5), NULL, GEN);
    texture_file = gc_mem(MALLOC, sizeof(char*) * 5, NULL, GEN);
    while(wf[i])
    {
        k = 0;
        j = 0;
        if(wf[i][0] == ' ' || (wf[i][0] <= 13 && wf[i][0] >= 9))
            blank_skipper(&wf[i], i);
        wt_line_getter(wt_line, wf[i]);
        textures_getter(texture_file, wf[i]);
        i++;
        while(texture_file[j])
        {
            if(j == 3)
                return texture_file;
            j++;   
        }
    }
    i = 0;
    if(!texture_file)
        printf("pas de pointeur sur txt_file\n\n");
    if(!wt_line)
        printf("Pas de pointeur wt_line\n\n");
    if(!texture_file[0])
        printf("Pas de txt_file rempli\n\n");
    if(!wt_line[0])
        printf("pas de wt_line rempli\n\n");
    printf("wt_file[0] is :%s\n\n", wt_line[0]);
    while(texture_file[i] && wt_line[i])
    {
        printf("whole line of %dth texture is :%s", i, wt_line[i]);
        printf("file part of this texture is :%s", texture_file[i]);
        i++;
    }
    return NULL;
}
