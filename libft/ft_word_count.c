/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:50:28 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/05/17 18:37:10 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	eval_quotes_state(const char c, const short quotes)
{
	if (c == '\'' && quotes == NONE)
		return (SINGLES);
	else if (c == '\'' && quotes == SINGLES)
		return (NONE);
	return (quotes);
}

int	ft_word_count_with_quotes(char *str, char character)
{
	int				word_count;
	enum e_quotes	quotes;

	word_count = 0;
	quotes = NONE;
	while (*str != '\0')
	{
		while (*str == character && *str != '\0')
			str++;
		if (*str != character && *str != '\0')
			word_count++;
		while (*str != '\0' && (*str != character || quotes != NONE))
		{
			quotes = eval_quotes_state(*str, quotes);
			str++;
		}
	}
	return (word_count);
}
