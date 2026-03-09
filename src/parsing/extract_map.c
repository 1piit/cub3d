/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 15:24:58 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/09 19:01:58 by ptricaud         ###   ########.fr       */
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
        if(!(line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S' || 
             line[i] == 'E' || line[i] == 'W' || line[i] == ' ' || 
             (line[i] >= 9 && line[i] <= 13)))
            {
				/* (*error) = 1; */
				return 0;}
		i++;
	}
	if(only_space(line)){
		/* printf("line %d -->%s has only blanks\n", j, line);
		(*error) = 2; */
		return 0;}
	return 1;
}
char *null_terminate(char *str)
{
	int i;

	i = 0;
	while(str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
	return str;
}
char **map_fill(int *nb_lines, int start, char **map, char **wf)
{
	int i = 0;
	int j = 0;
/* 	char *line;
 */	while(i < start)
		i++;
    map = gc_mem(MALLOC, (sizeof(char *) * (*nb_lines + 1)), NULL, GEN);
	while(i < (*nb_lines) + start)
	{
		map[j] = wf[i];
		map[j] = null_terminate(map[j]);
		i++;
		j++;
	}
    map[j] = NULL;
	return map;
}
char **check_eof(int *nb_lines, int start_map, char **map, char **wf)
{
	int i;
	int j;
	
	i = start_map + *nb_lines;
	while(wf[i])
	{
		j = 0;
		printf("we are on this line '%s'\n\n", wf[i]);
		while(wf[i][j])
		{
			if(wf[i][j] != '\n' && !ft_isspace(wf[i][j]) && wf[i][j] != '1' && wf[i][j] != '0' && wf[i][j] != 'S' && wf[i][j] != 'N' && wf[i][j] != 'W' && wf[i][j] != 'E')
				return (printf("On this line we found '%c', FAILURE\n",wf[i][j]), NULL);
			j++;
		}
		(*nb_lines)++;
		i++;
	}
	return(map_fill(nb_lines, start_map, map, wf));
}
char **map_part(char **map, char **wf/* , int fd */)
{
    int i = 0;
    int start_map = 0;
    int nb_lines = 0;
	
    while(wf[i] && wf)
    {
		char c = wf[i][0];
		printf("Tested char is '%c'\n", c);
		if(wf[i][0] == '1' || wf[i][0] == '0' || (wf[i][0] == ' ' 
            || (wf[i][0] > 10  && wf[i][0] <= 13)))
		{
			if(line_tester((wf[i])))
			{
				printf("The %dth line is accepted : %s\n", i, wf[i]);
				nb_lines++;
				printf("So we increment number of lines -->%d\n", nb_lines);
			}
			else
			{
				printf("line %d hasnt been accepted\n\n",i);
				if(!nb_lines)
				{
					printf("we increment start_map -->%d\n", start_map);
					start_map++;}
			}
		}
		else if(wf[i][0] == '\n' && nb_lines)
			return(check_eof(&nb_lines, start_map, map, wf));
        else
        {
			printf("line %d didnt pass the first test because wf[i][0] was '%c'\n\n", i, wf[i][0]);
			start_map++;
			printf("we increment start_map -->%d\n", start_map);
		}
        i++;
    }
    return(map_fill(&nb_lines, start_map, map, wf));
}
