/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:35:33 by dlanzas           #+#    #+#             */
/*   Updated: 2023/05/27 20:00:29 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>

enum e_quotes{
	NONE,
	SINGLES
};

int		ft_strlen(const char *s);
int		ft_strlen_word_with_quotes(const char *s, char c);
int		ft_word_count_with_quotes(char *str, char character);
int		eval_quotes_state(const char c, const short quotes);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strncmp(char *s1, char *s2, unsigned int n);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char *str, char character);
void	*ft_free(char **substr, int num);
char	**ft_array_of_words(char *s, char c, int num_words, char **split);

#endif
