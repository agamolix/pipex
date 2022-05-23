/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:32:08 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 14:12:39 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h" 

int	*init_tab(int tab[][4], t_data *data, int argc, char **argv)
{
	init_tab_ab(tab, argc, argv);
	copy_a_to_cd(tab, data);
	sort_c(tab, data);
	return (tab[0]);
}

int	*init_tab_ab(int tab[][4], int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		tab[i][0] = atoi_int(argv[i + 1]);
		tab[i][1] = 0;
		i++;
	}
	return (tab[0]);
}

int	*copy_a_to_cd(int tab[][4], t_data *data)
{
	int	i;

	i = 0;
	while (i <= data->max)
	{
		tab[i][2] = tab[i][0];
		tab[i][3] = tab[i][0];
		i++;
	}
	data->c0 = data->a0;
	return (tab[0]);
}

int	*sort_c(int tab[][4], t_data *data)
{
	int	i;
	int	temp;

	i = data->c0;
	while (i < data->max)
	{
		if (tab[i][2] > tab[i + 1][2])
		{
			temp = tab[i][2];
			tab[i][2] = tab[i + 1][2];
			tab[i + 1][2] = temp;
			i = data->c0 - 1;
		}
		i++;
	}
	return (tab[0]);
}

void	init_data(t_data *data, int argc)
{
	data->max = argc - 2;
	data->a0 = 0;
	data->b0 = argc - 1;
	data->counter = 0;
}
