/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 12:57:49 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 19:50:43 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	read_num_of_lines(char *str)
{
	int				res;
	int				i;
	unsigned int	temp;

	temp = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
		return (-1);
	if (str[i] == 43 || str[i] == 45)
		i++;
	while (str[i] != '\0' && i < (ft_strlen(str) - 3))
	{
		if (str[i] >= '0'
			&& str[i] <= '9')
			temp = temp * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	res = temp;
	return (res);
}
