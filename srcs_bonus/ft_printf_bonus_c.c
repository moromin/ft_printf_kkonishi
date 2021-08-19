#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	ft_put_c_left(t_args *args, va_list ap)
{
	int		res;
	char	c;
	int		len;

	len = 1;
	c = va_arg(ap, int);
	res = 0;
	res += ft_putchar(c);
	while ((args->width-- - len) > 0)
		res += ft_putchar(' ');
	return (res);
}

int	ft_put_c(t_args *args, va_list ap)
{
	int		res;
	char	c;

	if (args->has_hyphen)
		return (ft_put_c_left(args, ap));
	c = va_arg(ap, int);
	res = 0;
	while ((args->width-- - 1) > 0)
		res += ft_putchar(' ');
	return (res + ft_putchar(c));
}
