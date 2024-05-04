#include "minishell.h"

int	chek_for_file(int argc, char **argv)
{
	int	i;
	int fd;

	i = 2;
	fd = 1;
	while (i < argc)
	{
		if (argv[i][0] == 62 || (argv[i][0] == 62 && argv[i][1] == 62))
			fd = ft_open_file(argv[i + 1], 1);
		i++;
	}
	return (fd);
}

int	check_to_open_file(char *c, char *name)
{
	int fd;

	if (c[0] == 62)
		fd = ft_open_file(name, 1);
	else
		fd = 1;
	return (fd);
}

void	handler(char **argv)
{
	int i;

	i = 0;
	if (!ft_strncmp(argv[2], "-e"))
	{
		//printf("---> %c\n", argv[3][4]);
		while (argv[3][i])
		{
			//printf("--->i : %c -->i + 1 : %c\n", argv[3][i] , argv[3][i + 1]);
			if (!find_char(argv[3][i], 92) && !find_char(argv[3][i + 1], 110))
			{
				write(1, "\n", 1);
				i += 2;
			}
			if (argv[3][i] == '\0')
				return ;
			write(1, &argv[3][i], 1);
			
			i++;
		}
		write(1, "\n", 1);
	}
}

void    echo(int argc, char **argv)
{
	int i;
	int h;
	int	x;
	int fd;

	h = 0;
	x = 0;
	fd = chek_for_file(argc, argv);
	if (argc > 1 && !ft_strncmp("echo", argv[1]))
	{
			
		if (argc == 2)
		{
			write (fd, "\n", 1);
			exit(1);
		}
		i = 2;
		while (i < argc)
		{
			
			if (argv[i][0])
			{
				h++;
				if (!ft_strncmp(argv[2], "-e"))
				{
					x += 1;
					if (x == 1)
						i += 1;
					ft_putstr_e(argv[i], i, h, fd);
				}
				else
					ft_putstr(argv[i], i, h, fd);
			}
			i++;
		}
		write(fd, "\n", 1);
	}
	else
		write (2, "\n", 1);
}

int main(int argc, char **argv)
{
	echo(argc, argv);
}