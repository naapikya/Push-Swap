/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:14:02 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/02 16:14:39 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	pa(t_node **a, t_node **b)
{
	if (*b == NULL)
		return ;
	push(pop(b), a);
	write(1, "pa\n", 3);
}

void	pb(t_node **a, t_node **b)
{
	if (*a == NULL)
		return ;
	push(pop(a), b);
	write(1, "pb\n", 3);
}
