/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 20:40:24 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 22:30:15 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	zero_preparation(char **tempbuf, char ***map)
{
	std_in(tempbuf);
	if (*tempbuf <= 0 || !line_is_good(*tempbuf))
	{
		write(2, "map error\n", 10);
		smart_free(*tempbuf);
		exit (1);
	}
	parse_all_known(*tempbuf, map);
	if (*map <= 0 || !map_is_good(*map) || !ft_check_if_same_length(*map))
	{
		write(2, "map error\n", 10);
		smart_free(*tempbuf);
		smart_free_arr((void **) *map);
		exit (1);
	}
	return (1);
}

int	zero_arg(void)
{
	char	**map;
	char	*tempbuf;

	zero_preparation(&tempbuf, &map);
	find_bsq(&map);
	smart_free(tempbuf);
	smart_free_arr((void **) map);
	exit (0);
}
