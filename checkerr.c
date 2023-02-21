/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:30:04 by abel-bou          #+#    #+#             */
/*   Updated: 2022/05/14 18:41:11 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	is_number(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (j == 0 && (av[i][0] == '+' || av[i][0] == '-'))
			{
				if (av[i][0] != '+' && av[i][0] != '-')
					return (-1);
			}
			else if (!ft_isdigit(av[i][j]))
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

void	duplicat(int *arr, int ac)
{
	int	i;
	int	j;

	j = 0;
	while (j < ac - 1)
	{
		i = j + 1;
		while (i < ac -1)
		{
			if (arr[j] == arr[i])
			{
				write(1, "Error\n", 6);
				exit(0);
			}
			i++;
		}
		j++;
	}
}

int	convert_argv(int ac, char **av)
{
	int	i;
	int	j;
	int	*arr;

	i = 1;
	j = 0;
	arr = malloc(sizeof(int) * ac);
	if (!arr)
		return (0);
	while (i < ac)
	{
		arr[j] = ft_atoi(av[i]);
		i++;
		j++;
	}
	duplicat(arr, ac);
	free(arr);
	return (0);
}

int	check_error(int ac, char **av)
{
	if (is_number(ac, av) || convert_argv(ac, av))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	return (0);
}
