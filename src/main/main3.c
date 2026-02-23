#include "../../includes/cub3d.h"

int main(int ac, char **av)
{
    (void) ac;
    int fd;
    char *line;
    fd = open(av[1], O_RDONLY);
    line = get_next_line(fd);
    while(line != NULL)
    {
        //free(line);
        line = get_next_line(fd);
        printf("%s", line);
    }
    //free(line);
    return 0;
}