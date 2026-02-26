/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:06:49 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/26 18:50:11 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void tester(t_file cubfile)
{
    int i = 0;
    printf("MAP_CONTENT : \n");
    while(cubfile.map[i])
    {
        printf("%s", cubfile.map[i]);
        i++;
    }
    printf("\n\n\n --------------------------------------------- \n\n\n");
    printf("CEILFLOOR & RGB CONTENT : \n");
    i = 0;
    while(cubfile.ceilfloor[i])
    {
        printf("%s\n",cubfile.ceilfloor[i]);
        i++;
    }
    printf("\n\n\n --------------------------------------------- \n\n\n");
    i = 0;
    while(cubfile.RGB_c[i] && cubfile.RGB_f[i])
    {
        printf("value [%d] : RGB_c -->%d && RGB_f-->%d\n", i, cubfile.RGB_c[i], cubfile.RGB_f[i]);
        i++;
    }
    printf("\n\n\n --------------------------------------------- \n\n\n");
    while(cubfile.RGB_c[i])
    printf("\n\n\n --------------------------------------------- \n\n\n");
    printf("TEXTURE CONTENT : \n");
    printf("wt_line[0] is :%s\n\n", cubfile.wt_line[0]);
    printf("wt_line[1] is :%s\n\n", cubfile.wt_line[1]);
    printf("wt_line[2] is :%s\n\n", cubfile.wt_line[2]);
    printf("wt_line[3] is :%s\n\n", cubfile.wt_line[3]);
    printf("texture_file[0] is :%s\n\n", cubfile.texture_file[0]);
    printf("texture_file[1] is :%s\n\n", cubfile.texture_file[1]);
    printf("texture_file[2] is :%s\n\n", cubfile.texture_file[2]);
    printf("texture_file[3] is :%s\n\n", cubfile.texture_file[3]);
}
int	main(int ac, char **av)
{
    char **file_tab;
    int fd2;
    int i;
    t_file cubfile;
    t_garbage **garbage;
    
    garbage = get_garbage();
    check_args(ac);
    init_structs(&cubfile, av[1]);
    cubfile.fd = open(av[1], O_RDONLY);
    fd2 = open(av[1], O_RDONLY);
    i = 0;
    file_tab = NULL;
    file_tab = alloc_file_size(file_tab, cubfile.fd, fd2);
    cubfile = split_file(cubfile, file_tab);
    tester(cubfile);
    gc_mem(FULL_CLEAN, 0, NULL, GEN);
    return (0);
}
