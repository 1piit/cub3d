/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:24:58 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/23 18:50:35 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int only_space(char *line)
{
	int i = 0;
	if(line[0] == '\n')
		return 1;
	while(line[i] && (line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
		i++;
	if((size_t) i != ft_strlen(line))
		return 0;
	return 1;
}
static int line_tester(char *line/*, int j , int *error */)
{
    int i = 0;
	while(line[i])
	{
        if(!(line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
            {
				//(*error) = 1;
				return 0;}
		i++;
	}
	if(only_space(line)){
		//printf("line %d -->%s has only blanks\n", j, line);
		//(*error) = 2;
		return 0;}
	return 1;
}
/* char **map_fill(int nb_lines, int start, char **map, int fd)
{
	int i = 0;
	char *line;
	while(i < start)
	{
		line = get_next_line(fd);
		i++;
	}
    map = gc_mem(MALLOC, (sizeof(char *) * (nb_lines + 1)), NULL, GEN);
	i = 0;
	while(i < nb_lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
    map[i] = NULL;
	close(fd);
	return map;
} */
char **map_fill(int nb_lines, int start, char **map, char **wf)
{
	int i = 0;
	int j = 0;
	//char *line;
	while(i < start)
		i++;
    map = gc_mem(MALLOC, (sizeof(char *) * (nb_lines + 1)), NULL, GEN);
	while(i < nb_lines + start)
	{
		map[j] = wf[i];
		i++;
		j++;
	}
    map[j] = NULL;
	return map;
}
char **map_part(char **map, char **wf/* , int fd */)
{
    int i = 0;
    int fst = 0;
    int start_map = 0;
    int nb_lines = 0;
	//int error = 0;
	char c;
    while(wf[i] && wf)
    {
		c = wf[i][fst];
		if(wf[i][fst] == '1' || wf[i][fst] == '0' || wf[i][fst] == 'N' || (wf[i][fst] == ' ' 
            || (wf[i][fst] > 10  && wf[i][fst] <= 13)) || (!(wf[i][fst] == '\n')))
            if(line_tester((wf[i])/*, i , &error */))
            {
				//printf("The %dth line is accepted : %s\n", i, wf[i]);
                nb_lines++;
            }
            else
            {    
				//printf("line %d hasnt been accepted because of error type --> %d\n\n", i, error);
				if(!nb_lines)
                    start_map++;
			}
        else
        {
			//printf("line %d didnt pass the first test\n\n", i);
			start_map++;
		}
        i++;
    }
	//printf("nb_lines --> %d | start --> %d\n", nb_lines, start_map);
    map = map_fill(nb_lines, start_map, map, wf);
	// map = map_fill(nb_lines, start_map, map, fd);
	return map;
}
