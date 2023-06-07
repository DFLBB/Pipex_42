/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:18:22 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/05/26 21:34:03 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"

void	pipex(int argc, char **argv, char **envp);
void	p_launch(int argc, int fd[1024][2], int pid[1024], int count);
void	p_start(char **argv, char **envp, int fd1);
void	p_middle(char **argv, char **envp, int fd[1024][2], int count);
void	p_end(int argc, char **argv, char **envp, int fd[1024][2]);
void	p_exec(char *args, char **envp);
char	**p_check_env(char **envp);
char	*p_path(char *command, char **envp);
char	*p_checkpath(char *path, char *command);
void	pipex_alt(int argc, char **argv);

#endif
