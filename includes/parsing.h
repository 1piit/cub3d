/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/25 18:45:03 by pbride            #+#    #+#             */
/*   Updated: 2026/03/27 11:19:18 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

typedef struct s_data		t_data;
typedef struct s_garbage	t_garbage;

typedef struct s_map_part
{
	int	start;
	int	nb_lines;
}	t_map_part;

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

/* extract_map_utils.c */
int		only_space(char *line);
int		line_tester(char *line);
char	*null_terminate(char *str);
char	**map_fill(int *nb_lines, int start, char **map, char **wf);
char	**check_eof(int *nb_lines, int start_map, char **map, char **wf);

/* extract_ceilfloor.c */
char	**ceilfloor_part(t_file *cubfile, char **wf);

/* extract_cf_utils.c */
int		check_ceilfloor_line(char *str);
char	*look_char(char *wf, char letter);
void	get_values(int *rgb, char *str);
char	*join_line(char *str, char letter);
int		check_format(char *str, char letter);

/* extract_textures.c */
void	textures_part(char **texture_file, char **wt_line, char **wf);

/* extract_text_utils.c */
int		blank_skipper(char **str, int i);
int		ft_isspace(int c);
int		wt_line_getter(char **wt_line, int *index, char *wf, const char *dir);
int		textures_getter(char **texture_file, int *index, char *wf, char *dir);

/* file_alloc.c */
int		count_fd_lines(int fd, t_file *cubfile);
char	**alloc_file_size(t_file *cubfile, char **file_tab, int fd, int fd2);
t_file	split_file(t_file cubfile, char **file_tab);

/* parsing_map.c */
void	check_dimensions(int *flag, t_file cubfile);
void	enclosed_map(int *flag, char **map);

/* parsing_map_utils.c */
char	**temp_map(char **map, int *longest);

/* parsing_map_utils2.c */
int		left_side(char **temp);
int		right_side(char **temp);
int		top_side(char **temp);
int		bottom_side(char **temp);
int		edges_first(char **temp);

/* parsing_player.c */
void	check_player(int *flag, t_file cubfile);

/* parsing_ceilfloor.c */
void	invalid_rgb_case_one(int *flag, int RGB_c[3], int RGB_f[3]);
void	invalid_rgb_case_two(int *flag, char **ceilfloor);

/* parsing_textures.c */
void	invalid_textures(int *flag, t_file cubfile);

/* parsing_datas_gen.c */
int		parsing_datas(t_file cubfile, char *file);

/*file_alloc.c */
int		blank_line(char *str);

#endif
