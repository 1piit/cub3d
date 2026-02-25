#ifndef CUB3D_H
#define CUB3D_H

#define BUFFER_SIZE 42
#include <stdbool.h>
#include <stdio.h>

#include "parsing.h"
#include "get_next_line.h"
#include "garb.h"
#include "libft.h"

//main_utils.c

void check_args(int ac);
void init_structs(t_file *cubfile, char *file_arg);

#endif
