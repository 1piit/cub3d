#ifndef CUB3D_H
#define CUB3D_H

#define BUFFER_SIZE 42
#include <stdbool.h>
#include <stdio.h>
#include <mlx.h>

#include "parsing.h"
#include "get_next_line.h"
#include "garb.h"
#include "libft.h"

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	//int		width;
	//int		height;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	t_img	mini_map;
}	t_data;

//main_utils.c
void	check_args(int ac);
void	init_structs(t_file *cubfile, char *file_arg);
void	init_data(t_data *data);

#endif
