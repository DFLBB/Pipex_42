/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:31:16 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/06/05 19:42:55 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*p_checkpath(char *path, char *command)
{
	char	**aux;
	char	*aux2;
	char	*result;
	int		c;

	c = -1;
	aux = ft_split(path, ':');
	(free(path), path = NULL);
	while (aux[++c])
	{
		aux2 = ft_strjoin("/", command);
		result = ft_strjoin(aux[c], aux2);
		(free(aux2));
		if (access(result, X_OK) == 0)
		{
			(ft_free(aux, c));
			return (result);
		}
		else
			(free(result), result = NULL);
	}
	(ft_free(aux, c), free(result), result = NULL);
	return (NULL);
}

char	*p_path(char *command, char **envp)
{
	int		i;
	int		j;
	char	*path;
	char	*comm;

	i = -1;
	j = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = malloc((ft_strlen(envp[i]) - 4) * sizeof(char));
			if (!path)
				(free(path), path = NULL, perror("malloc"), exit(errno));
			while (envp[i][++j + 5])
				path[j] = envp[i][j + 5];
			path[j] = '\0';
			comm = p_checkpath(path, command);
			if (comm != NULL)
				return (comm);
		}
	}
	(perror(ft_strjoin("command not found: ", command)), exit (14));
	return (NULL);
}

void	pipex_alt(int argc, char **argv)
{
	int		fd1;

	fd1 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd1 == -1)
		(perror(argv[argc - 1]), exit(errno));
	errno = 13;
	(perror(""), close(fd1), exit (errno));
}
