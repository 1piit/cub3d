#include "../includes/cub3d.h"

void check_args(int ac)
{
    if(ac != 2)
        exit(0);
}
int count_fd_lines(int fd)
{
    char *line;
    int nb = 0;
    line = get_next_line(fd);
    while(line)
    {
        //free(line);
        line = get_next_line(fd);
        nb++;
    }
    //free(line);
    return nb;
}
char **alloc_file_size(char **file_tab, int fd, int fd2)
{
/*     t_garbage **garb;
    garb = get_garbage(); */
    int lines;
    int i;
    i = 0;
    lines = count_fd_lines(fd);
	close(fd);
    file_tab = gc_mem(MALLOC, (sizeof(char *) * (lines + 1)), NULL, GEN);
    //file_tab = malloc(sizeof(char *) * (lines + 1));
    if(!file_tab)
        return NULL;
    while(i < lines)
    {
        file_tab[i] = get_next_line(fd2);
        i++;
    }
    file_tab[i] = NULL;
	close(fd2);
    return file_tab;
}
int only_space(char *line)
{
	int i = 0;
	while(line[i])
	{
		if((!(line[i] >= 9 && line[i] <= 13)))
			return 0;
		i++;
	}
	return 1;
}
int line_tester(char *line)
{
    int i = 0;
	while(line[i])
	{
        if(!(line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == ' ' || (line[i] >= 9 && line[i] <= 13)))
            return 0;
		i++;
	}
	if(only_space(line))
		return 0;
	return 1;
}
char **map_fill(int nb_lines, int start, char **map, int fd)
{
	int i = 0;
	char *line;
	while(i < start)
	{
		line = get_next_line(fd);
		//free(line);
		i++;
	}
    map = gc_mem(MALLOC, (sizeof(char *) * (nb_lines + 1)), NULL, GEN);
	//map = malloc(sizeof(char *) * (nb_lines + 1));
	i = 0;
	while(i < nb_lines)
	{
		map[i] = get_next_line(fd);
		i++;
	}
    map[i] = NULL;
	return map;
}
char **map_part(char **map, char **wf, int fd)
{
    int i = 0;
    int fst = 0;
    int start_map = 0;
    int nb_lines = 0;
	char c;
	if(wf[i])
		printf("yes2\n");
    while(wf[i] && wf)
    {
		c = wf[i][fst];
		if(wf[i][fst] == '1' || wf[i][fst] == '0' || wf[i][fst] == 'N' || (wf[i][fst] == ' ' 
            || (wf[i][fst] > 10  && wf[i][fst] <= 13)) || (!(wf[i][fst] == '\n')))
            if(line_tester(wf[i]))
            {
                nb_lines++;
            }
            else
            {    
				if(!nb_lines)
                    start_map++;
			}
        else
            start_map++;
        i++;
    }
    map = map_fill(nb_lines, start_map, map, fd);
	return map;
}
t_file split_file(t_file cubfile, char **file_tab)
{
	int i = 0;
	cubfile.fd = open(cubfile.save_file, O_RDONLY);
    cubfile.map = map_part(cubfile.map, file_tab, cubfile.fd);
	while(cubfile.map[i])
	{
		printf("%s", cubfile.map[i]);
		i++;
	}
/*     cubfile.ceilfloor = ceilfloor_part(cubfile.map, file_tab);
    cubfile.textures = textures_part(cubfile.textures, file_tab); */
	return cubfile;
}
void init_structs(t_file *cubfile, char *file_arg)
{
	cubfile->save_file = file_arg;
    cubfile->ceilfloor = NULL;
    cubfile->map = NULL;
    cubfile->textures = NULL;
}