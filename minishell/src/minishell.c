/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:20:06 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/26 22:37:06 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	 count_pipe(char *cmd)
{
	char	**cmmd;
	int		i;
	int		pipe;

	i = 0;
	pipe = 0;
	cmmd = ft_split(cmd, ' ');
	while(cmmd[i])
	{
		if (!ft_strncmp(cmmd[i], "|", 1))
			pipe += 1;
		i++;
	}
	return (pipe);
}

int	main(int argc, char **argv, char **env)
{
	char		*line;
	t_list		*list;
	t_env		*env_list;
	int			i;

	(void)argv;
	(void)argc;

	list = NULL;
	virtual_stack(&list); //in
	// create a new linked list for the env
	// contains (char *value, struct *next;)
	while (1)
	{
		line = readline("minishell: ");
		if (!line)
		{
			ft_putstr_fd("exit\n", 1);
				break ;
		}
		if (!ft_strncmp(line, "exit", 4))
		{
			ft_putstr_fd("exit\n", 1);
				break ;
		}
		if (line && *line)
			add_history(line);
		i = count_pipe(line);
		// printf ("pipe : %d\n", i);
		// exit (0);
		if (ft_lstsize_1(list) > 1)
			multiple_cmd(env, list);
		exit (0);
		env_list = get_env(env);
		classification_cmd(env_list, line);
	}
}
