#include "minishell.h"

int	ft_open_file(char *name, int i)
{
	int	fd;

	if(i == 1)
		fd = open(name , O_CREAT | O_RDWR);
	else
		fd = 1;
	return (fd);
}

void	ft_putstr(char *str, int i, int h, int fd)
{
	int j;

	j = 0;

	if (h > 1 && str[0] != '\0')
		write(fd, " ", 1);
	while (str[j])
	{
		write (fd, &str[j], 1);
		j++;
	}
}
void	ft_putstr_e(char *str, int i, int h, int fd)
{
	int j;

	j = 0;
	if (fd > 1)
		write(fd, "\t", 1);
	if (h > 2 && str[0] != '\0')
		write(fd, " ", 1);
	while (str[j])
	{
		if (!find_char(str[j], 92) && !find_char(str[j + 1], 110))
		{
			write(fd, "\n", 1);
			j += 2;
		}
		if (str[j] == '\0')
			return ;
		write (fd, &str[j], 1);
		j++;
	}
}

int	find_char(int c, int h)
{
	if ((char) c == (char) h)
		return (0);
	else
		return (1);
}

int	ft_strncmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	
	while (s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*ft_strchr(const char *s, int c)
{
	char	*ptr;

	ptr = (char *)s;
	while (*ptr)
	{
		if (*ptr == (char) c)
			return (ptr);
		ptr++;
	}
	if ((char)c == '\0')
		return (ptr);
	return (NULL);
}