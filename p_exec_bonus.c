/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_exec_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 17:36:34 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/06/06 15:08:20 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	p_middle(char **argv, char **envp, int fd[1024][2], int count)
{
	int	aux;

	aux = -1;
	while (++aux < count - 1)
	{
		if (fd[aux][0] != fd[count - 3][0])
			close(fd[aux][0]);
		if (fd[aux][1] != fd[count - 2][1])
			close(fd[aux][1]);
	}
	dup2(fd[count - 2][1], STDOUT_FILENO);
	close(fd[count - 2][1]);
	dup2(fd[count - 3][0], STDIN_FILENO);
	close(fd[count - 3][0]);
	p_exec(argv[count], envp);
}

void	p_end(int argc, char **argv, char **envp, int fd[1024][2])
{
	int	fdout;
	int	aux;

	aux = -1;
	while (++aux < argc - 4)
	{
		close(fd[aux][1]);
		if (fd[aux][0] != fd[argc - 5][0])
			close(fd[aux][0]);
	}
	fdout = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fdout == -1)
		(perror(argv[argc - 1]), exit(errno));
	dup2(fdout, STDOUT_FILENO);
	close(fdout);
	dup2(fd[argc - 5][0], STDIN_FILENO);
	close(fd[argc - 5][0]);
	p_exec(argv[argc - 2], envp);
}
