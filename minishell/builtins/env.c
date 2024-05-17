#include "../minishell.h"

void	write_env(t_env *env)
{
	while(env)
	{
		ft_putstr_fd(env->content, 1);
		ft_putstr_fd("\n", 1);
		env = env->next;
	}
}