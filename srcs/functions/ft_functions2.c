/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 01:27:27 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:59 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_push_swap *p_swap)
{
	int	i;
	int	tmp;

	i = 0;
	if (p_swap->a_len > 1)
	{
		tmp = p_swap->a[0];
		while (i < p_swap->a_len - 1)
		{
			p_swap->a[i] = p_swap->a[i + 1];
			i++;
		}
		p_swap->a[p_swap->a_len - 1] = tmp;
		write(1, "ra\n", 3);
	}
}

void	ft_rb(t_push_swap *p_swap)
{
	int	i;
	int	tmp;

	i = 0;
	if (p_swap->b_len > 1)
	{
		tmp = p_swap->b[0];
		while (i < p_swap->b_len - 1)
		{
			p_swap->b[i] = p_swap->b[i + 1];
			i++;
		}
		p_swap->b[p_swap->b_len - 1] = tmp;
		write(1, "rb\n", 3);
	}
}

void	ft_rr(t_push_swap *p_swap)
{
	int	i;
	int	tmp;

	i = -1;
	if (p_swap->a_len > 1 || p_swap->b_len > 1)
	{
		if (p_swap->a_len > 1)
		{
			tmp = p_swap->a[0];
			while (++i < p_swap->a_len - 1)
				p_swap->a[i] = p_swap->a[i + 1];
			p_swap->a[p_swap->a_len - 1] = tmp;
		}
		i = -1;
		if (p_swap->b_len > 1)
		{
			tmp = p_swap->b[0];
			while (++i < p_swap->b_len - 1)
				p_swap->b[i] = p_swap->b[i + 1];
			p_swap->b[p_swap->b_len - 1] = tmp;
		}
		write(1, "rr\n", 3);
	}
}
