#ifndef PARSING_H
#define PARSING_H

#include "cub3d.h"

typedef struct s_garbage t_garbage;
typedef struct s_file
{
    char *save_file;
    char **textures;
    char **map;
    char **ceilfloor;
    int fd;
} t_file;

void check_args(int ac);
int count_fd_lines(int fd);
char **alloc_file_size(char **file_tab, int fd, int fd2);
char **map_part(char **map, char **whole_file, int fd);
t_file split_file(t_file cubfile, char **file_tab);
void init_structs(t_file *cubfile, char *file_arg);



#endif