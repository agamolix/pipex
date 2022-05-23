/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:30:12 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 13:30:25 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*case2(int tab[][4], t_data *data, int col)
{
	int	a;
	int	b;

	if (col == 0)
	{
		a = data->a0;
		b = data->a0 + 1;
		if (tab[a][0] > tab[b][0])
			s_col(tab, data, 0);
	}
	else
	{
		a = data->b0;
		b = data->b0 + 1;
		if (tab[a][1] < tab[b][1])
			s_col(tab, data, 1);
	}
	return (tab[0]);
}

int	*case3(int tab[][4], t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->a0;
	b = data->a0 + 1;
	c = data->a0 + 2;
	if (tab[a][0] < tab[c][0] && tab[b][0] > tab[c][0])
	{
		s_col(tab, data, 0);
		r_col(tab, data, 0);
	}
	if (tab[a][0] > tab[b][0] && tab[a][0] < tab[c][0])
		s_col(tab, data, 0);
	if (tab[c][0] < tab[a][0] && tab[c][0] > tab[b][0])
		r_col(tab, data, 0);
	if (tab[a][0] > tab[c][0] && tab[a][0] < tab[b][0])
		rr_col(tab, data, 0);
	if (tab[b][0] < tab[a][0] && tab[b][0] > tab[c][0])
	{
		r_col(tab, data, 0);
		s_col(tab, data, 0);
	}
	return (tab[0]);
}

int	*case3_inv(int tab[][4], t_data *data)
{
	int	a;
	int	b;
	int	c;

	a = data->b0;
	b = data->b0 + 1;
	c = data->b0 + 2;
	if (tab[a][1] > tab[c][1] && tab[b][1] < tab[c][1])
	{
		s_col(tab, data, 1);
		r_col(tab, data, 1);
	}
	if (tab[a][1] < tab[b][1] && tab[a][1] > tab[c][1])
		s_col(tab, data, 1);
	if (tab[c][1] > tab[a][1] && tab[c][1] < tab[b][1])
		r_col(tab, data, 1);
	if (tab[a][1] < tab[c][1] && tab[a][1] > tab[b][1])
		rr_col(tab, data, 1);
	if (tab[b][1] > tab[a][1] && tab[b][1] < tab[c][1])
	{
		r_col(tab, data, 1);
		s_col(tab, data, 1);
	}
	return (tab[0]);
}

int	*case6(int tab[][4], t_data *data)
{
	while (data->a0 < data->max - 2)
		pb_min(tab, data, data->max - 2);
	case3(tab, data);
	if (data->max - 2 == 2)
	{
		case2(tab, data, 1);
		pa(tab, data);
	}
	if (data->max - 2 == 3)
	{
		case3_inv(tab, data);
		pa(tab, data);
		pa(tab, data);
	}
	pa(tab, data);
	return (tab[0]);
}

int	*case_max6(int tab[][4], t_data *data)
{
	if (data->max == 1)
		case2(tab, data, 0);
	else if (data->max == 2)
		case3(tab, data);
	else
		case6(tab, data);
	return (tab[0]);
}
