/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 14:46:16 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 15:03:21 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	t_list	*n1;
// 	t_list	*n2;
// 	t_list	*n3;
// 	t_list	*last;

// 	n1 = ft_lstnew("reyna");
// 	n2 = ft_lstnew("jett");
// 	n3 = ft_lstnew("sova");
// 	n1->next = n2;
// 	n2->next = n3;
// 	last = ft_lstlast(n1);
// 	if (last)
// 		printf("Last node content: %s\n", (char *)last->content);
// 	free(n1);
// 	free(n2);
// 	free(n3);
// 	return (0);
// }
