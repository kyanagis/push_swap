/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:19:41 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 16:40:46 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	print_content(void *content)
// {
// 	printf("content: %s\n", (char *)content);
// }

// int	main(void)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	*c;

// 	a = ft_lstnew(strdup("Hello"));
// 	b = ft_lstnew(strdup("42"));
// 	c = ft_lstnew(strdup("Tokyo"));
// 	a->next = b;
// 	b->next = c;
// 	ft_lstiter(a, print_content);
// 	ft_lstclear(&a, free);
// }
