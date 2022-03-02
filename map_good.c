/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_good.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 17:13:20 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 17:09:22 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_check_if_lines_num_valid(char **map)
{
	int	num;
	int	it;

	num = read_num_of_lines(map[0]);
	it = 1;
	while (map[it] > 0)
	{
		it++;
	}
	it--;
	if (it != num)
		return (0);
	return (1);
}

int	ft_check_if_valid_char(char **map)
{
	char	empty;
	char	obstacle;
	int		i;
	int		j;

	empty = map[0][ft_strlen(map[0]) - 3];
	obstacle = map[0][ft_strlen(map[0]) - 2];
	i = 1;
	j = 0;
	while (map[i])
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] != empty && map[i][j] != obstacle)
			{
				return (0);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

int	linebreaks_inner_logic(char *str, int *i, int *c)
{
	int	newline1;
	int	newline2;

	while (str[*i])
	{
		if (str[*i] == '\n' && *c > 1)
		{
			if ((*i - newline2) != (newline2 - newline1))
				return (0);
			newline1 = newline2;
			newline2 = *i;
		}
		if (str[*i] == '\n' && *c == 1)
		{
			newline2 = *i;
			(*c)++;
		}
		if (str[*i] == '\n' && *c == 0)
		{
			newline1 = *i;
			(*c)++;
		}
		(*i)++;
	}
	return (1);
}

int	ft_check_if_enough_linebreaks(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	linebreaks_inner_logic(str, &i, &c);
	if (str[i - 1] != '\n' || c < 2)
		return (0);
	return (1);
}

int	ft_check_if_at_least_one_box(char **map)
{
	char	**firstline;

	firstline = remove_first_line(map);
	if (firstline[0][0] < 32 || firstline[0][0] == 127)
		return (0);
	return (1);
}
