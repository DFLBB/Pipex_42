/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanzas- <dlanzas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:18:22 by dlanzas-          #+#    #+#             */
/*   Updated: 2023/05/27 21:00:28 by dlanzas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"

void	pipex(char **argv, char **envp);
void	p_start(char **argv, char **envp, int fd1);
void	p_end(char **argv, char **envp, int fd2);
void	p_exec(char *args, char **envp);
char	**p_check_env(char **envp);
char	*p_path(char *command, char **envp);
char	*p_checkpath(char *path, char *command);
void	pipex_alt(int argc, char **argv);
//void	pipex_alt(int argc, char **argv, char **envp);

#endif
