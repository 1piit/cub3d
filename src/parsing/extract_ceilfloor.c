/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_ceilfloor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:26:15 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/02 16:05:16 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *look_char(char **wf, char letter)
{
    int i;
    int j;

    i = 0;
    while(wf[i])
    {
        j = 0;
        if(wf[i][j] == '\n' || !wf[i][j])
        {
            i++;
            continue;
        }
        while(!ft_isalpha(wf[i][j]))
            j++;
        if(wf[i][j] != letter)
            i++;
        else
            return(wf[i]);
    }
    return NULL;  
}

/* Format au sens litteral (Test des valeurs plus tard). 
Le schema teste est juste : nombre, virgule, nombre, virgule, nombre. 
Plus ez a coder, donc on la joue rigide et on juge pas ok la presence de blanks post-line F et C */
int format_RGBtest(char *str)
{
    int i;
    i = 2;
    if((str[1]) != ' ')
    {
        while(str[i] != ',' && str[i])
        {
            if(ft_isdigit(str[i]))
                i++;
            else
                return 0;
        }
    }
    return 1;
}
/* Ici one ne fait que mettre des valeurs dans le tableau [3] des valeurs rgb_f et rgb_c (Pas de tests en +) */
void get_values(unsigned int *rgb, char *str)
{
    int i;
    char *ret;
    int j;
    int index;

    index = 0;
    ret = gc_mem(MALLOC, 10, NULL, GEN);
    i = 0;
    while(str[i] && index < 3)
    {
        j = 0;
        ft_memset(ret, 0, 10);
        while(!ft_isdigit(str[i]))
            i++;
        while(ft_isdigit(str[i]))
        {
            ret[j] = str[i];
            j++;
            i++;
        }
        ret[j] = '\0';
        rgb[index++] = (unsigned int) ft_atoi(ret);
    }
    /* while(str[i] && index < 3)
    {
        j = 0;
        ft_memset(ret, 0, 10);
        while(str[i] != ',' && str[i] != '\n' && str[i] && ft_isdigit(str[i]))
        {
            ret[j] = str[i];
            i++;
            j++;
        }
        ret[j] = '\0';
        rgb[index] = (unsigned int) ft_atoi(ret);
        index++;
        if(str[i] == ',')
            i++;
    } */
}
char **ceilfloor_part(t_file *cubfile, char **wf)
{
    char *floor;
    char *ceilling;
    cubfile->RGB_f = gc_mem(MALLOC, (sizeof(unsigned int) * 3), NULL, GEN);
    cubfile->RGB_c = gc_mem(MALLOC, (sizeof(unsigned int) * 3), NULL, GEN);
    ceilling = NULL;
    floor = NULL;
    cubfile->ceilfloor = gc_mem(MALLOC, sizeof(char *) * 3, NULL, GEN);
    floor = look_char(wf, 'F');
    ceilling = look_char(wf, 'C');
    if(!floor || !ceilling)
        return NULL;
    get_values(cubfile->RGB_f, floor);
    get_values(cubfile->RGB_c, ceilling);
    cubfile->ceilfloor[0] = floor;
    cubfile->ceilfloor[1] = ceilling;
    cubfile->ceilfloor[2] = NULL;
    return cubfile->ceilfloor;
}
