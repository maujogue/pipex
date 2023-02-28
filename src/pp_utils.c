/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathisaujogue <mathisaujogue@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:07:18 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/28 15:37:42 by mathisaujog      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

char	*get_path_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

char	*get_path_cmd(t_pip *pip, char *cmd, char *path)
{
	char	**tab;
	char	*temp_path;
	char	*temp_path2;
	int		i;

	if (!cmd || access(cmd, F_OK) == 0 || !pip->path)
		return (cmd);
	i = 1;
	tab = ft_split(path, ':');
	if (!tab)
		free_exit(pip, 1, "Error\nMalloc failed1");
	while (tab[i + 1])
	{
		temp_path = ft_strjoin(tab[i], "/");
		temp_path2 = ft_strjoin(temp_path, cmd);
		free(temp_path);
		if (access(temp_path2, X_OK) == 0)
			return (free_array(tab), temp_path2);
		free(temp_path2);
		i++;
	}
	temp_path2 = ft_strjoin(tab[i], cmd);
	if (access(temp_path, F_OK) == 0)
		return (free_array(tab), temp_path2);
	return (free_array(tab), NULL);
}

int	check_second_cmd(t_pip *pip)
{
	if (!pip->cmd2[0])
		return (1);
	else if (ft_strnstr(pip->cmd2[0], "./", 2)
		|| (ft_strnstr(pip->cmd2[0], "/", 1)
			&& ft_strlen(pip->cmd2[0]) == 1)
		|| ft_strnstr(pip->argv[3], " ", 1))
		return (1);
	else
	{
		pip->path_cmd2 = get_path_cmd(pip, pip->cmd2[0], pip->path);
		if (!pip->path_cmd2)
			return (1);
		if (ft_strncmp(pip->path_cmd2, pip->cmd2[0],
				ft_strlen(pip->cmd2[0])) != 0)
		{
			if (pip->exit_status == 3)
				pip->exit_status = 5;
			else
				pip->exit_status = 4;
		}
	}
	return (0);
}

int	check_first_cmd(t_pip *pip)
{
	if (!pip->cmd1[0])
		return (1);
	else if (ft_strnstr(pip->cmd1[0], "./", 2)
		|| (ft_strnstr(pip->cmd1[0], "/", 1)
			&& ft_strlen(pip->cmd1[0]) == 1)
		|| ft_strnstr(pip->argv[2], " ", 1))
		return (1);
	else
	{
		pip->path_cmd1 = get_path_cmd(pip, pip->cmd1[0], pip->path);
		if (!pip->path_cmd1)
			return (1);
		if (ft_strncmp(pip->path_cmd1, pip->cmd1[0],
				ft_strlen(pip->path_cmd1)) != 0)
			pip->exit_status = 3;
	}
	return (0);
}
