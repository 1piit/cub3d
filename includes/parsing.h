#ifndef PARSING_H
#define PARSING_H

#include "cub3d.h"

typedef struct s_garbage t_garbage;
typedef struct s_file
{
    char *save_file;
    char **wt_line;
    char **texture_file;
    char **map;
    char **ceilfloor;
    unsigned int  *RGB_f;
    unsigned int  *RGB_c;
    int fd;
} t_file;

//extract_map.c
char **map_part(char **map, char **whole_file);

//extract_ceilfloor.c
char **ceilfloor_part(t_file *cubfile, char **wf);

//extract_textures.c
void textures_part(char **texture_file, char **wt_line, char **wf);

//file_alloc.c
int count_fd_lines(int fd);
char **alloc_file_size(char **file_tab, int fd, int fd2);
t_file split_file(t_file cubfile, char **file_tab);



#endif