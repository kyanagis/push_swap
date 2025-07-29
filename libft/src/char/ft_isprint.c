/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:33:47 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/08 23:44:20 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isprint('a'));
// 	printf("%d\n", ft_isprint('~'));
// 	printf("%d\n", ft_isprint('1'));
// 	printf("%d\n", ft_isprint('\t'));
// 	printf("%d\n", ft_isprint('\n'));
// 	printf("%d\n\n", ft_isprint('\0'));

// 	printf("%d\n", isprint('a'));
// 	printf("%d\n", isprint('~'));
// 	printf("%d\n", isprint('1'));
// 	printf("%d\n", isprint('\t'));
// 	printf("%d\n", isprint('\n'));
// 	printf("%d\n\n", isprint('\0'));
// 	return (0);
// }