/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:20:06 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/31 01:52:43 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(int argc, char **argv, char **env)
{
	char		*line;
	t_list		*list;
	t_env		*env_list;

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
		// if (!ft_strncmp(line, "exit", 4))
		// {
		// 	ft_putstr_fd("exit\n", 1);
		// 		break ;
		// }
		
		if (line && *line)
			add_history(line);
		
		env_list = get_env(env);
		
		multiple_cmd(env_list, list);
		list = NULL;
		//classification_cmd(env_list, line);
	}
}
