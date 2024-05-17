/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 00:35:27 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/18 00:41:31 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_fork(char *nood, char **env)
{
	
	int	pid;

	pid = fork();
	if (pid == -1)
		perror("error");
	else if (!pid)
		child(nood, env);
	else if (pid)
		parent (nood, env);
}

void	classification_cmd(t_env *env, char *nood)
{
	char	*pwd;
	char	**cmmd;

	pwd = NULL;
	if (!ft_strncmp("echo", nood, 4))
	{
		cmmd = ft_split(nood, 32);
		echo(nood);
	}
	else if (!ft_strncmp("pwd", nood, 3))
		ft_find_pwd();
	else if (!ft_strncmp("env", nood, 3))
		write_env(env);
	else if (!ft_strncmp("cd", nood, 2))
		get_cd(nood);
	else if (!ft_strncmp("export", nood, 6))
		export(nood, env);
	exit (0);
	// else
	// 	ft_fork(nood, env);
}
