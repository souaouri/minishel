#include "../minishell.h"

char	**change_list_to_env(t_env *list_env)
{
	char	**env;
	int		i;

	i = 0;
	while (list_env)
	{
		env[i] = list_env->content;
		i++;
		list_env = list_env->next;
	}
	return (env);
}

int	ft_strlen_1(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;
	i = 0;
	if (n == 0)
		return (0);

	while (s1[i] == s2[i] && (s1[i] || s2[i]) && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
