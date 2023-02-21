/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 23:49:29 by abel-bou          #+#    #+#             */
/*   Updated: 2022/05/15 17:02:57 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst)
{
	t_list	*st;

	st = lst;
	while (st->next)
	{
		if (st->content > st->next->content)
			return (0);
		st = st->next;
	}
	return (1);
}

int	position(t_list **stack, int num)
{
	t_list	*st;
	int		i;

	i = 0;
	st = *stack;
	while (st)
	{
		if (st->index == num)
			break ;
		st = st->next;
		i++;
	}
	return (i);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if (check_error(argc, argv) || argc == 1)
		return (0);
	creat_list(&a, argc, argv);
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			swap_a_b(&a, 'a');
		else
		{
			if (ft_lstsize(a) <= 100)
				algo_more5(&a, &b, 3);
			else
				algo_more5(&a, &b, 5);
		}
	}
	return (0);
}
