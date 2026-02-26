/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:26:08 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/26 18:40:32 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int blank_skipper(char **str, int i)
{
    if(!str || !*str || !str[i])
        return i;
    while(*str[i] && (*str[i] == ' ' || (*str[i] <= 13 && *str[i] >= 9)))
    {
        (*str)++;
        i++;
    }
    return i;
}

int wt_line_getter(char **wt_line, int *index, char *wf, const char *orientation)
{
    if(wf[0] == ' ' ||(wf[0] >= 9 && wf[0] <= 13))
        blank_skipper(&wf, 0);
    wf = ft_strnstr(wf, orientation, ft_strlen(wf));
    if(wf == NULL)
        return 0;      
    if(!ft_strncmp(wf, orientation, 2))
    {
        wt_line[*index] = gc_strdup(wf, GEN);
        (*index)++;
        return 1;
    }
    return 0;
}
int ft_isspace(int c)
{
    if(c == ' ' || (c >= 9 && c <= 13))
        return 1;
    return 0;
}
int textures_getter(char **texture_file, int *index, char *wf, char *orientation)
{
    int i;
    if (!wf)
        return 0;
    i = 0;
    wf = ft_strnstr(wf, orientation, ft_strlen(wf));
    if(!wf)
        return (0);
    while(ft_isalnum(wf[i]))
        i++;
    while(ft_isspace(wf[i]))
        i++;
    texture_file[*index] = gc_strdup(&wf[i], GEN);
    (*index)++;
    return 1;
}
void bf_wt_line(char **wt_line, char *wf)
{
    static int index = 0;
    if(wt_line_getter(wt_line, &index, wf, "NO"))
        return;
    else if(wt_line_getter(wt_line, &index, wf, "SO"))
        return;
    else if(wt_line_getter(wt_line, &index, wf, "EA"))
        return;
    else if(wt_line_getter(wt_line, &index, wf, "WE"))
        return;
}

void bf_textures_getter(char **texture_file, char *wf)
{
    static int index = 0;
    if(textures_getter(texture_file, &index, wf, "NO"))
        return;
    if(textures_getter(texture_file, &index, wf, "SO"))
        return;
    if(textures_getter(texture_file, &index, wf, "EA"))
        return;
    if(textures_getter(texture_file, &index, wf, "WE"))
        return;
}

void textures_part(char **texture_file, char **wt_line, char **wf)
{
    int i;
    int j;
    int k = 0;
    char *test;     

    test = "NOSOWEEA";
    i = 0;
    while(wf[i])
    {
        j = 0;
        if(wf[i][0] == ' ' || (wf[i][0] <= 13 && wf[i][0] >= 9))
            i = blank_skipper(&wf[i], i);
        bf_wt_line(wt_line, wf[i]);
        bf_textures_getter(texture_file, wf[i]);
        k++;
        i++;
        while(texture_file[j] && wt_line[j])
        {
            if(texture_file[3] && wt_line[3])
                return;
            j++;   
        }
    }
    return;
}
    
