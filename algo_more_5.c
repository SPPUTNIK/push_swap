/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_more_5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 02:45:53 by abel-bou          #+#    #+#             */
/*   Updated: 2022/05/15 17:00:03 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	search_index(t_list **st, int index, char c)
{
	if (position(st, index) <= ft_lstsize(*st) / 2 + 1)
		while ((*st)->index != index)
			rotate_a_b(st, c);
	else
		while ((*st)->index != index)
			reverse_rotate(st, c);
}

void	utils_b(t_list **a, t_list **b)
{
	while (ft_lstsize(*b))
	{
		if (ft_lstlast(*a)->index == (*a)->index - 1)
			reverse_rotate(a, 'a');
		else if ((*a)->index - 1 == (*b)->index)
			push_a_b(b, a, 'a');
		else if ((*b)->index < (*a)->index
			&& (*b)->index > ft_lstlast(*a)->index)
		{
			push_a_b(b, a, 'a');
			rotate_a_b(a, 'a');
		}
		else
		{
			search_index(b, (*a)->index - 1, 'b');
			push_a_b(b, a, 'a');
		}
	}
	while (!is_sorted(*a))
		reverse_rotate(a, 'a');
}

void	algo(t_list **a, t_list **b, int d)
{
	t_var	var;
	int		index;
	t_list	*st;

	while (ft_lstsize(*a) > 5)
	{
		var.min = min_index(a);
		var.max = var.min + (ft_lstsize(*a) - 5) / d;
		var.med = (var.min + var.max) / 2;
		st = *a;
		while (st)
		{
			if (st->index >= var.min && st->index <= var.max)
			{
				index = st->index;
				search_index(a, index, 'a');
				push_a_b(a, b, 'b');
				if ((*b)->index <= var.med && ft_lstsize(*b) > 1)
					rotate_a_b(b, 'b');
				st = *a;
			}
			else
				st = st->next;
		}
	}
}

void	algo_more5(t_list **a, t_list **b, int d)
{
	index_them(a);
	algo(a, b, d);
	algo_five_num(a, b);
	ft_lstlast(*a)->index = -1;
	utils_b(a, b);
}
