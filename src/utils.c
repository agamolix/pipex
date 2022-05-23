/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:25:59 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 15:27:26 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	calc_div(int rank)
{
	int	i;
	int	div;

	i = 0;
	div = 1;
	while (i < rank)
	{
		div = div * 10;
		i++;
	}
	return (div);
}

int	calc_gap(int tab[][4], t_data *data, int rank)
{
	int	i;
	int	gap;

	i = 0;
	gap = -1;
	while (gap < 0)
	{
		if ((tab[i][0] / calc_div(rank)) % 10 == 0)
			gap = i - data->a0;
		i++;
	}
	return (gap);
}

int	convert_to_bin(int nb)
{
	int	res;
	int	mult;

	if (nb == 0)
		return (0);
	res = 0;
	mult = 1;
	while (nb > 0)
	{
		res = res + (nb % 2) * mult;
		nb = nb / 2;
		mult *= 10;
	}
	return (res);
}
