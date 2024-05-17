#include "../minishell.h"

void	child(char *nood, char **env)
{
	// dup2(nood->infile, 0);
	// dup2(nood->outfile, 1);
	// close(nood->infile);
	// close(nood->outfile);
	ft_exec(nood, env);
}

void	parent(char *nood, char **env)
{
	(void)env;
	(void)nood;
	wait(NULL);
}
