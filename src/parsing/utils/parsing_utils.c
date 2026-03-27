/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 14:35:34 by pbride            #+#    #+#             */
/*   Updated: 2026/03/27 11:23:51 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

//int tester_extract(t_file cubfile)
//{
//    int i = 0;
//    printf("MAP_CONTENT : \n");
//    if(!cubfile.map || !cubfile.map[0])
//        return(printf("No map detected\n"));
//    while(cubfile.map[i])
//    {
//        printf("%s\n", cubfile.map[i]);
//        i++;
//    }
//    printf("\n\nthere is %d lines\n\n", i);
//    printf("\n\n\n --------------------------------------------- \n\n\n");
//    printf("CEILFLOOR & RGB CONTENT : \n");
//    i = 0;
//    if(!cubfile.ceilfloor || !cubfile.ceilfloor[0] || !cubfile.ceilfloor[1])
//        return(printf("No ceilfloor detected\n"));
//    while(cubfile.ceilfloor[i])
//    {
//        printf("%s\n",cubfile.ceilfloor[i]);
//        i++;
//    }
//    printf("\n\n\n --------------------------------------------- \n\n\n");
//    i = 0;
//    while(i < 3)
//    {
//        printf("value [%d] : RGB_c -->%d && RGB_f-->%d\n",
					//i, cubfile.rgb_c[i], cubfile.rgb_f[i]);
//        i++;
//    }
//    printf("\n\n\n --------------------------------------------- \n\n\n");
//    printf("TEXTURE CONTENT : \n");
//    if(!cubfile.wt_line || !cubfile.texture_file)
//        return(printf("No textures detected\n"));
//    printf("wt_line[0] is :%s\n\n", cubfile.wt_line[0]);
//    printf("wt_line[1] is :%s\n\n", cubfile.wt_line[1]);
//    printf("wt_line[2] is :%s\n\n", cubfile.wt_line[2]);
//    printf("wt_line[3] is :%s\n\n", cubfile.wt_line[3]);
//    printf("texture_file[0] is :%s\n\n", cubfile.texture_file[0]);
//    printf("texture_file[1] is :%s\n\n", cubfile.texture_file[1]);
//    printf("texture_file[2] is :%s\n\n", cubfile.texture_file[2]);
//    printf("texture_file[3] is :%s\n\n", cubfile.texture_file[3]);
//    return 0;
//}

static void	init_structs(t_file *cubfile, char *file_arg)
{
	cubfile->save_file = file_arg;
	cubfile->ceilfloor = NULL;
	cubfile->map = NULL;
}

void	init_parsing(t_data *data, int ac, char **av)
{
	char	**file_tab;
	int		fd2;

	check_args(ac);
	init_structs(&data->cubfile, av[1]);
	data->cubfile.fd = open(av[1], O_RDONLY);
	fd2 = open(av[1], O_RDONLY);
	file_tab = NULL;
	file_tab = alloc_file_size(&data->cubfile, file_tab, data->cubfile.fd, fd2);
	data->cubfile = split_file(data->cubfile, file_tab);
	if (!parsing_datas(data->cubfile, av[1]))
	{
		printf("\nMAP/FICHIER INVALIDE\n");
		gc_mem(FULL_CLEAN, 0, NULL, GEN);
		exit(ERROR);
	}
}
