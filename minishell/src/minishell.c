/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:20:06 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/17 00:32:40 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **env)
{
	char		*line;
	t_list		*list;

	(void)argv;
	(void)argc;

	list = NULL;
	virtual_stack(&list);
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
		
		classification_cmd(env, line);
	}
}