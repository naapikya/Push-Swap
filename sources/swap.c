/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:11:33 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/02 16:13:19 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	sa(t_node **a, int flag)
{
	int		tmp;
	t_node	*temp;

	temp = *a;
	if (temp == NULL || temp ->next == NULL)
		return ;
	tmp = temp -> value;
	temp -> value = temp -> next -> value;
	temp -> next -> value = tmp;
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_node **b, int flag)
{
	int		tmp;
	t_node	*temp;

	temp = *b;
	if (temp == NULL || temp ->next == NULL)
		return ;
	tmp = temp -> value;
	temp -> value = temp -> next -> value;
	temp -> next -> value = tmp;
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	sa(a, 1);
	sb(b, 1);
	write(1, "ss\n", 3);
}
