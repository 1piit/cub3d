/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_datas_gen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 17:21:20 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/12 12:47:45 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_msg(const char *msg, int status)
{
	printf("%s\n", msg);
	printf("Error:%d\n", status);
}
void is_here(int *flag, t_file cubfile)
{
    if(!cubfile.ceilfloor || !cubfile.ceilfloor[0] || !cubfile.ceilfloor[1]
		|| !cubfile.map || !cubfile.map[0] || !cubfile.wt_line
		|| !cubfile.wt_line[0])
        *flag = 1;

}
void	extra_data(int *flag, t_file cubfile)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cubfile.map && cubfile.map[i])
	{
		if(blank_line(cubfile.map[i]))
			cubfile.used_lines++;
		i++;
		j++;
	}
	i = 0;
	while (cubfile.ceilfloor && cubfile.ceilfloor[i++])
		j++;
	i = 0;
	while (cubfile.wt_line && cubfile.wt_line[i++])
		j++;
	if ((unsigned int)j != cubfile.used_lines)
		*flag = 1;
	printf(" %d <=> j VS %d <=> used_lines\n", j, cubfile.used_lines);
}
void empty_file(int *flag, t_file cubfile)
{
    if(!cubfile.used_lines)
        *flag = 1;
}

void check_extension(int *flag, char *file)
{
	int i;
	//int found;

	//found = 0;
	i = 0;

	while(file[i])
	{
		if(file[i] == '.')
		{
			if(!ft_strncmp(&file[i], ".cub", 4) && !file[i+4])
				return;
		}
		i++;
	}
	*flag = 1;
}
int	parsing_datas(t_file cubfile, char *file)
{
	int flag;
	flag = 0;

	check_extension(&flag, file);
	printf("\nflag check_extension-->%d\n", flag);
	check_dimensions(&flag, cubfile);
	printf("flag check_dimensions-->%d\n", flag);
	check_player(&flag, cubfile);
	printf("flag check_player-->%d\n", flag);
	enclosed_map(&flag, cubfile.map);
	printf("flag enclosed_map-->%d\n", flag);
	invalid_textures(&flag, cubfile);
	printf("flag invalid_textures-->%d\n", flag);
	invalid_rgb_case_one(&flag, cubfile.RGB_c, cubfile.RGB_f);
	printf("flag invalid_rgb_case_one-->%d\n", flag);
	invalid_rgb_case_two(&flag, cubfile.ceilfloor);
	printf("flag invalid_rgb_case_two-->%d\n", flag);
	is_here(&flag, cubfile);
	printf("flag is_here-->%d\n", flag);
    empty_file(&flag, cubfile);
	printf("flag empty_file-->%d\n", flag);
	extra_data(&flag, cubfile);
	printf("flag extra_data-->%d\n", flag);
	if (flag)
		return (0);
	return (1);
}
