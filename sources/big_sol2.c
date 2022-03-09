/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 13:19:29 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/07 13:19:33 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	big_sort2(t_node **a, t_node **b, t_sort *s, int *n)
{
	s -> i = 0;
	while (s -> i < *n)
	{
		if ((*a)->value > s -> point
			&& getelem(*a, stack_size(*a) - 1) < s -> point)
			rra(a, 0);
		else if ((*a)->value < s -> point)
		{
			pb(a, b);
			if (stack_size(*b) >= 2)
			{
				if ((*b)->value < (*b)->next->value)
					sb(b, 0);
			}
			s -> len++;
		}
		else if (stack_size(*b) > 1 && (*b)->value < (*b)->next->value)
			rr(a, b);
		else
			ra(a, 0);
		s -> i++;
	}
}

void	big_sort3(t_node **a, t_node **b, t_sort *s)
{
	while (stack_size(*b))
	{
		s -> i = 0;
		s -> point = (*b)-> value;
		while (++s -> i < stack_size(*b))
		{
			if (getelem(*b, s -> i) > s -> point)
			{
				s -> point = getelem(*b, s -> i);
				s -> index = s -> i;
			}
		}
		if (s -> index <= stack_size(*b) / 2)
		{
			s -> index++;
			while (--s -> index)
				rb(b, 0);
		}
		else
		{
			while (s -> index++ < stack_size(*b))
				rrb(b, 0);
		}
		pa(a, b);
	}
}

void	big_sort4(t_node **a, t_node **b, t_sort *s, int *n)
{
	if (stack_size(*a) == 3)
		sort3(a);
	if (stack_size(*a) > 3)
		big_sort(a, b, (*n - s -> len));
}

void	big_sort(t_node **a, t_node **b, int n)
{
	int		*temp_arr;
	t_node	*ptr;
	t_sort	s;

	s.i = 0;
	s.len = 0;
	ptr = *a;
	s.index = 0;
	temp_arr = malloc(n * sizeof(int));
	if (!temp_arr)
		return ;
	while (ptr != NULL)
	{
		temp_arr[s.i] = ptr->value;
		ptr = ptr->next;
		s.i++;
	}
	sortmerge(temp_arr, 0, n - 1);
	s.point = temp_arr[n / 3];
	big_sort2(a, b, &s, &n);
	big_sort4(a, b, &s, &n);
	big_sort3(a, b, &s);
	free(temp_arr);
}
