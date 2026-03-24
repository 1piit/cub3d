/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_ceilfloor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:26:15 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/05 18:55:39 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int check_ceilfloor_line(char *str)
{
    int i;
    int limit;

    limit  = 0;
    i = 0;
    
    while(str[i])
    {
        if(ft_isalpha(str[i]))
            limit++;
        if(limit > 1)
            return 1;
        i++;        
    }
    return 0;
}
char *look_char(char *wf, char letter)
{
    int i;


    i = 0;
    while(wf && wf[i])
    {
        if(wf[i] == '\n')
        {   
            i++;
            continue;
        }
        while(wf[i] && ft_isspace(wf[i]))
            i++;
        if(wf[i] != letter)
        {
                i++;
            break;}
        else
            { 
/*                 printf("THE FUNCTION HAS RETURNED %s\n\n", wf);
 */                return(wf);}
    }
    return NULL;  
}
void get_values(int *rgb, char *str)
{
    int i;
    char *ret;
    int j;
    int index;
/*     printf("ON EST DANS GET_VALUES\n\n\n");
 */    index = 0;
    ret = gc_mem(MALLOC, 5, NULL, GEN);
    i = 0;
    while(str[i] && index < 3)
    {
        j = 0;
        ft_memset(ret, -1, 5);
        while(!ft_isdigit(str[i]) && str[i] != '\n' && !(str[i] == '+' || str[i] == '-'))
            i++;
        while(ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
        {
            ret[j] = str[i];
            j++;
            i++;
        }
        ret[j] = '\0';
        rgb[index] = ft_atoi(ret);
/*         printf("found value of current rgb[%d] is %d\n", index, rgb[index]);
 */        index++;
    }
}
char *join_line(char *str, char letter)
{
    int i;
    int j;
    char *temp;
    
    i = 0;
    j = 0;
    if(*str == letter)
        str++;
    if(!ft_isspace(*str))
        return NULL;
    temp = gc_mem(MALLOC, (sizeof(char) * ft_strlen(str) + 1), NULL, GEN);
    while(str[i])
    {
        if(!ft_isspace(str[i]))
        {
            temp[j] = str[i];
            j++;
        }
        i++;
    }
    return temp;
}
int check_format(char *str, char letter)
{
    int i;
    char *temp;
    
    i = 0;
    temp = join_line(str, letter);
    if(!temp)
        return 0;
    if(temp[0] == ',')
        return 0;
    while(temp && temp[i++])
    {                    
        if(temp[i] == ',')
        {
            if(!ft_isdigit(temp[++i]))
                return 0;
        }
    }
    i = 0;
    while(temp[i])
    {
        if(!ft_isdigit(temp[i]) && temp[i] != ',')
            return 0;
        i++;
    }
    return 1;
}
int get_ceilfloor_lines(char **ceilling, char **floor, char **wf, t_file *cubfile)
{
    unsigned int i;

    i = 0;
    while(*floor == NULL)
    {
        *floor = look_char(wf[i], 'F');
        if(*floor && !check_format(*floor, 'F'))
            *floor = NULL;
        if(cubfile->used_lines == (i))
            break;
        i++;
    }
    i = 0;
    while(!*ceilling)
    {
        *ceilling = look_char(wf[i], 'C');
        if(*ceilling && !check_format(*ceilling, 'C'))
            *ceilling = NULL;
        if(cubfile->used_lines == i)
            break;
        i++;
    }
    if(!*floor || !*ceilling)
        return 0;
    return 1;
}
char **ceilfloor_part(t_file *cubfile, char **wf)
{
    char *floor;
    char *ceilling;
    // int i;

    // i = 0;
    cubfile->RGB_f = gc_mem(MALLOC, (sizeof(int) * 3), NULL, GEN);
    cubfile->RGB_c = gc_mem(MALLOC, (sizeof(int) * 3), NULL, GEN);
    ceilling = NULL;
    floor = NULL;
    cubfile->ceilfloor = gc_mem(MALLOC, sizeof(char *) * 3, NULL, GEN);
    if(!get_ceilfloor_lines(&ceilling, &floor, wf, cubfile))
        return (/* printf("ON VA PAS DANS GET_VALUES\n\n"), */ NULL);
            get_values(cubfile->RGB_f, floor);
    get_values(cubfile->RGB_c, ceilling);
    cubfile->ceilfloor[0] = gc_strdup(floor, GEN);
    cubfile->ceilfloor[1] = gc_strdup(ceilling, GEN);
    cubfile->ceilfloor[2] = NULL;
    return cubfile->ceilfloor;
}
