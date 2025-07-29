/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:33:32 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/12 16:11:35 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// int	main(void)
// {
// 	printf("%d\n", ft_isascii(0));
// 	printf("%d\n", ft_isascii(-1));
// 	printf("%d\n", ft_isascii(127));
// 	printf("%d\n", ft_isascii(128));
// 	printf("%d\n", ft_isascii(-2147483648));
// 	printf("%d\n\n", ft_isascii(2147483647));

// 	printf("%d\n", isascii(0));
// 	printf("%d\n", isascii(-1));
// 	printf("%d\n", isascii(127));
// 	printf("%d\n", isascii(128));
// 	printf("%d\n", isascii(-2147483648));
// 	printf("%d\n\n", isascii(2147483647));
// }