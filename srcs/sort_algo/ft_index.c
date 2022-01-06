/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:47:52 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:59 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_push_swap *p_swap)
{
	int	bigger;
	int	i;
	int	j;
	int	*newtab;

	newtab = malloc(sizeof(int) * p_swap->a_len);
	if (!newtab)
		return ;
	i = 0;
	while (i < p_swap->a_len)
	{
		j = 0;
		bigger = 0;
		while (j < p_swap->a_len)
		{
			if (p_swap->a[j] > p_swap->a[i])
				bigger++;
			j++;
		}
		newtab[i] = p_swap->a_len - bigger;
		i++;
	}
	free(p_swap->a);
	p_swap->a = newtab;
}
