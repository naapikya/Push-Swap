/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:14:50 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/02 16:15:41 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ra(t_node **a, int flag)
{
	if (*a == NULL)
		return ;
	push_end(pop(a), a);
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_node **b, int flag)
{
	if (*b == NULL)
		return ;
	push_end(pop(b), b);
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	ra(a, 1);
	rb(b, 1);
	write(1, "rr\n", 3);
}
