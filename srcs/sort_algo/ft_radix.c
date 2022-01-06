/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:05:33 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:59 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	convert(t_push_swap *p_swap, char *base)
{
	int	i;

	i = 0;
	while (i < p_swap->a_len)
	{
		p_swap->a[i] = ft_itoi_base(p_swap->a[i], base, 1);
		i++;
	}
}

static int	ft_lstfindik(int *tab, int d, int k, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (((tab[i] / d) % 10) == k)
			return (1);
		i++;
	}
	return (0);
}

static void	radix_base_pt2(t_push_swap *p_swap, int k, int i, int d)
{
	int	lenmax;

	d *= 10;
	while (k >= 0)
	{
		lenmax = p_swap->b_len;
		i = 0;
		if (ft_lstfindik(p_swap->b, d, k, p_swap->b_len))
		{
			while (i < lenmax)
			{
				if (((p_swap->b[0] / d) % 10) == k)
					ft_pa(p_swap);
				else
					ft_rb(p_swap);
				i++;
			}
		}
		k--;
	}
}

static void	radix_base_pt1(t_push_swap *p_swap, int k, int i, int d)
{
	int	lenmax;
	int	j;

	j = k;
	k = 0;
	while (j >= 0)
	{
		lenmax = p_swap->a_len;
		i = 0;
		if (ft_lstfindik(p_swap->a, d, k, p_swap->a_len))
		{
			while (i < lenmax)
			{
				if (((p_swap->a[0] / d) % 10) == k)
					ft_pb(p_swap);
				else
					ft_ra(p_swap);
				i++;
			}
		}
		k++;
		j--;
	}
}

void	radix_base(t_push_swap *p_swap, char *base)
{
	int	i;
	int	d;

	d = 1;
	i = 0;
	convert(p_swap, base);
	while (ft_findmax(p_swap->a, p_swap->a_len) / d > 0)
	{
		radix_base_pt1(p_swap, ft_strlen(base) - 1, i, d);
		radix_base_pt2(p_swap, ft_strlen(base) - 1, i, d);
		d *= 100;
	}
}
