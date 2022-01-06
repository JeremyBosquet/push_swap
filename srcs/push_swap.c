/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:21:39 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:02:24 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_push_swap *p_swap)
{
	int	i;

	i = 0;
	while (i < p_swap->a_len - 1)
	{
		if (p_swap->a[i] > p_swap->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	*ft_init_b(t_push_swap *p_swap)
{
	int	*b;

	b = malloc(sizeof(int) * p_swap->a_len);
	if (!b)
		return (NULL);
	p_swap->b_len = 0;
	return (b);
}

int	main(int argc, char **argv)
{
	t_push_swap	p_swap;

	if (argc < 2)
		return (0);
	ft_parse_args(argc, argv, &p_swap);
	if (!ft_check_tab(p_swap.a, p_swap.a_len))
		return (0);
	if (is_sort(&p_swap))
		exit (0);
	p_swap.b = ft_init_b(&p_swap);
	ft_select_sort(&p_swap);
	free(p_swap.a);
	free(p_swap.b);
	exit (0);
}
