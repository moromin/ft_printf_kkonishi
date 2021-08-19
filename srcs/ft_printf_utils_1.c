#include "../includes/ft_printf_utils.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (*str)
		res += ft_putchar(*str++);
	return (res);
}

char	*ft_strchr(char *str, int c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
