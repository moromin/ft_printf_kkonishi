#include "../includes/ft_printf_bonus_utils.h"

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

int	sign_check(char s)
{
	if (s == '-')
		return (-1);
	else
		return (1);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long long	res;

	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		sign = sign_check(str[i++]);
	res = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if ((res * 10 + (str[i] - '0')) / 10 != res)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
