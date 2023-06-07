/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:27:18 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/06/06 15:30:27 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	p_exec(char *args, char **envp)
{
	char	**commands;
	char	*command;
	int		count;
	int		exe;

	count = ft_word_count_with_quotes(args, ' ');
	commands = ft_split(args, ' ');
	command = commands[0];
	if (command == NULL)
		(perror("command not found: "), exit (13));
	if (access(command, X_OK) != 0)
		command = p_path(commands[0], envp);
	exe = execve(command, commands, envp);
	if (commands)
	{
		(ft_free(commands, count - 1), commands = NULL);
		(free(command), command = NULL);
	}
	if (exe < 0)
		(perror("execve"), exit(errno));
}

void	p_start(char **argv, char **envp, int fd1)
{
	int	fdin;

	fdin = open(argv[1], O_RDONLY);
	if (fdin == -1)
		(perror(argv[1]), exit(errno));
	dup2(fdin, STDIN_FILENO);
	close(fdin);
	dup2(fd1, STDOUT_FILENO);
	close(fd1);
	p_exec(argv[2], envp);
}

void	p_end(char **argv, char **envp, int fd2)
{
	int	fdout;

	fdout = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fdout == -1)
		(perror(argv[4]), exit(errno));
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	dup2(fd2, STDIN_FILENO);
	close(fd2);
	p_exec(argv[3], envp);
}

void	pipex(char **argv, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;
	int	status;
	int	status2;

	pid2 = 0;
	if (pipe(fd) == -1)
		(perror("pipe"), exit(errno));
	pid1 = fork();
	if (pid1 < 0)
		(perror("fork"), exit(errno));
	if (pid1 == 0)
		(close(fd[0]), p_start(argv, envp, fd[1]));
	else
	{	
		pid2 = fork();
		if (pid2 < 0)
			(perror("fork"), exit(errno));
		if (pid2 == 0)
			(close(fd[1]), p_end(argv, envp, fd[0]));
	}
	(close(fd[0]), close(fd[1]));
	waitpid(-1, &status, 0);
	waitpid(-1, &status2, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int	i;

	i = -1;
	if (argc == 5)
	{
		if (ft_strlen(argv[2]) == 0 || ft_strlen(argv[3]) == 0)
		{
			while (envp[++i])
			{
				if (ft_strncmp(envp[i], "PATH=", 5) == 0)
					pipex_alt(argc, argv);
			}
		}
		pipex(argv, envp);
	}
	else
	{
		ft_putstr_fd("Error en el número de argumentos. Debe introducirse:\n \
			./pipex archivo1 \"comando_1\" \"comando_2\" archivo2\n", 1);
		exit (1);
	}
	return (0);
}
