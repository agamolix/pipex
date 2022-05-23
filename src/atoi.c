/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atrilles <atrilles@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:17:32 by atrilles          #+#    #+#             */
/*   Updated: 2022/05/23 13:20:29 by atrilles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_long_int(char *str)
{
	if (str == 0 || str_len(str) > 12)
		return (0);
	while (str[0])
	{
		if (str[0] < '0' || str[0] > '9')
			return (0);
		str++;
	}
	return (1);
}

int	is_int(char *str, int len_nb, int sign)
{
	long long int	res;

	res = 0;
	while (len_nb > 0)
	{
		res = res * 10;
		res = res + str[0] - '0';
		if (len_nb != 1)
			str++;
		len_nb--;
	}
	res = res * sign;
	if (res > INT_MAX || res < INT_MIN)
		return (0);
	return (1);
}

int	convert_to_int(char *str, int len_nb, int sign)
{
	long long int	res;

	res = 0;
	while (len_nb > 0)
	{
		res = res * 10;
		res = res + str[0] - '0';
		if (len_nb != 1)
			str++;
		len_nb--;
	}
	res = res * sign;
	return (res);
}

int	is_atoi_int(char *str)
{
	int	sign;
	int	len_nb;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	if (str[0] == 0)
		return (0);
	len_nb = str_len(str);
	if (is_long_int(str) && is_int(str, len_nb, sign))
		return (1);
	return (0);
}

int	atoi_int(char *str)
{
	int	sign;
	int	len_nb;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		str++;
	}
	len_nb = str_len(str);
	return (convert_to_int(str, len_nb, sign));
}
