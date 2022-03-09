/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:26:14 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/02 16:37:42 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sort2(t_node **a)
{
	if (*a == NULL)
		return ;
	if ((*a)-> value > (*a)-> next -> value)
		sa(a, 0);
}

void	sort3(t_node **a)
{
	if (((*a)-> next -> next -> value > (*a)-> value)
		&& ((*a)-> value > (*a)-> next -> value))
		sa(a, 0);
	else if (((*a)-> next -> next -> value < (*a)-> next -> value)
		&& ((*a)-> next -> value < (*a)-> value))
	{
		sa(a, 0);
		rra(a, 0);
	}
	else if (((*a)-> next -> value < (*a)-> next -> next -> value)
		&& ((*a)-> next -> next -> value < (*a)-> value))
		ra(a, 0);
	else if (((*a)-> value < (*a)-> next -> next -> value)
		&& ((*a)-> next -> next -> value < (*a)-> next -> value))
	{
		sa(a, 0);
		ra(a, 0);
	}
	else if (((*a)-> next -> value > (*a)-> value)
		&& ((*a)-> value > (*a)-> next -> next -> value))
		rra(a, 0);
	else
		return ;
}

void	sort4(t_node **a, t_node **b)
{
	if (*a == NULL)
		return ;
	min_to_top(a);
	pb(a, b);
	sort3(a);
	pa(a, b);
}

void	sort5(t_node **a, t_node **b)
{
	if (*a == NULL)
		return ;
	min_to_top(a);
	pb(a, b);
	min_to_top(a);
	pb(a, b);
	sort3(a);
	pa(a, b);
	pa(a, b);
}

void	choose(t_node **a, t_node **b, int argc)
{
	int	size;

	size = stack_size(*a);
	if (size == 1)
		return ;
	else if (size == 2)
		sort2(a);
	else if (size == 3)
		sort3(a);
	else if (size == 4)
		sort4(a, b);
	else if (size == 5)
		sort5(a, b);
	else if (size >= 6 && size <= 500)
		big_sort(a, b, argc - 1);
}
