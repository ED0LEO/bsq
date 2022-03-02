/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_preparation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:08:29 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 19:41:04 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	line_is_good(char *str)
{
	return (ft_check_if_enough_linebreaks(str));
}

int	map_is_good(char **map)
{
	return (ft_check_if_at_least_one_box(map) && ft_check_if_valid_char(map)
		&& ft_check_if_lines_num_valid(map) && map_decl_is_good(map[0]));
}

char	**remove_first_line(char **map)
{
	return (&map[1]);
}

int	map_decl_is_good(char *line)
{
	int	size;
	int	i;

	i = 0;
	size = ft_strlen(line);
	if (size < 4)
		return (0);
	if ((line[size - 1] == line[size - 2])
		|| (line[size - 3] == line[size - 1])
		|| (line[size - 3] == line[size - 2]))
		return (0);
	if (line[size - 1] < 32 || line[size - 2] < 32 || line[size - 3] < 32
		|| line[size - 1] == 127 || line[size - 2] == 127
		|| line[size - 3] == 127)
		return (0);
	while (i < size - 3)
	{
		if (line[i] < '0' || line[i] > '9')
			return (0);
		i++;
	}
	if (read_num_of_lines(line) < 1)
		return (0);
	return (1);
}

int	ft_check_if_same_length(char **map)
{
	int	i;
	int	j;
	int	length;

	i = 1;
	j = 0;
	while (map[i] != 0)
	{
		while (map[i][j])
			j++;
		if (i != 1)
		{
			if (length != j)
				return (0);
		}
		length = j;
		j = 0;
		i++;
	}
	return (1);
}
