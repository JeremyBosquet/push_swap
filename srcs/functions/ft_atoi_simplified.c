/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_simplified.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 09:48:19 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:59 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	ft_atoi_simplified(const char *str)
{
	int				i;
	int				neg;
	unsigned int	n;

	i = 0;
	n = 0;
	neg = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg = -1;
	if (i == (int)ft_strlen(str))
		ft_error();
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = (10 * n) + (str[i++] - 48);
		if ((n > 2147483647 && neg == 1) || (n > 2147483648 && neg == -1))
			ft_error();
	}
	if (i == 0 || i != (int)ft_strlen(str))
		ft_error();
	return ((int)n * neg);
}
