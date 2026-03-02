#include "stdio.h"
//#include "includes/cub3d.h"
#include "includes/libft.h"
int main()
{
    char *big = "bonjour";
    char *lil = "jour";

    printf("%s\n", big);
    big = ft_substr(big, 3, 2);
    printf("%s\n",big);
}