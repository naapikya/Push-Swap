/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:56:19 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/03 09:56:22 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			result = result * 10 + (str[i] - '0');
		else
			return (result * sign);
		i++;
	}
	return (result * sign);
}

int	invalid_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-'
				&& (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
			{
				j++;
				continue ;
			}
			else if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				return (1);
			if ((ft_atoi(argv[i]) < -2147483648)
				|| (ft_atoi(argv[i]) > 2147483647))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	invalid_list(t_node *node)
{
	t_node	*tmp;
	t_node	*run;

	tmp = node;
	while (tmp != NULL)
	{
		run = tmp -> next;
		while (run != NULL)
		{
			if (tmp -> value == run -> value)
				return (1);
			run = run -> next;
		}
		tmp = tmp -> next;
	}
	return (0);
}

int	is_sorted(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	while (tmp -> next != NULL)
	{
		if (tmp -> value > tmp -> next -> value)
			return (0);
		tmp = tmp -> next;
	}
	return (1);
}

void	freelist(t_node **node)
{
	t_node	*tmp;
	t_node	*prev;

	tmp = *node;
	if (!tmp)
		return ;
	if (tmp -> next == NULL)
	{
		free(tmp);
		*node = NULL;
		return ;
	}
	prev = tmp;
	tmp = tmp -> next;
	while (prev != NULL)
	{
		free(prev);
		prev = tmp;
		if (tmp != NULL)
			tmp = tmp -> next;
	}
	*node = NULL;
}
