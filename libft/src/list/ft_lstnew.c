/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 12:58:24 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/16 14:43:00 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
// int	main(void)
// {
// 	t_list *node = ft_lstnew("ramen, sushi, tempura");
// 	if (node)
// 	{
// 		printf("Node: %s\n", (char *)node->content);
// 		free(node);
// 	}
// 	else
// 	{
// 		printf("error\n");
// 	}
// 	return (0);
// }