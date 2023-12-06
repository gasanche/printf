/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabsanch <gabsanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:38:35 by gabsanch          #+#    #+#             */
/*   Updated: 2023/07/16 18:29:08 by gabsanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list_new;
	t_list	*temp;
	void	*content;

	list_new = NULL;
	while (lst != NULL)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (temp == NULL)
		{
			free(content);
			ft_lstclear(&list_new, del);
			return (NULL);
		}
		ft_lstadd_back(&list_new, temp);
		lst = lst->next;
	}
	return (list_new);
}
