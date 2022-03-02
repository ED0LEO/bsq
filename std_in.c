/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 19:48:45 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 22:40:51 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	std_in(char **buf)
{
	char	symbol;
	int		i;
	int		ret;

	i = 0;
	symbol = 0;
	ret = 1;
	*buf = malloc(9999999999);
	while (1)
	{
		ret = read(0, &symbol, 1);
		if (ret < 0)
			return (0);
		(*buf)[i] = symbol;
		if (ret == 0)
		{
			(*buf)[i] = '\0';
			break ;
		}
		i++;
	}
	return (1);
}
