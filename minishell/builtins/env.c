#include "../minishell.h"

void	get_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		ft_putstr_fd(env[i], 1);
		i++;
	}
}
