/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naapikya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 12:50:16 by naapikya          #+#    #+#             */
/*   Updated: 2021/11/07 12:50:57 by naapikya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	getelem(t_node *node, int n)
{
	t_node	*ptr;
	int		count;

	ptr = node;
	count = 0;
	while (ptr != NULL)
	{
		if (count == n)
			return (ptr->value);
		count++;
		ptr = ptr->next;
	}
	return (0);
}

void	merge2(t_merge *norm, int le[], int ri[], int arr[])
{
	norm -> i = 0;
	norm -> j = 0;
	while (norm -> i < norm -> n1 && norm -> j < norm -> n2)
	{
		if (le[norm -> i] <= ri[norm -> j])
		{
			arr[norm -> k] = le[norm -> i];
			norm -> i++;
		}
		else
		{
			arr[norm -> k] = ri[norm -> j];
			norm -> j++;
		}
		norm -> k++;
	}
	while (norm -> i < norm -> n1)
	{
		arr[norm -> k] = le[norm -> i];
		norm -> i++;
		norm -> k++;
	}
}

void	merge3(t_merge *norm, int ri[], int arr[])
{
	while (norm -> j < norm -> n2)
	{
		arr[norm -> k] = ri[norm -> j];
		norm -> j++;
		norm -> k++;
	}
}

void	merge(int arr[], int l, int m, int r)
{
	int		*le;
	int		*ri;
	t_merge	norm;

	norm.n1 = m - l + 1;
	norm.n2 = r - m;
	le = (int *)malloc(norm.n1 * sizeof(int));
	ri = (int *)malloc(norm.n2 * sizeof(int));
	norm.i = 0;
	norm.j = 0;
	while (norm.i < norm.n1)
	{
		le[norm.i] = arr[l + norm.i];
		norm.i++;
	}
	while (norm.j < norm.n2)
	{
		ri[norm.j] = arr[m + 1 + norm.j];
		norm.j++;
	}
	norm.k = l;
	merge2(&norm, le, ri, arr);
	merge3(&norm, ri, arr);
	free(le);
	free(ri);
}

void	sortmerge(int arr[], int l, int r)
{
	int	m;

	if (l < r)
	{
		m = l + (r - l) / 2;
		sortmerge(arr, l, m);
		sortmerge(arr, m + 1, r);
		merge(arr, l, m, r);
	}
}
