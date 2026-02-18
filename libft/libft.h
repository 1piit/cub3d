/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbride <pbride@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 16:47:25 by pbride            #+#    #+#             */
/*   Updated: 2025/10/13 16:15:35 by pbride           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

int		ft_isspace(int c);
void	ft_sitoa(int n, char *n_dst);
int		ft_isdigit(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
