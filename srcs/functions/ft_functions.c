/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:06:03 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:59 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_push_swap *p_swap)
{
	int	tmp;

	if (p_swap->a_len <= 1)
		return ;
	tmp = p_swap->a[0];
	p_swap->a[0] = p_swap->a[1];
	p_swap->a[1] = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_push_swap *p_swap)
{
	int	tmp;

	if (p_swap->b_len <= 1)
		return ;
	tmp = p_swap->b[0];
	p_swap->b[0] = p_swap->b[1];
	p_swap->b[1] = tmp;
	write(1, "sb\n", 3);
}

void	ft_ss(t_push_swap *p_swap)
{
	int	tmpa;
	int	tmpb;

	if (p_swap->a_len <= 1 || p_swap->b_len <= 1)
		return ;
	tmpa = p_swap->a[0];
	p_swap->a[0] = p_swap->a[1];
	p_swap->a[1] = tmpa;
	tmpb = p_swap->b[0];
	p_swap->b[0] = p_swap->b[1];
	p_swap->b[1] = tmpb;
	write(1, "ss\n", 3);
}

void	ft_pb(t_push_swap *p_swap)
{
	int	ia;
	int	i;

	ia = -1;
	i = p_swap->b_len;
	if (!p_swap->a || p_swap->a_len == 0)
		return ;
	if (i > 0)
	{
		while (i > 0)
		{
			p_swap->b[i] = p_swap->b[i - 1];
			i--;
		}
		p_swap->b[0] = p_swap->a[0];
	}
	else
		p_swap->b[p_swap->b_len] = p_swap->a[0];
	p_swap->a_len--;
	while (++ia < p_swap->a_len)
		p_swap->a[ia] = p_swap->a[ia + 1];
	p_swap->b_len++;
	write(1, "pb\n", 3);
}

void	ft_pa(t_push_swap *p_swap)
{
	int	i;
	int	ib;

	i = p_swap->a_len;
	ib = -1;
	if (!p_swap->b || p_swap->b_len == 0)
		return ;
	if (i > 0)
	{
		while (i > 0)
		{
			p_swap->a[i] = p_swap->a[i - 1];
			i--;
		}
		p_swap->a[0] = p_swap->b[0];
	}
	else
		p_swap->a[p_swap->a_len] = p_swap->b[0];
	p_swap->b_len--;
	while (++ib < p_swap->b_len)
		p_swap->b[ib] = p_swap->b[ib + 1];
	p_swap->a_len++;
	write(1, "pa\n", 3);
}
