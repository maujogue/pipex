/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_free_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:31:57 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/23 15:32:08 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

void	write_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	free_array(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	free_fd(void)
{
	int	fd;

	fd = 0;
	while (close(fd) != -1)
		fd++;
	fd = 5;
	while (close(fd) != -1)
		fd++;
}

void	free_exit(t_pip *pip, int i, char *message)
{
	if (pip->exit_status >= 1)
		free_array(pip->cmd1);
	if (pip->exit_status >= 2)
		free_array(pip->cmd2);
	if ((pip->exit_status == 3 || pip->exit_status == 5)
		&& pip->fd_infile != -1)
		free(pip->path_cmd1);
	if (pip->exit_status == 4 || pip->exit_status == 5)
		free(pip->path_cmd2);
	if (i == 0)
	{
		free_fd();
		exit(EXIT_SUCCESS);
	}
	write(2, message, ft_strlen(message));
	free_fd();
	exit(EXIT_FAILURE);
}
