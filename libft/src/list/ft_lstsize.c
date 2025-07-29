/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:35:45 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 14:45:35 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		++count;
		lst = lst->next;
	}
	return (count);
}

// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *new_node1 = ft_lstnew("ramen");
// 	t_list *new_node2 = ft_lstnew("yakiniku");
// 	t_list *new_node3 = ft_lstnew("soba");

// 	ft_lstadd_front(&head, new_node1);
// 	ft_lstadd_front(&head, new_node2);
// 	ft_lstadd_front(&head, new_node3);

// 	printf("List size: %d\n", ft_lstsize(head));

// 	while (head)
// 	{
// 		t_list *temp = head;
// 		head = head->next;
// 		free(temp);
// 	}

// 	return (0);
// }