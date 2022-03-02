/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 11:59:23 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/21 19:09:28 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	count_cols(char **map)
{
	int	i;

	i = 0;
	while (map[i] != 0)
		i++;
	return (i);
}

int	count_rows(char **map)
{
	int	i;

	i = 0;
	while (map[0][i] != '\0')
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	int		size1;
	char	c;

	size1 = 0;
	c = str[0];
	while (c != '\0')
	{
		size1++;
		c = str[size1];
	}
	return (size1);
}
