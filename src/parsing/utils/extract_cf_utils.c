/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_cf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptricaud <ptricaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 09:46:51 by pbride            #+#    #+#             */
/*   Updated: 2026/04/01 14:37:34 by ptricaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/cub3d.h"

int	check_ceilfloor_line(char *str)
{
	int	i;
	int	limit;

	limit = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			limit++;
		if (limit > 1)
			return (1);
		i++;
	}
	return (0);
}

char	*look_char(char *wf, char letter)
{
	int	i;

	i = 0;
	while (wf && wf[i])
	{
		if (wf[i] == '\n')
		{
			i++;
			continue ;
		}
		while (wf[i] && ft_isspace(wf[i]))
			i++;
		if (wf[i] != letter)
		{
			i++;
			break ;
		}
		else
			return (wf);
	}
	return (NULL);
}

void	get_values(int *rgb, char *str)
{
	int		i;
	char	*ret;
	int		j;
	int		index;

	index = 0;
	ret = gc_mem(MALLOC, 100, NULL, GEN);
	i = 0;
	while (str[i] && index < 3)
	{
		j = 0;
		ft_memset(ret, -1, 5);
		while (!ft_isdigit(str[i]) && str[i] != '\n' && !(str[i] == '+'
				|| str[i] == '-'))
			i++;
		while (ft_isdigit(str[i]) || str[i] == '+' || str[i] == '-')
		{
			ret[j] = str[i];
			j++;
			i++;
		}
		ret[j] = '\0';
		rgb[index] = ft_atoi(ret);
		index++;
	}
}

char	*join_line(char *str, char letter)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (*str == letter)
		str++;
	if (!ft_isspace(*str))
		return (NULL);
	temp = gc_mem(MALLOC, (sizeof(char) * ft_strlen(str) + 1), NULL, GEN);
	while (str[i])
	{
		if (!ft_isspace(str[i]))
		{
			temp[j] = str[i];
			j++;
		}
		i++;
	}
	return (temp);
}

int	check_format(char *str, char letter)
{
	int		i;
	char	*temp;

	i = 0;
	temp = join_line(str, letter);
	if (!temp)
		return (0);
	if (temp[0] == ',')
		return (0);
	while (temp && temp[i++])
	{
		if (temp[i] == ',')
		{
			if (!ft_isdigit(temp[++i]))
				return (0);
		}
	}
	i = 0;
	while (temp[i])
	{
		if (!ft_isdigit(temp[i]) && temp[i] != ',')
			return (0);
		i++;
	}
	return (1);
}
