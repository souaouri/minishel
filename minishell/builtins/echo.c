#include "../minishell.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		if (fd >= 0)
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

void	echo(char *cmd)
{
	char	**cmmd;
	int		i;
	int		v;

	i = 1;
	v = 0;
	cmmd = ft_split(cmd, 32);

	if (!ft_strncmp(cmmd[i], "-n", 2))
	{
		i++;
		v++;
	}
	while (cmmd[i])
	{
		if (cmmd[i][0] == '$')
		{
			char	*var;
			var = getenv(cmmd[i] + 1);
			printf ("====%s\n", cmmd[i]);
			if (var)
				ft_putstr_fd(var, 1);
		}
		else
			ft_putstr_fd(cmmd[i], 1);
			if (cmmd[i + 1])
				ft_putstr_fd(" ", 1);
		i++;
	}
	if (!v)
		ft_putstr_fd("\n", 1);
}
