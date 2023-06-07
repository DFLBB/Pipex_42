/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:29:23 by dlanzas           #+#    #+#             */
/*   Updated: 2023/05/17 15:39:55 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	c;

	c = 0;
	while (s[c] != '\0')
		c++;
	return (c);
}

int	ft_strlen_word_with_quotes(const char *s, char c)
{
	int				count;
	enum e_quotes	quotes;

	quotes = NONE;
	quotes = eval_quotes_state(*s, quotes);
	count = 0;
	if (quotes == NONE)
	{
		while (*s == c)
				s++;
	}
	while (*s != '\0' && (*s != c || quotes != NONE))
	{
		quotes = eval_quotes_state(*s, quotes);
		if (*s == '\'')
			s++;
		else
		{
			count++;
			s++;
			quotes = eval_quotes_state(*s, quotes);
		}
	}
	return (count);
}
