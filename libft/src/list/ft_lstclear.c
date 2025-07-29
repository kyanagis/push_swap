/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:05:11 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 16:18:35 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	*lst = NULL;
}

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list *node1 = ft_lstnew(malloc(5));
// 	t_list *node2 = ft_lstnew(malloc(5));
// 	t_list *node3 = ft_lstnew(malloc(5));

// 	node1->next = node2;
// 	node2->next = node3;

// 	ft_lstclear(&node1, del);

// 	if (node1 == NULL)
// 		printf("リストはすべて解放されました。\n");
// 	else
// 		printf("解放に失敗しました。\n");
// }