/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:00:22 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 15:31:46 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h> 
# include <stdlib.h>

typedef struct s_data
{
	int	max;
	int	a0;
	int	b0;
	int	c0;
	int	counter;
}	t_data;

// atoi
int		is_long_int(char *str);
int		is_int(char *str, int len_nb, int sign);
int		convert_to_int(char *str, int len_nb, int sign);
int		is_atoi_int(char *str);
int		atoi_int(char *str);

// cases
int		*case2(int tab[][4], t_data *data, int col);
int		*case3(int tab[][4], t_data *data);
int		*case3_inv(int tab[][4], t_data *data);
int		*case6(int tab[][4], t_data *data);
int		*case_max6(int tab[][4], t_data *data);

// errors
int		check_error_double(int tab[][4], t_data *data);
int		check_error_atoi(int argc, char **argv);

// functions_tab
int		*convert_to_rank(int tab[][4], t_data *data);
int		is_sorted(int tab[][4], t_data *data);
int		*pb_min(int tab[][4], t_data *data, int nb);

// init
int		*init_tab(int tab[][4], t_data *data, int argc, char **argv);
int		*init_tab_ab(int tab[][4], int argc, char **argv);
int		*copy_a_to_cd(int tab[][4], t_data *data);
int		*sort_c(int tab[][4], t_data *data);
void	init_data(t_data *data, int argc);

// moves
int		*ss(int tab[][4], t_data *data);
int		*rr(int tab[][4], t_data *data);
int		*rrr(int tab[][4], t_data *data);
int		*pa(int tab[][4], t_data *data);
int		*pb(int tab[][4], t_data *data);

// moves_col
int		*s_col(int tab[][4], t_data *data, int col);
int		*r_col(int tab[][4], t_data *data, int col);
int		*rr_col(int tab[][4], t_data *data, int col);
int		tern(int i, int rtrue, int rfalse);

// radix
int		*radix(int tab[][4], t_data *data, int rank);
int		count_nb(int tab[][4], t_data *data, int rank);
int		*push_to_a(int tab[][4], t_data *data);
int		*push_to_b(int tab[][4], t_data *data, int rank);

// utils
int		str_len(char *str);
int		calc_div(int rank);
int		calc_gap(int tab[][4], t_data *data, int rank);
int		convert_to_bin(int nb);

#endif
