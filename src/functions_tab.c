/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:30:43 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 13:31:08 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*convert_to_rank(int tab[][4], t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data->max)
	{
		while (tab[i][0] != tab[j][2])
			j++;
		tab[i][0] = convert_to_bin(j);
		i++;
		j = 0;
	}
	return (tab[0]);
}

int	is_sorted(int tab[][4], t_data *data)
{
	int	i;

	i = 1;
	while (i <= data->max)
	{
		if (tab[i][0] < tab[i - 1][0])
			return (0);
		i++;
	}
	return (1);
}

int	*pb_min(int tab[][4], t_data *data, int nb)
{
	int	max_nb;
	int	i;
	int	gap;

	if (nb == 1)
		max_nb = 0;
	else if (nb == 2)
		max_nb = 1;
	else
		max_nb = 10;
	i = 0;
	gap = -1;
	while (gap < 0)
	{
		if (tab[i][0] <= max_nb)
			gap = i - data->a0;
		i++;
	}
	while (gap > 0)
	{
		r_col(tab, data, 0);
		gap--;
	}	
	pb(tab, data);
	return (tab[0]);
}
