#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

int	ft_putdi(int d, t_args *args)
{
	int		res;

	res = 0;
	(void)args;
	if (d == -2147483648)
	{
		res += ft_putchar('-');
		res += ft_putstr("2147483648");
		return (res);
	}
	if (d < 0)
	{
		res += ft_putchar('-');
		d *= -1;
	}
	if (d / 10)
		res += ft_putdi(d / 10, args);
	res += ft_putchar((d % 10) + '0');
	return (res);
}

int	ft_put_di(t_args *args, va_list ap)
{
	int		di;
	int		res;

	di = va_arg(ap, int);
	res = 0;
	return (res + ft_putdi(di, args));
}
