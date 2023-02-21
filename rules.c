/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 23:03:56 by abel-bou          #+#    #+#             */
/*   Updated: 2022/05/15 14:18:46 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a_b(t_list **stack_a_b, char c)
{
	int		swap;
	int		index;
	t_list	*tmp;

	if (!stack_a_b)
		return ;
	swap = (*stack_a_b)->content;
	index = (*stack_a_b)->index;
	tmp = (*stack_a_b)->next;
	(*stack_a_b)->content = tmp->content;
	tmp->content = swap;
	tmp->index = index;
	(*stack_a_b)->next = tmp;
	write(1, "s", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	rotate_a_b(t_list **stack_a_b, char c)
{
	t_list	*tmp;
	t_list	*last;

	last = ft_lstnew((*stack_a_b)->content, (*stack_a_b)->index);
	tmp = *stack_a_b;
	ft_lstadd_back(stack_a_b, last);
	*stack_a_b = (*stack_a_b)->next;
	free(tmp);
	write(1, "r", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	reverse_rotate(t_list **stack_a_b, char c)
{
	t_list	*tmp;
	t_list	*last;

	tmp = *stack_a_b;
	last = ft_lstlast(*stack_a_b);
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a_b, ft_lstnew(last->content, last->index));
	free(last);
	write(1, "rr", 2);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	push_a_b(t_list **stack1, t_list **stack2, char c)
{
	t_list	*tmp;
	int		index;

	tmp = *stack1;
	index = (*stack1)->index;
	*stack1 = (*stack1)->next;
	ft_lstadd_front(stack2, ft_lstnew(tmp->content, index));
	free(tmp);
	write(1, "p", 1);
	write(1, &c, 1);
	write(1, "\n", 1);
}

void	creat_list(t_list **a, int ac, char **av)
{
	int	i;

	*a = ft_lstnew(ft_atoi(av[1]), 0);
	i = 2;
	while (i < ac)
	{
		ft_lstadd_back(a, ft_lstnew(ft_atoi(av[i]), 0));
		i++;
	}
}
