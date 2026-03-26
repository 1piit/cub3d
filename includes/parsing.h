/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:45:03 by pbride            #+#    #+#             */
/*   Updated: 2026/03/26 18:20:35 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_data		t_data;
typedef struct s_garbage	t_garbage;

typedef struct s_file
{
	char			*save_file;
	char			**wt_line;
	char			**texture_file;
	char			**map;
	char			**ceilfloor;
	int				*rgb_f;
	int				*rgb_c;
	unsigned int	used_lines;
	int				fd;
}	t_file;

/* parsing_utils.c */
void	init_parsing(t_data *data, int ac, char **av);

/* extract_map.c */
char	**map_part(char **map, char **whole_file);

/* extract_ceilfloor.c */
char	**ceilfloor_part(t_file *cubfile, char **wf);

/* extract_textures.c */
void	textures_part(char **texture_file, char **wt_line, char **wf);
int		ft_isspace(int c);

/* file_alloc.c */
int		count_fd_lines(int fd, t_file *cubfile);
char	**alloc_file_size(t_file *cubfile, char **file_tab, int fd, int fd2);
t_file	split_file(t_file cubfile, char **file_tab);

/* parsing_datas */
int		parsing_datas(t_file cubfile, char *file);
void	error_msg(const char *msg, int status);
void	invalid_rgb_case_one(int *flag, int RGB_c[3], int RGB_f[3]);
void	invalid_rgb_case_two(int *flag, char **ceilfloor);
void	is_here(int *flag, t_file cubfile);
void	check_dimensions(int *flag, t_file cubfile);
void	check_player(int *flag, t_file cubfile);
void	invalid_textures(int *flag, t_file cubfile);
void	enclosed_map(int *flag, char **map);
char	**temp_map(char **map, int *longest);
int		blank_line(char *str);

#endif
