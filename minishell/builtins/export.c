#include "../minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_lstsize(t_env *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++; 
	}
	return (i);
}

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

void	ft_sort_env(t_env *env)
{
	char	**ptr;
	char	*tmp;
	int		list_len;
	int		i;
	t_env	*head;

	ptr = NULL;
	list_len = ft_lstsize(env);
	i = 0;
	while (i < list_len)
	{
		head = env;
		while(head->next)
		{
			if (ft_strcmp(head->content, head->next->content) > 0)
			{
				tmp = head->content;
				head->content = head->next->content;
				head->next->content = tmp;
			}
			head = head->next;
		}
		i++;
	}
	head = NULL;
	// return (0);
}

void	add_variable(t_env *list_env, char *new)
{
	t_env	*var;

	var = ft_lstnew_env(new);
	ft_lstadd_back_env(&list_env, var);
}

void	export(char **cmd, t_env *list_env)
{
	// char	**export;
	t_env	*head;

	if (!ft_strncmp(cmd[0], "export", 6) && !cmd[1])
	{
		ft_sort_env(list_env);
		head = list_env;
		while (head)
		{
			ft_putstr_fd("declare -x ", 1);
			ft_putstr_fd(head->content, 1);
			ft_putstr_fd("\n", 1);
			head = head->next;
		}
	}
	if (cmd[1])
	{
		if (ft_strchr(cmd[1], '='))
		{
			add_variable(list_env, cmd[1]);
		}
		else 
			printf ("lllll\n");
	}
}
