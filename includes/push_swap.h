/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:21:57 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:01:54 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include "libft.h"

typedef struct s_push_swap
{
	int	*a;
	int	*b;
	int	a_len;
	int	b_len;
}	t_push_swap;

int		is_sort(t_push_swap *p_swap);
void	ft_error(void);

//PARSING

int		ft_check_tab(int *tab, int len);
void	ft_parse_args(int argc, char **argv, t_push_swap *p_swap);

//PRINT

void	ft_print_a(int	*a, t_push_swap *p_swap);
void	ft_print_b(int	*b, t_push_swap *p_swap);
void	ft_print_ab(int *a, int	*b, t_push_swap *p_swap);

//FUNCTIONS
void	ft_sa(t_push_swap *p_swap);
void	ft_sb(t_push_swap *p_swap);
void	ft_ss(t_push_swap *p_swap);
void	ft_pa(t_push_swap *p_swap);
void	ft_pb(t_push_swap *p_swap);
void	ft_rra(t_push_swap *p_swap);
void	ft_rrb(t_push_swap *p_swap);
void	ft_rrr(t_push_swap *p_swap);
void	ft_ra(t_push_swap *p_swap);
void	ft_rb(t_push_swap *p_swap);
void	ft_rr(t_push_swap *p_swap);
int		ft_itoi_base(int n, char *base, int s);
int		ft_findmax(int *tab, int len);
int		ft_atoi_simplified(const char *str);
char	*ft_strjoin_free_space(char *s1, char *s2);
void	ft_free_2tab_tab(char	**tab, char *tab2);
int		ft_strlen_2tab(char	**str);

//INDEX
void	ft_index(t_push_swap *p_swap);

//SORT
void	select_rotate(t_push_swap *p_swap, char lst, int searched);
void	ft_select_sort(t_push_swap *p_swap);
void	hard_sort_2(t_push_swap *p_swap);
void	hard_sort_3(t_push_swap *p_swap);
void	hard_sort_5(t_push_swap *p_swap, int i, int start);
void	radix_base(t_push_swap *p_swap, char *base);

#endif