/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 19:19:34 by dlanzas           #+#    #+#             */
/*   Updated: 2023/05/17 18:08:27 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_array_of_words(char *str, char c, int num_words, char **split)
{
	int				aux;
	int				aux2;
	int				len_word;

	aux = 0;
	aux2 = 0;
	len_word = 0;
	while (aux < num_words)
	{
		len_word = ft_strlen_word_with_quotes(str, c);
		split[aux] = malloc(sizeof(char) * (len_word + 1));
		if (!split[aux])
			(ft_free(split, aux), perror("malloc"), exit(errno));
		while (*str == c || *str == '\'')
			str++;
		while (aux2 < len_word)
			split[aux][aux2++] = *str++;
		split[aux++][aux2] = '\0';
		aux2 = 0;
	}
	split[aux] = NULL;
	return (split);
}

char	**ft_split(char *str, char character)
{
	char	**split;
	int		num_words;

	if (!str)
		return (NULL);
	num_words = ft_word_count_with_quotes(str, character);
	split = malloc((num_words + 1) * sizeof(char *));
	if (!split)
	{
		perror("malloc");
		return (NULL);
	}
	split = ft_array_of_words(str, character, num_words, split);
	return (split);
}
