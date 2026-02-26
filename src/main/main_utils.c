#include "../includes/cub3d.h"

void check_args(int ac)
{
    if(ac != 2)
        exit(0);
}
void init_structs(t_file *cubfile, char *file_arg)
{
	cubfile->save_file = file_arg;
    cubfile->ceilfloor = NULL;
    cubfile->map = NULL;
    //cubfile->textures = NULL;
}