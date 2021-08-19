#include "../includes/ft_printf_bonus_utils.h"

int	ft_get_digits(int d)
{
	int	digits;

	if (d == -2147483648)
		return (11);
	digits = 0;
	if (d < 0)
	{
		digits++;
		d *= -1;
	}
	d /= 10;
	while (d)
	{
		digits++;
		d /= 10;
	}
	digits++;
	return (digits);
}

int	ft_get_digits_c(char *str)
{
	int	res;

	res = 0;
	if (!str)
		return (res);
	while (ft_isdigit(*str++))
		res++;
	return (res);
}

int	ft_get_digits_u(unsigned int ud)
{
	int	digits;

	digits = 0;
	while (ud / 10)
	{
		digits++;
		ud /= 10;
	}
	digits++;
	return (digits);
}

int	ft_get_digits_x(unsigned int ud)
{
	int	digits;

	digits = 0;
	while (ud / 16)
	{
		digits++;
		ud /= 16;
	}
	digits++;
	return (digits);
}

int	ft_get_digits_p(void *addr)
{
	int					digits;
	unsigned long long	addr_l;

	addr_l = (unsigned long long)addr;
	digits = 0;
	while (addr_l / 16)
	{
		digits++;
		addr_l /= 16;
	}
	digits++;
	return (digits);
}
