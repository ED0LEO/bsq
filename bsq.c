/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:08:10 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 23:19:17 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	super_break(int num)
{
	if (num > 1)
		write(1, "\n", 1);
}

int	work_on_one(t_nf *nf)
{
	char	**map;
	char	*tempbuf;

	if ((read_file_known(nf, &tempbuf) == 0)
		|| tempbuf <= 0 || !line_is_good(tempbuf))
	{
		write(2, "map error\n", 10);
		smart_free(tempbuf);
		return (0);
	}
	parse_all_known(tempbuf, &map);
	if (map <= 0 || !map_is_good(map) || !ft_check_if_same_length(map))
	{
		write(2, "map error\n", 10);
		smart_free(tempbuf);
		smart_free(map);
		return (0);
	}
	find_bsq(&map);
	smart_free(tempbuf);
	smart_free_arr((void **) map);
	return (1);
}

int	work_on_all(char **names, int number_of_files)
{
	int		i;
	t_nf	*nf;

	i = 1;
	while (i < number_of_files)
	{
		super_break(i);
		nf = create_nf(names[i]);
		i++;
		if (nf == 0)
		{
			write(2, "map error\n", 10);
			continue ;
		}
		if (nf < 0)
		{
			write(2, "map error\n", 10);
			smart_free(nf);
			continue ;
		}
		work_on_one(nf);
		smart_free(nf);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		zero_arg();
	}
	else if (argc < 2)
	{
		write(2, "map error\n", 14);
		exit(1);
	}
	else
		work_on_all(argv, argc);
	exit(0);
}
