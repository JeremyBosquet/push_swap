/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 11:20:07 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:02:24 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_a(int	*a, t_push_swap *p_swap)
{
	int	i;

	i = 0;
	if (!a)
		return ;
	while (i < p_swap->a_len)
	{
		ft_putnbr_fd(a[i], 1);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n-\na\n", 6);
}

void	ft_print_b(int	*b, t_push_swap *p_swap)
{
	int	i;

	i = 0;
	if (!b)
		return ;
	while (i < p_swap->b_len)
	{
		ft_putnbr_fd(b[i], 1);
		write(1, "\n", 1);
		i++;
	}
	write(1, "\n-\nb\n", 6);
}

void	ft_print_ab(int *a, int	*b, t_push_swap *p_swap)
{
	int	i;

	i = 0;
	if (!a || !b)
		return ;
	write(1, "\n", 1);
	while (i < p_swap->a_len || i < p_swap->b_len)
	{
		if (i < p_swap->a_len)
			ft_putnbr_fd(a[i], 1);
		else
			write(1, " ", 1);
		write(1, " | ", 3);
		if (i < p_swap->b_len)
			ft_putnbr_fd(b[i], 1);
		write(1, "\n", 1);
		i++;
	}
	write(1, "-----\na   b\n\n", 14);
}
