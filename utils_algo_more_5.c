/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_algo_more_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 23:03:35 by abel-bou          #+#    #+#             */
/*   Updated: 2022/05/14 21:58:16 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *x, int *y)
{
	int	z;

	z = *x;
	*x = *y;
	*y = z;
}

int	*put_htem_in_arr(t_list **t_stack)
{
	t_list	*st;
	int		*arr;
	int		i;
	int		size;

	st = (*t_stack);
	size = ft_lstsize(st);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (0);
	i = 0;
	while (i < size)
	{
		arr[i] = st->content;
		st = st->next;
		i++;
	}
	return (arr);
}

int	*sort_them(t_list **stack)
{
	t_list	*st;
	int		*arr;
	int		i;
	int		j;
	int		size;

	st = (*stack);
	arr = put_htem_in_arr(&st);
	size = ft_lstsize(st);
	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
				ft_swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	return (arr);
}

void	index_them(t_list **stack)
{
	t_list	*st;
	int		*arr;
	int		size;
	int		i;
	int		j;

	st = (*stack);
	size = ft_lstsize(st);
	arr = sort_them(&st);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size && st)
		{
			if (arr[j] == st->content)
			{
				st->index = j;
				st = st->next;
			}
			j++;
		}
		i++;
	}
	free(arr);
}

int	min_index(t_list **stack)
{
	t_list	*i;
	int		min;

	i = *stack;
	min = i->index;
	while (i)
	{
		if (min > i->index)
			min = i->index;
		i = i->next;
	}
	return (min);
}
