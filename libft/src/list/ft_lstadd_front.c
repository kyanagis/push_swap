/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:01:14 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 14:42:58 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *new_node = ft_lstnew("ramen,yakiniku,soba,jett,sova");

// 	ft_lstadd_front(&head, new_node);
// 	if (head)
// 	{
// 		printf("Node: %s\n", (char *)head->content);
// 		free(head);
// 	}
// 	else
// 	{
// 		printf("error\n");
// 	}
// 	return (0);
// }