/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_actions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:20:47 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/02 16:25:18 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	is_empty(t_node *node)
{
	return (!node);
}

int	stack_size(t_node *node)
{
	int		i;
	t_node	*tmp;

	i = 0;
	tmp = node;
	if (tmp == NULL)
		return (0);
	while (tmp != NULL)
	{
		i++;
		tmp = tmp -> next;
	}
	return (i);
}

int	find_min(t_node *node)
{
	t_node	*tmp;
	int		min;

	tmp = node;
	min = tmp -> value;
	if (!tmp)
		return (0);
	while (tmp != NULL)
	{
		if (tmp -> value < min)
			min = tmp -> value;
		tmp = tmp -> next;
	}
	return (min);
}

int	elemindex(int elem, t_node **node)
{
	int		index;
	t_node	*tmp;

	index = 0;
	tmp = *node;
	while (tmp != NULL)
	{
		if (tmp -> value == elem)
			return (index);
		index++;
		tmp = tmp -> next;
	}
	return (-1);
}

void	min_to_top(t_node **a)
{
	int	min;
	int	index;

	min = find_min(*a);
	index = elemindex(min, a);
	if (index <= stack_size(*a) / 2)
	{
		while (index--)
			ra(a, 0);
	}
	else
	{
		while (index++ != stack_size(*a))
			rra(a, 0);
	}
}
