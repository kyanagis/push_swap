/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:31:00 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 17:24:32 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_content = f(lst->content);
		new_node = ft_lstnew(new_content);
		if (!new_node)
		{
			del(new_content);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}

// #include <ctype.h>
// #include <stdlib.h>
// #include <string.h>

// void	*to_upper(void *content)
// {
// 	char	*str;
// 	char	*new_str;

// 	str = (char *)content;
// 	new_str = strdup(str);
// 	for (int i = 0; new_str[i]; i++)
// 		new_str[i] = toupper(new_str[i]);
// 	return (new_str);
// }

// void	del(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list	*a;
// 	t_list	*b;
// 	t_list	*c;
// 	t_list	*new;

// 	a = ft_lstnew(strdup("ramem"));
// 	b = ft_lstnew(strdup("yakuniku"));
// 	c = ft_lstnew(strdup("nikuniku"));
// 	a->next = b;
// 	b->next = c;
// 	new = ft_lstmap(a, to_upper, del);
// 	ft_lstiter(new, (void (*)(void *))puts);
// 	ft_lstclear(&a, del);
// 	ft_lstclear(&new, del);
// }
