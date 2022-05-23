/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:17:22 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 15:21:56 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*s_col(int tab[][4], t_data *data, int col)
{
	int	temp;

	temp = tern((col == 0), tab[data->a0][col], tab[data->b0][col]);
	if (col == 0)
	{
		tab[data->a0][col] = tab[data->a0 + 1][col];
		tab[data->a0 + 1][col] = temp;
	}
	else
	{
		tab[data->b0][col] = tab[data->b0 + 1][col];
		tab[data->b0 + 1][col] = temp;
	}
	data->counter++;
	if (col == 0)
		write(1, "sa\n", 3);
	else
		write(1, "sb\n", 3);
	return (tab[col]);
}

int	*r_col(int tab[][4], t_data *data, int col)
{
	int	temp;
	int	i;

	temp = tern((col == 0), tab[data->a0][col], tab[data->b0][col]);
	i = tern((col == 0), data->a0, data->b0);
	while (i < data->max)
	{
		tab[i][col] = tab[i + 1][col];
		i++;
	}
	tab[data->max][col] = temp;
	data->counter++;
	if (col == 0)
		write(1, "ra\n", 3);
	else
		write(1, "rb\n", 3);
	return (tab[col]);
}

int	*rr_col(int tab[][4], t_data *data, int col)
{
	int	temp;
	int	i;

	temp = tab[data->max][col];
	i = data->max;
	while (i > tern((col == 0), data->a0, data->b0))
	{
		tab[i][col] = tab[i - 1][col];
		i--;
	}
	if (col == 0)
		tab[data->a0][col] = temp;
	else
		tab[data->b0][col] = temp;
	data->counter++;
	if (col == 0)
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
	return (tab[col]);
}

int	tern(int i, int rtrue, int rfalse)
{
	if (i)
		return (rtrue);
	return (rfalse);
}
