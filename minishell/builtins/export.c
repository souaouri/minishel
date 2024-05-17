#include "../minishell.h"

void	ft_memcpy(char *dst, char *src, size_t	n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = dst;
	s = src;
	i = 0;
	if (d == NULL && s == NULL)
		return ;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
}

char	**sort_env(char **env)
{
	char	**ptr;
	int		i;
	int		x;

	ptr = NULL;
	i = 0;
	x = 0;

	while(env[i])
	{
		
		ft_memcpy(ptr[x], env[i], ft_strlen(env[i]));
		printf("--> %s\n", ptr[x]);
		exit (0);
	}
	return (0);
}

void	export(char *cmd, char **env)
{
	char	**cmmd;
	char	**export;
	char	**var;

	cmmd = ft_split(cmd, 32);
	
	if (!ft_strncmp(cmmd[0], "export", 6) && !cmmd[1])
	{
		export = sort_env(env);
	}
	var = ft_split(cmmd[1], '=');
	printf("%s", var[0]);
}
