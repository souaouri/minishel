#include "../minishell.h"
// int	count_pipe(char *str)
// {
// 	char	**ptr;
// 	int		i;
// 	int		pipe;

// 	i = 0;
// 	pipe = 0;
// 	ptr = ft_split(str, 32);
// 	while (ptr[i])
// 	{
// 		if (!ft_strncmp(ptr[i], "|", 1))
// 			pipe++;
// 		i++;
// 	}
// 	return (pipe);
// }

// void	multiple_child(char **argv, int *p_fd, char **env)
// {
// 	int	fd;

// 	fd = open_file(argv[1], 0);
// 	if (fd == -1)
// 		ft_error(p_fd);
// 	dup2(fd, 0);
// 	dup2(p_fd[1], 1);
// 	close(fd);
// 	close(p_fd[1]);
// 	close(p_fd[0]);
// 	ft_exec(argv[2], env);
// }

// void	multiple_parent(char **argv, int *p_fd, char **env)
// {
// 	int	fd;
// 	int	pid;

// 	fd = open_file(argv[4], 1);
// 	if (fd == -1)
// 		ft_error(p_fd);
// 	pid = fork();
// 	if (pid == 0)
// 	{
// 		dup2(fd, 1);
// 		dup2(p_fd[0], 0);
// 		close(fd);
// 		close(p_fd[0]);
// 		close(p_fd[1]);
// 		ft_exec(argv[3], env);
// 	}
// 	else if (pid > 0)
// 	{
// 		close(p_fd[0]);
// 		close(p_fd[1]);
// 	}
// 	else
// 		perror("piping error !!");
// }

// void	multiple_cmdl()
// {
// 	int		p_fd[2];
// 	int		pid;

// 	if (pipe(p_fd) == -1)
// 		exit(1);
// 	pid = fork();
// 	if (pid == -1)
// 		(perror("piping error !!"), close(p_fd[0]), close(p_fd[1]), exit(1));
// 	if (!pid)
// 		child(argv, p_fd, env);
// 	else
// 	{
// 		parent(argv, p_fd, env);
// 		close (p_fd[1]);
// 		close (p_fd[0]);
// 		waitpid(pid, NULL, 0);
// 	}
// }

void	multiple_cmd(char **env, t_list *list)
{
	int	p_fd[2];
	int hold_fd_in;
	int pid;
	int	p_in ;
	int	p_out;
	t_list *tmp;

	hold_fd_in = 0;
	tmp = list;
	// while (list)
	// {
	// 	printf ("cmd : %s | infile : %d | outfile : %d\n", list->content.cmd[0], list->content.infile, list->content.outfile);
	// 	list = list->next;
	// }
	// exit (0);
	while (list)
	{
		p_in = dup (0);
		p_out = dup (1);
		

		if (list->content.infile > 0)
		{
			if (hold_fd_in > 0)
				close (hold_fd_in);
			dup2(list->content.infile, 0);
			close (list->content.infile);
		}
		else if (hold_fd_in > 0)
		{
			dup2(hold_fd_in, 0);
			close (hold_fd_in);
		}
		if (list->next)
		{
			if (pipe(p_fd) == -1)
				exit(1);
			dup2(p_fd[1], 1);
			close (p_fd[1]);
			hold_fd_in = p_fd[0];
		}
		if (list->content.outfile > 1)
		{
			dup2(list->content.outfile, 1);
			close (list->content.outfile);
		}
		pid = fork();
		if (pid == 0)
		{
			close (p_in);
			close (p_out);
			if (hold_fd_in > 0)
				close (hold_fd_in);
			while (1)
				;
			ft_exec(list->content.cmd, env);
		}
		if (pid < 0)
		{
			ft_putstr_fd("minishell:", 2);
			ft_putstr_fd("fork: Resource temporarily unavailable", 2);
		}
		dup2(p_in, 0);
		close (p_in);
		dup2(p_out, 1);
		close (p_out);
		list = list->next;
	}
	while (wait(NULL) != -1)
		;
}
	/*
	while (head)
	{
		int fd_inparent= dup(0);
		int fd_outparent= dup(1);
		if(data->next)
		{
			int *ptr = creatpipe();
			dup2(ptr[1], 1);
			int hold_fdin = ptr[0];
		}
		if(data->fdin >  1)
		{
			close(hold_fdin);
			daup2(fdin, 0);
			close(fdin);
		}
		else if (hold_fdin > 0)
		{
			daup2(hold_fdin, 0);
			close(hold_fdin);
		}
		pid = fork();
		if (pid == 0)
		{
			
			run_cammand(**env, **cmd);
		}
		else if (pid < 0)
		{
			message : wahh wahh alyamm !
		}

		head = head->next;

	}
	
	
	
	
	*/