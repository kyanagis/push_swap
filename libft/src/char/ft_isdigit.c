/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:33:38 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/09 04:40:31 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int	main(void)
// {
// 	printf("%d\n", ft_isdigit('a'));
// 	printf("%d\n", ft_isdigit('z'));
// 	printf("%d\n", ft_isdigit('A'));
// 	printf("%d\n", ft_isdigit('0'));
// 	printf("%d\n", ft_isdigit('1'));
// 	printf("%d\n\n", ft_isdigit('\0'));

// 	printf("%d\n", isdigit('a'));
// 	printf("%d\n", isdigit('z'));
// 	printf("%d\n", isdigit('A'));
// 	printf("%d\n", isdigit('0'));
// 	printf("%d\n", isdigit('1'));
// 	printf("%d\n\n", isdigit('\0'));
// 	return (0);
// }