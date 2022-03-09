/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_actions1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:19:05 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/02 16:20:41 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push(int val, t_node **node)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof (t_node));
	if (!new)
		return ;
	new->value = val;
	new->next = *node;
	*node = new;
}

void	push_end(int val, t_node **node)
{
	t_node	*tmp;
	t_node	*new;

	new = (t_node *)malloc(sizeof (t_node));
	tmp = *node;
	if (!new)
		return ;
	new -> next = NULL;
	new -> value = val;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp -> next = new;
}

int	pop(t_node **node)
{
	int		ret;
	t_node	*tmp;

	tmp = *node;
	if (tmp == NULL)
		return (0);
	ret = tmp -> value;
	*node = tmp -> next;
	free (tmp);
	return (ret);
}

int	pop_end(t_node **node)
{
	int		ret;
	t_node	*tmp;
	t_node	*del;

	tmp = *node;
	if (tmp == NULL)
		return (0);
	if (tmp -> next == NULL)
	{
		ret = tmp -> value;
		free (tmp);
		*node = NULL;
		return (ret);
	}
	while (tmp -> next -> next != NULL)
		tmp = tmp -> next;
	del = tmp -> next;
	ret = del -> value;
	tmp -> next = NULL;
	free (del);
	return (ret);
}

void	print(t_node *node)
{
	t_node	*tmp;

	tmp = node;
	if (tmp == NULL)
		printf("Stack is empty\n");
	else
	{
		while (tmp != NULL)
		{
			if (tmp -> next != NULL)
				printf("%d, ", tmp->value);
			else
				printf("%d", tmp->value);
			tmp = tmp -> next;
		}
	}
}
