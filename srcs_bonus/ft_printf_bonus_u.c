#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	ft_putu(unsigned int ud, t_args *args, int padding, int width)
{
	int		res;

	res = 0;
	if (args->has_zero && !args->has_hyphen)
		while (width-- > 0)
			res += ft_putchar('0');
	while (padding-- > 0)
		res += ft_putchar('0');
	if (ud / 10)
		res += ft_putu(ud / 10, args, padding, width);
	res += ft_putchar((ud % 10) + '0');
	return (res);
}

int	get_u_length(t_args *args, unsigned int ud, int *padding)
{
	int	len;

	len = ft_get_digits_u(ud);
	if (args->has_precision && !args->precision && !ud)
		len = 0;
	if (len < args->precision)
		*padding = args->precision - len;
	len += *padding;
	return (len);
}

int	ft_put_u_left(t_args *args, va_list ap)
{
	unsigned int	ud;
	int				res;
	int				len;
	int				padding;

	res = 0;
	padding = 0;
	ud = va_arg(ap, unsigned int);
	len = get_u_length(args, ud, &padding);
	if (args->has_space && ud)
		res += ft_putchar(' ');
	if (!(args->has_precision && !args->precision))
		res += ft_putu(ud, args, padding, args->width);
	while ((args->width-- - len) > 0 && !args->has_zero)
		res += ft_putchar(' ');
	if (args->has_precision && !args->precision && !ud)
		return (res);
	return (res);
}

int	ft_put_u(t_args *args, va_list ap)
{
	unsigned int	ud;
	int				res;
	int				len;
	int				padding;

	if (args->has_hyphen)
		return (ft_put_u_left(args, ap));
	res = 0;
	padding = 0;
	ud = va_arg(ap, unsigned int);
	len = get_u_length(args, ud, &padding);
	if (args->has_space && ud)
		res += ft_putchar(' ');
	while ((args->width-- - len) > 0 && !args->has_zero)
		res += ft_putchar(' ');
	if (args->has_precision && !args->precision && !ud)
		return (res);
	return (res + ft_putu(ud, args, padding, args->width - len + 1));
}
