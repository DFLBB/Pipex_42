/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:27:18 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/06/06 15:13:57 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	p_launch(int argc, int fd[1024][2], int pid[1024], int count)
{
	if (count < argc - 2)
	{
		if (pipe(fd[count - 2]) != 0)
			(perror("pipe"), exit(errno));
	}
	pid[count - 2] = fork();
	if (pid[count - 2] < 0)
		(perror("fork"), exit(errno));
}

void	pipex(int argc, char **argv, char **envp)
{
	int	fd[1024][2];
	int	count;
	int	pid[1024];
	int	status;

	count = 2;
	p_launch(argc, fd, pid, count);
	if (pid[count - 2] == 0)
		(close(fd[0][0]), p_start(argv, envp, fd[0][1]));
	else
	{	
		while (argv[++count] && count < argc - 2)
		{
			p_launch(argc, fd, pid, count);
			if (pid[count - 2] == 0)
				p_middle(argv, envp, fd, count);
		}
		p_launch(argc, fd, pid, count);
		if (pid[count - 2] == 0)
			(close(fd[count - 3][1]), p_end(argc, argv, envp, fd));
	}
	while (--count - 2 >= 0)
		(close(fd[count - 2][1]), close(fd[count - 2][0]));
	while (++count < argc - 1)
		waitpid(-1, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	count;
	int	i;

	i = -1;
	count = 1;
	while (++count < argc - 1)
	{
		if (ft_strlen(argv[count]) == 0)
		{
			while (envp[++i])
			{
				if (ft_strncmp(envp[i], "PATH=", 5) == 0)
					pipex_alt(argc, argv);
			}
		}
	}
	if (argc > 4)
		pipex(argc, argv, envp);
	else
	{
		ft_putstr_fd("Error en el número de argumentos. Debe introducirse:\n \
./pipex archivo1 \"comando_1\" \"comando_2\" ... \"comando_n\" archivo2\n", 1);
		exit (1);
	}
	return (0);
}
