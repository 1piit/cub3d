/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 14:06:49 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/09 17:58:00 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	main(int ac, char **av)
{
	t_data	data;
	(void)ac;
	(void)av;
    //char **file_tab;
    //int fd2;
    //int i;
    //t_file cubfile;
    //t_garbage **garbage;
	char *map[] = {
		"        111111111111111111111",
		"        100000110000000000001",
		"        101100000000000000001",
		"        100100000000000000001",
		"11111111101100000111000000001",
		"10000000001100000111011111011",
		"11110111111111011100000010001    ",
		"11110111111111011101010010001    ",
		"11000000110101011100000010001    ",
		"10000000000000001100000010001    ",
		"10000000000000001101010010001    ",
		"11000001110101011111011110E01  ",
		"11110111 1110101 101111010001    ",
		"11111111 1111111 111111111111    ",
		NULL
	};

	init_data(&data);
	init_game_img(&data);
	draw_mini_map(&data, map);
	mlx_put_image_to_window(data.mlx, data.mlx_win,
		data.game_img.mlx_img, 0, 0);
	mlx_loop(data.mlx);
    //garbage = get_garbage();
    //check_args(ac);
    //init_structs(&cubfile, av[1]);
    //cubfile.fd = open(av[1], O_RDONLY);
    //fd2 = open(av[1], O_RDONLY);
    //i = 0;
    //file_tab = NULL;
    //file_tab = alloc_file_size(file_tab, cubfile.fd, fd2);
    //cubfile = split_file(cubfile, file_tab);
    //gc_mem(FULL_CLEAN, 0, NULL, GEN);

	return (0);
}
