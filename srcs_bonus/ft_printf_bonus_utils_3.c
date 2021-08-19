#include "../includes/ft_printf_bonus_utils.h"

int	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_strlen(char *str)
{
	int		len;

	len = 0;
	if (!str)
		return (0);
	while (*str++)
		len++;
	return (len);
}
