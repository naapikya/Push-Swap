/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:15:55 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/02 16:17:01 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rra(t_node **a, int flag)
{
	if (*a == NULL)
		return ;
	push(pop_end(a), a);
	if (flag == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_node **b, int flag)
{
	if (*b == NULL)
		return ;
	push(pop_end(b), b);
	if (flag == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	rra(a, 1);
	rrb(b, 1);
	write(1, "rrr\n", 4);
}
