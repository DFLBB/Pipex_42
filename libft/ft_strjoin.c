/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:21:39 by dlanzas           #+#    #+#             */
/*   Updated: 2023/05/17 18:08:54 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joins;
	int		c;

	c = 0;
	if (!s1 || !s2)
		return (NULL);
	joins = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!joins)
		(free(joins), joins = NULL, perror("malloc"), exit(errno));
	while (*s1 != '\0')
	{
		joins[c] = *s1;
		c++;
		s1++;
	}
	while (*s2 != '\0')
	{
		joins[c] = *s2;
		c++;
		s2++;
	}
	if ((*s1 == '\0' && *s2 == '\0'))
		joins[c] = '\0';
	return (joins);
}
