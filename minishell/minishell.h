#ifndef MINISHELL_H
#define MINNISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct echo
{
    int i;
	int h;
	int	x;
	int fd;
}           t_variabl;

int	    ft_strncmp(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
int	    find_char(int c, int h);
void	ft_putstr(char *str, int i, int h, int fd);
void	ft_putstr_e(char *str, int i, int h, int fd);
int 	ft_open_file(char *name, int i);

#endif