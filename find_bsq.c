/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_bsq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 17:33:38 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 23:04:17 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	is_possible(t_map *mapt, int row, int col, int dims)
{
	int	r;
	int	c;

	r = row;
	c = col;
	if (((col + dims) > mapt->cols) || ((row + dims) > mapt->rows))
		return (0);
	while (r < (row + dims))
	{
		c = col;
		while (c < (col + dims))
		{
			if (mapt->map[r][c] == mapt->obst)
				return (0);
			c++;
		}
		r++;
	}
	mapt->row_best = row;
	mapt->col_best = col;
	mapt->dim_best = dims;
	return (1);
}

void	ft_print_res(t_map *mapt)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < mapt->rows)
	{
		j = 0;
		while (j < mapt->cols)
		{
			if ((i >= mapt->row_best && j >= mapt->col_best)
				&& (i < (mapt->row_best + mapt->dim_best)
					&& j < (mapt->col_best + mapt->dim_best)))
				write(1, &(mapt->full), 1);
			else
				write(1, &mapt->map[i][j], 1);
			if (j == mapt->cols - 1)
			{
				write(1, "\n", 1);
			}
			j++;
		}
		i++;
	}
}

void	find_solution(t_map *mapt)
{
	int		i;
	int		j;
	int		best;

	i = 0;
	j = 0;
	best = 0;
	while (i < mapt->rows)
	{
		j = 0;
		while (j < mapt->cols)
		{
			while (1)
			{
				if (is_possible(mapt, i, j, best + 1))
					best++;
				else
					break ;
			}
			j++;
		}
		i++;
	}
}

int	one_to_one(t_map *mapt)
{
	if (mapt->map[0][0] == mapt->empty)
	{
		write(1, &mapt->full, 1);
		write(1, "\n", 1);
	}
	else
	{
		write(1, &mapt->obst, 1);
		write(1, "\n", 1);
	}
	smart_free(mapt);
	return (1);
}

int	find_bsq(char ***map)
{
	t_map	*mapt;

	mapt = create_tmap(*map);
	if (mapt <= 0)
	{
		write(2, "map error\n", 10);
		smart_free(mapt);
		return (0);
	}
	find_solution(mapt);
	if (mapt->dim_best >= 0 || mapt->dim_best < 0)
	{
		ft_print_res(mapt);
		smart_free(mapt);
	}
	else if (mapt->rows == 1 && mapt->cols == 1)
		return (one_to_one(mapt));
	else
	{
		write(2, "map error\n", 10);
		smart_free(mapt);
		return (0);
	}
	return (1);
}
