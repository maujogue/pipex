/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:34:55 by maujogue          #+#    #+#             */
/*   Updated: 2022/11/21 09:46:34 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tab;
	char	*str;

	tab = NULL;
	if (!del || !f)
		return (NULL);
	while (lst != NULL)
	{
		str = (*f)(lst->content);
		new = ft_lstnew(str);
		if (!new)
		{
			del(str);
			ft_lstclear(&tab, (*del));
			return (NULL);
		}
		ft_lstadd_back(&tab, new);
		lst = lst->next;
	}
	return (tab);
}
