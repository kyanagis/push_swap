#include "libft.h"

int	ft_isspace(int c)
{
	unsigned char ch;

	ch = (unsigned char)c;
	return (ch == ' ' || (ch >= 9 && ch <= 13));
}