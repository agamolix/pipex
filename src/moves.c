/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:22:14 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 15:23:54 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*ss(int tab[][4], t_data *data)
{
	s_col(tab, data, 0);
	s_col(tab, data, 0);
	data->counter++;
	write(1, "ss\n", 3);
	return (tab[0]);
}

int	*rr(int tab[][4], t_data *data)
{
	r_col(tab, data, 0);
	r_col(tab, data, 1);
	data->counter++;
	write (1, "rr\n", 3);
	return (tab[0]);
}

int	*rrr(int tab[][4], t_data *data)
{
	rr_col(tab, data, 0);
	rr_col(tab, data, 1);
	data->counter++;
	write(1, "rrr\n", 4);
	return (tab[0]);
}

int	*pa(int tab[][4], t_data *data)
{
	tab[data->a0 - 1][0] = tab[data->b0][1];
	tab[data->b0][1] = 0;
	data->a0 = data->a0 - 1;
	data->b0 = data->b0 + 1;
	data->counter++;
	write(1, "pa\n", 3);
	return (tab[0]);
}

int	*pb(int tab[][4], t_data *data)
{
	tab[data->b0 - 1][1] = tab[data->a0][0];
	tab[data->a0][0] = 0;
	data->b0 = data->b0 - 1;
	data->a0 = data->a0 + 1;
	data->counter++;
	write(1, "pb\n", 3);
	return (tab[0]);
}
