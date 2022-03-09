/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:38:26 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/02 16:44:32 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node {
	int				value;
	struct s_node	*next;
}	t_node;

typedef struct s_merge {
	int	i;
	int	j;
	int	k;
	int	n1;
	int	n2;
}	t_merge;

typedef struct s_sort {
	int	i;
	int	point;
	int	len;
	int	index;
}	t_sort;

void	push(int val, t_node **node);
void	push_end(int val, t_node **node);
int		pop(t_node **node);
int		pop_end(t_node **node);
void	print(t_node *node);
int		is_empty(t_node *node);
int		stack_size(t_node *node);
int		find_min(t_node *node);
int		elemindex(int elem, t_node **node);
int		getelem(t_node *node, int n);
void	min_to_top(t_node **a);
void	sa(t_node **a, int flag);
void	sb(t_node **b, int flag);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a, int flag);
void	rb(t_node **b, int flag);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a, int flag);
void	rrb(t_node **b, int flag);
void	rrr(t_node **a, t_node **b);
void	sort2(t_node **a);
void	sort3(t_node **a);
void	sort4(t_node **a, t_node **b);
void	sort5(t_node **a, t_node **b);
void	choose(t_node **a, t_node **b, int argc);
int		invalid_arg(int argc, char **argv);
int		ft_atoi(char *str);
int		invalid_list(t_node *node);
int		is_sorted(t_node *node);
void	quickSort(int *arr, int left, int right);
int		getelem(t_node *node, int n);
void	big_sort(t_node **a, t_node **b, int n);
void	sortmerge(int arr[], int l, int r);
void	freelist(t_node **node);
#endif
