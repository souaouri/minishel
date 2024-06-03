/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 17:31:42 by souaouri          #+#    #+#             */
/*   Updated: 2024/06/03 19:22:39 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	open_in_file(t_list **list)
{
	int	i;
	int	fd;

	i = 0;
	if (!(*list)->content.in_file)
		return (0);
	while ((*list)->content.in_file[i])
	{
		fd = open ((*list)->content.in_file[i], O_RDONLY , 0644);
		i++; //  sss > hhhh > kkk
	}
	return (fd);
}

int	open_out_file(t_list **list)
{
	int	i;
	int	fd;

	i = 0;
	if (!(*list)->content.out_file)
		return (1);
	while ((*list)->content.out_file[i])
	{
		fd = open ((*list)->content.out_file[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		i++;
	}
	return (fd);
}

void	change_list(t_list **list)
{
	(*list)->content.outfile = open_out_file(list);
	(*list)->content.infile = open_in_file(list);
}