/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 11:24:29 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:59 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_select_sort(t_push_swap *p_swap)
{
	if (p_swap->a_len == 2)
		hard_sort_2(p_swap);
	else if (p_swap->a_len == 3)
		hard_sort_3(p_swap);
	else if (p_swap->a_len <= 5)
		hard_sort_5(p_swap, 0, 1);
	else if (p_swap->a_len <= 200)
		radix_base(p_swap, "0123");
	else
		radix_base(p_swap, "012");
}

static void	select_rotate_b(t_push_swap *p_swap, int searched)
{
	int	i;

	i = 0;
	while (i < p_swap->b_len)
	{
		if (p_swap->b[i] == searched)
		{
			if (i > p_swap->b_len / 2)
				ft_rrb(p_swap);
			else
				ft_rb(p_swap);
			return ;
		}
		i++;
	}
}

void	select_rotate(t_push_swap *p_swap, char lst, int searched)
{
	int	i;

	i = 0;
	if (lst == 'a')
	{
		while (i < p_swap->a_len)
		{
			if (p_swap->a[i] == searched)
			{
				if (i > p_swap->a_len / 2)
					ft_rra(p_swap);
				else
					ft_ra(p_swap);
				return ;
			}
			i++;
		}
	}
	else if (lst == 'b')
	{
		select_rotate_b(p_swap, searched);
	}
}
