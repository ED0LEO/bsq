/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   headers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlothair <mlothair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 14:05:05 by ralfredi          #+#    #+#             */
/*   Updated: 2021/09/22 21:58:16 by mlothair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADERS_H
# define HEADERS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	full;
	char	**map;
	int		row_best;
	int		col_best;
	int		dim_best;
};

struct s_new_file
{
	char	*name;
};

typedef struct s_map		t_map;
typedef struct s_new_file	t_nf;

int		map_is_good(char **map);
int		line_is_good(char *str);
int		count_cols(char **map);
int		count_rows(char **map);
int		find_bsq(char ***map);
int		std_in(char **buf);
char	**remove_first_line(char **map);
int		ft_strlen(char *str);
int		map_decl_is_good(char *line);
int		read_num_of_lines(char *fl);
int		zero_arg(void);
int		read_file_known(t_nf *nf, char **buf);
int		parse_all_known(char *grand_buf, char ***names);
t_map	*create_tmap(char **map);
t_nf	*create_nf(char *name);
void	smart_free(void *thing);
void	smart_free_arr(void **arr_thing);
int		ft_check_if_at_least_one_box(char **map);
int		ft_check_if_enough_linebreaks(char *str);
int		ft_check_if_valid_char(char **map);
int		ft_check_if_lines_num_valid(char **map);
int		ft_check_if_same_length(char **map);

#endif
