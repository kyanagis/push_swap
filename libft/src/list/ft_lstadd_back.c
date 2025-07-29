/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:03:43 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 15:54:13 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
// #include <stdio.h>

// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*second;
// 	t_list	*current;

// 	head = ft_lstnew("rameeen");
// 	second = ft_lstnew("BBBBBB");
// 	ft_lstadd_back(&head, second);
// 	current = head;
// 	while (current)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}
// 	return (0);
// }
