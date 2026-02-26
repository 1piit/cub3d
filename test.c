#include "stdio.h"
//#include "includes/cub3d.h"
#include "includes/libft.h"
int main()
{
    char *big = "bonjour";
    char *lil = "jour";

    printf("%s\n", big);
    big = ft_strnstr(big, lil, ft_strlen(big));
    printf("%s\n",big);
}