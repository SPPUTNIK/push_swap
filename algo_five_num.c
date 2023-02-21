/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_five_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 18:20:17 by abel-bou          #+#    #+#             */
/*   Updated: 2022/05/15 14:37:52 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case3_4_5(t_list **a)
{
	t_list	*st;

	st = *a;
	if (st->content > st->next->content
		&& st->content > st->next->next->content
		&& st->next->content < st->next->next->content)
		rotate_a_b(a, 'a');
	else if (st->content < st->next->content
		&& st->content < st->next->next->content
		&& st->next->content > st->next->next->content)
	{
		swap_a_b(a, 'a');
		rotate_a_b(a, 'a');
	}
	else if (st->content < st->next->content
		&& st->content > st->next->next->content
		&& st->next->content > st->next->next->content)
		reverse_rotate(a, 'a');
	else
		return ;
}

void	algo_three_num(t_list **a)
{
	t_list	*st;

	st = *a;
	if (st->content > st->next->content && st->content < st->next->next->content
		&& st->next->content < st->next->next->content)
		swap_a_b(a, 'a');
	if (st->content > st->next->content
		&& st->content > st->next->next->content
		&& st->next->content > st->next->next->content)
	{
		swap_a_b(a, 'a');
		reverse_rotate(a, 'a');
	}
	case3_4_5(a);
	return ;
}

void	algo_five_num(t_list **a, t_list **b)
{
	int	tmp;
	int	i;

	i = 0;
	while (ft_lstsize(*a) > 3)
	{
		tmp = min_index(a);
		if (position(a, tmp) <= ft_lstsize(*a) / 2 + 1)
			while ((*a)->index != tmp)
				rotate_a_b(a, 'a');
		else
			while ((*a)->index != tmp)
				reverse_rotate(a, 'a');
		push_a_b(a, b, 'b');
		i++;
	}
	algo_three_num(a);
	while (i--)
		push_a_b(b, a, 'a');
}
