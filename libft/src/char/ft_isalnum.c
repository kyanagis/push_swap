/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyanagis <kyanagis@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 04:33:28 by kyanagis          #+#    #+#             */
/*   Updated: 2025/05/12 16:11:28 by kyanagis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return ((ft_isdigit(c)) || (ft_isalpha(c)));
}

// int	main(void)
// {
// 	printf("%d\n", ft_isalnum('a'));
// 	printf("%d\n", ft_isalnum('z'));
// 	printf("%d\n", ft_isalnum('A'));
// 	printf("%d\n", ft_isalnum('Z'));
// 	printf("%d\n", ft_isalnum('1'));
// 	printf("%d\n\n", ft_isalnum('\0'));

// 	printf("%d\n", isalnum('a'));
// 	printf("%d\n", isalnum('z'));
// 	printf("%d\n", isalnum('A'));
// 	printf("%d\n", isalnum('Z'));
// 	printf("%d\n", isalnum('1'));
// 	printf("%d\n\n", isalnum('\0'));

// 	return (0);
// }