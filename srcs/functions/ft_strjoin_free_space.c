/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free_space.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbosquet <jbosquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:35:17 by jbosquet          #+#    #+#             */
/*   Updated: 2022/01/05 14:07:59 by jbosquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin_free_space(char *s1, char *s2)
{
	char	*newstr;
	size_t	i;
	size_t	j;

	j = -1;
	i = -1;
	newstr = NULL;
	if (s1 && s2)
	{
		newstr = (char *)ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 2),
				sizeof(char));
		if (!newstr)
			return (NULL);
		while (s1 && s1[++j])
			newstr[++i] = s1[j];
		j = -1;
		newstr[++i] = ' ';
		while (s2 && s2[++j])
			newstr[++i] = s2[j];
		newstr[++i] = '\0';
		free(s1);
		return (newstr);
	}
	return (NULL);
}
