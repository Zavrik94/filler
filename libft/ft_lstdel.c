/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azavrazh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 21:51:09 by azavrazh          #+#    #+#             */
/*   Updated: 2017/12/15 21:40:46 by azavrazh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *lst1;

	if (!alst || !(*alst) || !del)
		return ;
	lst = *alst;
	while (lst)
	{
		lst1 = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = lst1;
	}
	*alst = NULL;
}
