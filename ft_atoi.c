/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 18:55:37 by abel-bou          #+#    #+#             */
/*   Updated: 2022/04/30 02:29:47 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	ft_twentyfive_line(const char *str, int i, int sign)
{
	long long	num;

	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (num * sign > 2147483647 || num * sign < -2147483648)
	{
		write(1, "Error\n", 7);
		exit(0);
	}
	return (num * sign);
}

long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	num;
	int			count;

	i = 0;
	sign = 1;
	count = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' || str[i] == '+')
			count++;
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	num = ft_twentyfive_line(str, i, sign);
	if (count >= 2)
		return (0);
	return (num);
}
