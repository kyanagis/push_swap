/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:33:23 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/13 12:51:40 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

// int	main(void)
// {
// 	printf("%d\n", ft_isalpha('a'));
// 	printf("%d\n", ft_isalpha('z'));
// 	printf("%d\n", ft_isalpha('A'));
// 	printf("%d\n", ft_isalpha('Z'));
// 	printf("%d\n", ft_isalpha('1'));
// 	printf("%d\n\n", ft_isalpha('\0'));

// 	printf("%d\n", isalpha('a'));
// 	printf("%d\n", isalpha('z'));
// 	printf("%d\n", isalpha('A'));
// 	printf("%d\n", isalpha('Z'));
// 	printf("%d\n", isalpha('1'));
// 	printf("%d\n\n", isalpha('\0'));
// 	return (0);
// }