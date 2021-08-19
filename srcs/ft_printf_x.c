#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

int	ft_putx(unsigned int ud, char c)
{
	int		res;

	res = 0;
	if (ud / 16)
		res += ft_putx((ud / 16), c);
	if ((ud % 16) >= 10)
	{
		if (c == 'x')
			res += ft_putchar((ud % 16) - 10 + 'a');
		else
			res += ft_putchar((ud % 16) - 10 + 'A');
	}
	else
		res += ft_putchar((ud % 16) + '0');
	return (res);
}

int	ft_put_x(t_args *args, va_list ap, char c)
{
	unsigned int	ud;
	int				res;

	ud = va_arg(ap, unsigned int);
	res = 0;
	if (ud != 0 && args->has_sharp)
	{
		if (c == 'x')
			res += ft_putstr("0x");
		else
			res += ft_putstr("0X");
	}
	return (res + ft_putx(ud, c));
}
