/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:07:47 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 15:10:50 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	int		(*tab)[4];
	t_data	data;
	int		rank;

	tab = malloc(sizeof(int [4]) * (argc - 1));
	if (tab == 0)
		return (write(2, "Error\n", 6), 1);
	init_data(&data, argc);
	if (check_error_atoi(argc, argv) == 1)
		return (free(tab), 1);
	init_tab(tab, &data, argc, argv);
	if (check_error_double(tab, &data) == 1)
		return (free(tab), 1);
	convert_to_rank(tab, &data);
	if (is_sorted(tab, &data))
		return (free(tab), 0);
	rank = 0;
	if (data.max <= 5)
		case_max6(tab, &data);
	else
		while (!is_sorted(tab, &data))
			rank += (radix(tab, &data, rank), 1);
	return (free(tab), 0);
}
