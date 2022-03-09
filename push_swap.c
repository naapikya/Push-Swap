/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:22:56 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/07 12:51:53 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main2(int argc, char *argv[])
{
	if (invalid_arg(argc, argv))
	{
		write(1, "Error\n", 7);
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (!main2(argc, argv))
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		push(ft_atoi(argv[i]), &a);
		i--;
	}
	if (invalid_list(a))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!is_sorted(a))
		choose(&a, &b, argc);
	freelist(&a);
	freelist(&b);
}
