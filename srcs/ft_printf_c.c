#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

int	ft_putchar_c(unsigned char c)
{
	return (write(1, &c, 1));
}

int	ft_put_c(t_args *args, va_list ap)
{
	int				res;
	unsigned char	c;

	(void)args;
	c = (unsigned char)va_arg(ap, int);
	res = 0;
	return (res + ft_putchar_c(c));
}
