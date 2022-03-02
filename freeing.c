/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 14:13:18 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 17:10:36 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	smart_free(void *thing)
{
	if (thing == 0)
	{
		return ;
	}
	free (thing);
}

void	smart_free_arr(void **arr_thing)
{
	int	i;

	i = 0;
	if (arr_thing == 0)
	{
		return ;
	}
	while (arr_thing[i] > 0)
	{
		if (arr_thing[i] != 0)
			free(arr_thing[i]);
		i++;
	}
	if (arr_thing != 0)
		free (arr_thing);
}
