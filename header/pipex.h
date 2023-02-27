/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 16:38:15 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/24 11:24:49 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <errno.h>

typedef struct pip
{
	char	**argv;
	char	**envp;
	char	**cmd1;
	char	**cmd2;
	char	*path_cmd1;
	char	*path_cmd2;
	char	*path;
	char	*infile;
	char	*outfile;
	int		fd_infile;
	int		fd_outfile;
	int		dup;
	int		exit_status;
}	t_pip;

void	write_error(char *str);
void	free_array(char **tab);
void	free_fd(void);
void	free_exit(t_pip *pip, int i, char *message);

int		check_first_cmd(t_pip *pip);
int		check_second_cmd(t_pip *pip);
char	*get_path_envp(char **envp);
char	*get_path_cmd(t_pip *pip, char *cmd, char *path);

void	pipex(t_pip *pip);

#endif