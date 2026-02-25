/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_ceilfloor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:26:15 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/24 19:10:23 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char *look_char(char **wf, char letter)
{
    int i;

    i = 0;
    while(wf[i])
    {
        if(wf[i][0] != letter)
            i++;
        else
            return(wf[i]);
    }
    return NULL;  
}

// Format au sens litteral (Test des valeurs plus tard). 
// Le schema teste est juste : nombre, virgule, nombre, virgule, nombre. 
// Plus ez a coder, donc on la joue rigide et on juge pas ok la presence de blanks post-line F et C
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
//Ici one ne fait que mettre des valeurs dans le tableau [3] des valeurs rgb_f et rgb_c (Pas de tests en +)
void get_values(unsigned int *rgb, char *str)
{
    int i;
    char *ret;
    int j;
    int index;
    
    index = 0;
    ret = gc_mem(MALLOC, 4, NULL, GEN);
    i = 0;
    while(!ft_isdigit(str[i]))
        i++;
    while(str[i])
    {
        j = 0;
        while(str[i] != ',' && str[i] != '\n' && str[i])
        {
            ret[j] = str[i];
            i++;
            j++;
        }
        ret[j] = '\0';
        rgb[index] = (unsigned int) ft_atoi(ret);
        index++;
        i++;
    }
}
char **ceilfloor_part(t_file *cubfile, char **wf)
{
    char *floor;
    char *ceilling;
    cubfile->RGB_f = gc_mem(MALLOC, (sizeof(int) * 3) , NULL, GEN);
    cubfile->RGB_c = gc_mem(MALLOC, (sizeof(int) * 3), NULL, GEN);
    ceilling = NULL;
    floor = NULL;
    cubfile->ceilfloor = gc_mem(MALLOC, sizeof(char *) * 3, NULL, GEN);
    floor = look_char(wf, 'F');
    ceilling = look_char(wf, 'C');
    get_values(cubfile->RGB_f, floor);
    get_values(cubfile->RGB_c, ceilling);
    cubfile->ceilfloor[0] = floor;
    cubfile->ceilfloor[1] = ceilling;
    cubfile->ceilfloor[2] = NULL;
    return cubfile->ceilfloor;
}
