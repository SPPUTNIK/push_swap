/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-bou <abel-bou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:22:19 by abel-bou          #+#    #+#             */
/*   Updated: 2022/05/15 17:05:08 by abel-bou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include  <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct s_var
{
	int		med;
	int		max;
	int		min;
}t_var;

int		check_error(int ac, char **av);
int		is_sorted(t_list *lst);

void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content, int index);
int		ft_lstsize(t_list *list);
t_list	*ft_lstlast(t_list *lst);
void	creat_list(t_list **a, int ac, char **av);
long	ft_atoi(char *str);
void	swap_a_b(t_list **stack_a_b, char c);
void	rotate_a_b(t_list **stack_a_b, char c);
void	reverse_rotate(t_list **stack_a_b, char c);
void	push_a_b(t_list **stack1, t_list **stack2, char c);
void	algo_five_num(t_list **a, t_list **b);
void	algo_more5(t_list **a, t_list **b, int d);
int		position(t_list **stack, int num);
void	index_them(t_list **stack);
int		min_index(t_list **stack);

#endif