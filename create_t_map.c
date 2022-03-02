/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_t_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:42:26 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 14:42:39 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_map	*create_tmap(char **map)
{
	t_map	*new_elem;
	int		size_of_rules;

	size_of_rules = 0;
	new_elem = malloc (sizeof(t_map));
	if (new_elem == 0)
		return (0);
	size_of_rules = ft_strlen(map[0]);
	new_elem->empty = map[0][size_of_rules - 3];
	new_elem->obst = map[0][size_of_rules - 2];
	new_elem->full = map[0][size_of_rules - 1];
	new_elem->map = remove_first_line(map);
	new_elem->cols = count_rows(new_elem->map);
	new_elem->rows = count_cols(new_elem->map);
	new_elem->row_best = -1;
	new_elem->col_best = -1;
	new_elem->dim_best = -1;
	return (new_elem);
}
