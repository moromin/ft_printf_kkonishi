#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	ft_putchar_c(unsigned char c)
{
	return (write(1, &c, 1));
}

int	ft_put_c_left(t_args *args, va_list ap)
{
	int				res;
	unsigned char	c;
	int				len;

	len = 1;
	c = (unsigned char)va_arg(ap, int);
	res = 0;
	res += ft_putchar_c(c);
	while ((args->width-- - len) > 0)
		res += ft_putchar(' ');
	return (res);
}

int	ft_put_c(t_args *args, va_list ap)
{
	int				res;
	unsigned char	c;

	if (args->has_hyphen)
		return (ft_put_c_left(args, ap));
	c = (unsigned char)va_arg(ap, int);
	res = 0;
	while ((args->width-- - 1) > 0)
		res += ft_putchar(' ');
	return (res + ft_putchar_c(c));
}
