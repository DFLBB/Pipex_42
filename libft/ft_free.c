/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 11:51:12 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/05/16 18:51:37 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_free(char **substr, int num)
{
	while (num >= 0)
	{
		free(substr[num]);
		substr[num] = NULL;
		num--;
	}
	free(substr);
	substr = NULL;
	return (NULL);
}
