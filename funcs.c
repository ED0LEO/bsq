/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:59:23 by mlothair          #+#    #+#             */
/*   Updated: 2021/09/22 22:40:29 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

t_nf	*create_nf(char *name)
{
	t_nf	*nf;

	if (name == 0)
		return (0);
	nf = malloc (sizeof(t_nf));
	if (nf == 0)
		return (0);
	nf->name = name;
	return (nf);
}

int	read_file_known(t_nf *nf, char **buf)
{
	int		current_file;
	char	symbol;
	int		i;

	i = 0;
	symbol = 0;
	if (nf->name == 0)
		return (0);
	*buf = malloc(9999999999);
	if (*buf == 0)
		return (0);
	current_file = open(nf->name, O_RDONLY);
	if (current_file == -1)
		return (0);
	while (read(current_file, &symbol, 1))
	{
		(*buf)[i] = symbol;
		i++;
	}
	(*buf)[i] = '\0';
	if (close(current_file) == -1)
		return (0);
	return (1);
}

void	fill_strings(char *grand_buf, char ***names)
{
	int		i;
	int		j;
	int		iter_names;

	i = 0;
	j = 0;
	iter_names = 0;
	while (grand_buf[i] != '\0' && grand_buf[i] > 0)
	{
		if (grand_buf[i] == '\n')
		{
			(*names)[iter_names++][j] = '\0';
			j = 0;
			if (grand_buf[i + 1] > 0)
				(*names)[iter_names] = malloc (80000);
			else
				break ;
			i++;
			continue ;
		}
		(*names)[iter_names][j++] = grand_buf[i++];
	}
	(*names)[iter_names] = 0;
}

int	parse_all_known(char *grand_buf, char ***names)
{
	*names = malloc(80000);
	*names[0] = malloc(80000);
	if (grand_buf <= 0)
		return (0);
	fill_strings(grand_buf, names);
	return (1);
}
