/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:32:42 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:59 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_push_swap *p_swap)
{
	int	i;
	int	tmp;

	i = p_swap->a_len;
	if (i > 1)
	{
		tmp = p_swap->a[i - 1];
		while (i > 1)
		{
			p_swap->a[i - 1] = p_swap->a[i - 2];
			i--;
		}
		p_swap->a[0] = tmp;
	}
	write(1, "rra\n", 4);
}

void	ft_rrb(t_push_swap *p_swap)
{
	int	i;
	int	tmp;

	i = p_swap->b_len;
	if (i > 1)
	{
		tmp = p_swap->b[i - 1];
		while (i > 1)
		{
			p_swap->b[i - 1] = p_swap->b[i - 2];
			i--;
		}
		p_swap->b[0] = tmp;
	}
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_push_swap *p_swap)
{
	int	i;
	int	tmp;

	i = p_swap->a_len;
	if (p_swap->a_len > 1 || p_swap->b_len > 1)
	{
		if (i++ > 1)
		{
			tmp = p_swap->a[i - 2];
			while (--i > 0)
				p_swap->a[i] = p_swap->a[i - 1];
			p_swap->a[0] = tmp;
		}
		i = p_swap->b_len;
		if (i++ > 1)
		{
			tmp = p_swap->b[i - 2];
			while (--i > 0)
				p_swap->b[i] = p_swap->b[i - 1];
			p_swap->b[0] = tmp;
		}
		write(1, "rrr\n", 4);
	}
}
