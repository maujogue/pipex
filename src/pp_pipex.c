/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:53:34 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/24 12:47:02 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static int	first_function(t_pip *pip, int pipefd[2])
{
	int	pid1;

	if (check_first_cmd(pip) == 1)
	{
		write_error("No such file or directory\n");
		return (0);
	}
	pid1 = fork();
	if (pid1 < 0)
		free_exit(pip, 1, "Error\nFork failed");
	if (pid1 == 0)
	{
		close(pipefd[0]);
		if (dup2(pip->fd_infile, STDIN_FILENO) < 0)
			free_exit(pip, 1, "Error: Dup2 failed");
		if (dup2(pipefd[1], STDOUT_FILENO) < 0)
			free_exit(pip, 1, "Error: Dup2 failed");
		close(pipefd[1]);
		execve(pip->path_cmd1, pip->cmd1, pip->envp);
		perror("");
		pip->dup = 1;
		free_exit(pip, 1, "");
	}
	return (pid1);
}

static int	second_function(t_pip *pip, int pipefd[2])
{
	int	pid2;

	if (check_second_cmd(pip) == 1)
	{
		write_error("No such file or directory\n");
		return (0);
	}
	pid2 = fork();
	if (pid2 < 0)
		free_exit(pip, 1, "Error: Fork failed");
	if (pid2 == 0)
	{
		close(pipefd[1]);
		if (dup2(pip->fd_outfile, STDOUT_FILENO) < 0)
			free_exit(pip, 1, "Error: Dup2 failed");
		if (dup2(pipefd[0], STDIN_FILENO) < 0 && pip->dup == 1)
			free_exit(pip, 1, "Error: Dup2 failed");
		close(pipefd[0]);
		execve(pip->path_cmd2, pip->cmd2, pip->envp);
		perror("");
	}
	return (pid2);
}

void	pipex(t_pip *pip)
{
	int	pipefd[2];
	int	pid1;
	int	pid2;
	int	status;

	if (pipe(pipefd) == -1)
		free_exit(pip, 1, "Error\nPipe failed");
	if (pip->fd_infile != -1)
		pid1 = first_function(pip, pipefd);
	pid2 = second_function(pip, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
}
