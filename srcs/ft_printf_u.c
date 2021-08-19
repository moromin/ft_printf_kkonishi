#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

int	ft_putu(unsigned int ud)
{
	int		res;

	res = 0;
	if (ud / 10)
		res += ft_putu(ud / 10);
	res += ft_putchar((ud % 10) + '0');
	return (res);
}

int	ft_put_u(t_args *args, va_list ap)
{
	unsigned int	ud;
	int				res;

	(void)args;
	ud = va_arg(ap, unsigned int);
	res = 0;
	return (res + ft_putu(ud));
}
