/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:07:09 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:59 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse(int r, int d)
{
	int	nbr;

	nbr = 0;
	while (d-- > 0 || r >= 10)
	{
		nbr = nbr * 10 + r % 10;
		r /= 10;
	}
	return (nbr);
}

int	ft_itoi_base(int n, char *base, int s)
{
	int	r;
	int	nbr;
	int	d;
	int	len_base;

	nbr = n;
	len_base = ft_strlen(base);
	if (n < 0)
	{
		nbr = -nbr;
		s = -s;
	}
	d = 1;
	r = nbr;
	while (r >= len_base)
		r /= len_base + 0 * d++;
	r = 0;
	while (nbr >= len_base)
	{
		r = r * 10 + base[nbr % len_base] - 48;
		nbr /= len_base;
	}
	r = r * 10 + base[nbr % len_base] - 48;
	return (reverse(r, d) * s);
}
