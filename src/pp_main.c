/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:43:44 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/24 12:07:17 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	init_pip(t_pip *pip, char **envp, char **argv)
{
	pip->dup = 0;
	pip->argv = argv;
	pip->exit_status = 0;
	pip->infile = argv[1];
	pip->outfile = argv[4];
	pip->path = get_path_envp(envp);
	pip->envp = envp;
	pip->cmd1 = ft_split(argv[2], ' ');
	if (!pip->cmd1)
		free_exit(pip, 1, "Error\nMalloc failed");
	pip->exit_status++;
	pip->cmd2 = ft_split(argv[3], ' ');
	if (!pip->cmd2)
		free_exit(pip, 1, "Error\nMalloc failed");
	pip->exit_status++;
	pip->fd_infile = open(pip->infile, O_RDONLY);
	if (pip->fd_infile == -1)
		perror(NULL);
	pip->fd_outfile = open(pip->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pip->fd_outfile == -1)
	{
		pip->exit_status = 2;
		perror(NULL);
		free_exit(pip, 1, "");
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pip	pip;

	if (argc == 5)
	{
		init_pip(&pip, envp, argv);
		pipex(&pip);
		free_exit(&pip, 0, NULL);
	}
	else if (argc < 5)
		write_error("Error: not enough arguments (4 required)");
	else if (argc > 5)
		write_error("Error: too much arguments (4 required)");
	return (0);
}
