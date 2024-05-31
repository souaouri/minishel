/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: souaouri <souaouri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:54:18 by souaouri          #+#    #+#             */
/*   Updated: 2024/05/31 01:58:07 by souaouri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_initialisation(t_container	*nood)
{
	nood->cmd = ft_split("ls -a", ' ');
	nood->infile = 0; //open ("Makefile", O_RDONLY , 0644);
	nood->outfile = 1; //open ("solimi", O_CREAT | O_RDWR , 0644);
}

void	ft_initialisation2(t_container	*nood)
{
	nood->cmd = ft_split("cat", ' ');
	nood->infile = 0;
	nood->outfile = open ("solimi", O_CREAT | O_RDWR , 0644);
}

void	ft_initialisation3(t_container	*nood)
{
	// int fd;
	// fd = open ("test.tgjxt", O_CREAT | O_RDONLY | 0644);
	nood->cmd = ft_split("cat", ' ');
	nood->infile = open ("solimi", O_RDONLY , 0644);
	nood->outfile = 1; //open ("tttt", O_CREAT | O_RDWR , 0644);
}

t_list	*ft_lstnew(t_container content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (!*lst || !lst || !new)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	virtual_stack(t_list **list)
{
	t_container	nood;
	// t_container	nood2;
	// t_container	nood3;
	t_list		*new;
	// t_list		*new2;
	// t_list		*new3;

	ft_initialisation(&nood);
	// ft_initialisation2(&nood2);
	// ft_initialisation3(&nood3);

	new = ft_lstnew(nood);
	// new2 = ft_lstnew(nood2);
	// new3 = ft_lstnew(nood3);

	ft_lstadd_back(list, new);
	// ft_lstadd_back(list, new2);
	// ft_lstadd_back(list, new3);
	// while (list)
	// {
	// 	printf("---> cmd : %s\n", list->content.cmd);
	// 	list = list->next; 
	// }
}