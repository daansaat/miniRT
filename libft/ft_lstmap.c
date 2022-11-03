/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaat <dsaat@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/11/08 12:17:31 by dsaat         #+#    #+#                 */
/*   Updated: 2021/11/08 12:17:32 by dsaat         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*next;

	if (!lst || !*f)
		return (0);
	head = ft_lstnew(f(lst->content));
	lst = lst->next;
	while (lst != NULL)
	{
		next = ft_lstnew(f(lst->content));
		if (!next)
		{
			ft_lstclear(&head, del);
			break ;
		}
		lst = lst->next;
		ft_lstadd_back(&head, next);
	}
	return (head);
}
