#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

int	ft_put_c(t_args *args, va_list ap)
{
	int		res;
	char	c;

	(void)args;
	c = va_arg(ap, int);
	res = 0;
	return (res + ft_putchar(c));
}
