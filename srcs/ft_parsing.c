/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:34:14 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:02:24 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_tab(int *tab, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 1;
		while (i + j < len)
		{
			if (tab[i + j] == tab[i])
				ft_error();
			j++;
		}
		i++;
	}
	return (1);
}

static int	*ft_convert_char_to_int(char **tab, t_push_swap *p_swap)
{
	int	*result;
	int	i;

	i = 0;
	while (tab[i])
		i++;
	result = malloc(sizeof(int) * i);
	i = -1;
	while (tab[++i])
		result[i] = ft_atoi_simplified(tab[i]);
	p_swap->a_len = i;
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (result);
}

static int	*ft_parse_onearg(char **argv, t_push_swap *p_swap)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(argv[1], ' ');
	if (!tab)
		return (NULL);
	return (ft_convert_char_to_int(tab, p_swap));
}

static int	*ft_parse_multiargs(char **argv, t_push_swap *p_swap)
{
	int		*result;
	char	*joined;
	char	**tab;
	int		i;

	i = 0;
	joined = ft_calloc(sizeof(char), 1);
	if (!joined)
		ft_error();
	while (argv[++i])
		joined = ft_strjoin_free_space(joined, argv[i]);
	tab = ft_split(joined, ' ');
	if (!tab)
		ft_error();
	result = malloc(sizeof(int) * ft_strlen_2tab(tab));
	if (!result)
		ft_error();
	i = -1;
	while (tab[++i])
		result[i] = ft_atoi_simplified(tab[i]);
	p_swap->a_len = i;
	ft_free_2tab_tab(tab, joined);
	return (result);
}

void	ft_parse_args(int argc, char **argv, t_push_swap *p_swap)
{
	if (argc == 2)
		p_swap->a = (ft_parse_onearg(argv, p_swap));
	else
		p_swap->a = (ft_parse_multiargs(argv, p_swap));
	ft_index(p_swap);
}
