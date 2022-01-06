/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hardcode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:27:58 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:44 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_sort_2(t_push_swap *p_swap)
{
	if (p_swap->a[0] > p_swap->a[1])
		ft_sa(p_swap);
}

void	hard_sort_3(t_push_swap *p_swap)
{
	if (p_swap->a[0] == 3 && p_swap->a[1] == 1 && p_swap->a[2] == 2)
		ft_ra(p_swap);
	if (p_swap->a[0] == 3 && p_swap->a[1] == 2 && p_swap->a[2] == 1)
	{
		ft_ra(p_swap);
		ft_sa(p_swap);
	}
	if (p_swap->a[0] == 2 && p_swap->a[1] == 3 && p_swap->a[2] == 1)
	{
		ft_ra(p_swap);
		ft_ra(p_swap);
	}
	if (p_swap->a[0] == 2 && p_swap->a[1] == 1 && p_swap->a[2] == 3)
		ft_sa(p_swap);
	if (p_swap->a[0] == 1 && p_swap->a[1] == 3 && p_swap->a[2] == 2)
	{
		ft_rra(p_swap);
		ft_sa(p_swap);
	}
}

void	hard_sort_5(t_push_swap *p_swap, int i, int start)
{
	int	reverse;

	reverse = -1;
	start = 1;
	while (i < p_swap->a_len)
	{
		while (start <= 3)
		{		
			while (p_swap->a[i] != start && start <= 3)
				select_rotate(p_swap, 'a', start);
			if (p_swap->a[i] == start)
				ft_pb(p_swap);
			else
				select_rotate(p_swap, 'a', start);
			start++;
		}
		if (start == 4)
		{
			hard_sort_2(p_swap);
			while (++reverse < 3)
				ft_pa(p_swap);
		}
		i++;
	}
}
