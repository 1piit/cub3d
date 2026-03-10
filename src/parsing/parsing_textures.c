/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 14:47:27 by ptricaud          #+#    #+#             */
/*   Updated: 2026/03/07 17:33:05 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int check_xpm(char *tf)
{
	int i;

	i = 0;
	while(tf[i])
	{
		if(tf[i] == '.')
		{
			if(!ft_strncmp(&tf[i], ".xpm", 4))
				return 1;
			else
				return 0;
		}
		i++;
	}
    return 0;
}
void invalid_textures(int *flag, t_file cubfile)
{
    int fd;
    int i;
    
    i = 0;
    while(cubfile.texture_file[i])
    {
        fd = open(cubfile.texture_file[i], O_RDONLY);
        if(fd < 0 || !check_xpm(cubfile.texture_file[i]))
        {
            *flag = 1;
            return;
        }
        else
            close(fd);
        i++;
    }
    if(i <= 3)
        *flag = 1;
}