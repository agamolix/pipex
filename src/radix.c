/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:24:19 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 15:25:40 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

int	*radix(int tab[][4], t_data *data, int rank)
{
	count_nb(tab, data, rank);
	push_to_b(tab, data, rank);
	push_to_a(tab, data);
	return (tab[0]);
}

int	count_nb(int tab[][4], t_data *data, int rank)
{
	int	i;
	int	res;
	int	div;

	i = 0;
	res = 0;
	div = calc_div(rank);
	while (i <= data->max)
	{
		if ((tab[i][0] / div) % 2 == 0)
			res++;
		i++;
	}
	return (res);
}

int	*push_to_a(int tab[][4], t_data *data)
{
	while (data->b0 <= data->max)
		pa(tab, data);
	return (*tab);
}

int	*push_to_b(int tab[][4], t_data *data, int rank)
{
	int	gap;
	int	nb;
	int	count_mov;

	count_mov = 0;
	nb = count_nb(tab, data, rank);
	while (nb > 0)
	{
		gap = calc_gap(tab, data, rank);
		while (gap > 0)
		{
			r_col(tab, data, 0);
			count_mov++;
			gap--;
		}
		pb(tab, data);
		count_mov++;
		nb--;
	}
	while (count_mov++ < data->max + 1)
		r_col(tab, data, 0);
	return (*tab);
}
