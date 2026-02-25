/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:06:49 by ptricaud          #+#    #+#             */
/*   Updated: 2026/02/23 18:37:00 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

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
    gc_mem(FULL_CLEAN, 0, NULL, GEN);
    return (0);
}
