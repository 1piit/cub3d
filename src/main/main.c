/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 13:43:56 by pbride            #+#    #+#             */
/*   Updated: 2026/02/20 14:05:48 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void check_args(int ac/* , char **av */)
{
	if(ac != 2)
		exit(0);
	return;
}
void blank_skipper(int *i, char *cubfile)
{
	/* while(cubfile && cubfile[*i])
		(*i)++; */
	if(!cubfile[*i])
		return;
	while(cubfile[*i] != ' '|| (cubfile[*i] >= 13 && cubfile[*i] <= 9))
		(*i)++;
}
void reach_endline(int *i, char *cubfile)
{
	while(cubfile[*i] != '\n' && cubfile[*i])
		(*i)++;
}
int digit_tester(int *i, char *cubfile)
{
	int flag = 1;
	int isdigit = *i;
	if(ft_isdigit(cubfile[*i]))
		while(cubfile && cubfile[*i] != '\n' && cubfile[*i] != '\0')
		{
			if((!ft_isdigit(cubfile[*i])) && (!(cubfile[*i] != ' ' || (cubfile[*i] >= 13 && cubfile[*i] <= 9))))
			{
				reach_endline(i, cubfile);
				flag = 0;
			}
			(*i)++;
		}
	if(isdigit == *i)
		flag = 0;
	return flag;
}
char *fill_buffer(int fd)
{
	char *str;
	int end;
	str = ft_calloc(BUFFER_SIZE, 1);
	if(!str)
		return NULL;
	end = read(fd, str, BUFFER_SIZE);
	if(!end)
		return(free(str), NULL);
	str[end] = '\0';
	return str;
}
//Si je rencontre des blank apres le '\n' , alors je dois :
//1/ Skip tous les blank avant de rencontrer un caractere
//2/Si le caractere rencontre est un digit, tester toute la ligne: ca doit etre soit blank, soit digit
int count_map_lines(int fd, int *start)
{
	int i = 0;
	int nb_lines = 0;
	char *buffer;
	buffer = NULL;
	char test;
	buffer = fill_buffer(fd);
	while(buffer[i])
	{
		test = buffer[i];
		if(buffer[i] == '\n')
		{
			i++;
			test = buffer[i];
			if(!nb_lines)
				(*start)++;
			blank_skipper(&i, buffer);
			if(digit_tester(&i, buffer))
				nb_lines++;
		}	
		i++;
	}
	return nb_lines + 1;
}
char **alloc_fill_map(char **map, char *cubfile)
{
	int start = 0;
	int fd = open(cubfile, O_RDONLY);
	int nb_lines = count_map_lines(fd, &start);
	char *line;

	line = get_next_line(fd);
	map = malloc(sizeof(char *) * (nb_lines + 1));
	while(line != NULL && start != 0)
	{
		line = get_next_line(fd);
		free(line);
		start--;
	}
	while(start < nb_lines)
	{
		map[start] = ft_strdup(get_next_line(fd));
		start++;
	}
	map[start] = NULL;
	return map;
}
int	main(int ac, char **av)
{
	char **map;
	int i;
	i = 0;
	map = NULL;
	check_args(ac/* , av */);
	map = alloc_fill_map(map, av[1]);
	while(map && map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	
	return (0);
}
