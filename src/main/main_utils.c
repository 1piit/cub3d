#include "../includes/cub3d.h"

void	check_args(int ac)
{
	if (ac != 2)
		exit(0);
}

void	init_structs(t_file *cubfile, char *file_arg)
{
	cubfile->save_file = file_arg;
	cubfile->ceilfloor = NULL;
	cubfile->map = NULL;
	cubfile->texture_file = NULL;
}

void	init_data(t_data *data)
{
	*data = (t_data){0};
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1080, "cub3D - P2P");
}
