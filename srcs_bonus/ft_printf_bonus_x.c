#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	ft_putx(unsigned int ud, t_args *args, int padding, int width)
{
	int		res;

	res = 0;
	if (args->has_zero)
		while (width-- > 0)
			res += ft_putchar('0');
	while (padding-- > 0)
		res += ft_putchar('0');
	if (ud / 16)
		res += ft_putx((ud / 16), args, padding, width);
	if ((ud % 16) >= 10)
	{
		if (args->c == 'x')
			res += ft_putchar((ud % 16) - 10 + 'a');
		else
			res += ft_putchar((ud % 16) - 10 + 'A');
	}
	else
		res += ft_putchar((ud % 16) + '0');
	return (res);
}

int	get_x_length(t_args *args, unsigned int ud, int *padding)
{
	int	len;

	len = ft_get_digits_x(ud);
	if (args->has_precision && !args->precision && !ud)
		len = 0;
	if (len < args->precision)
		*padding = args->precision - len;
	len += *padding;
	if (args->has_sharp && ud)
		len += 2;
	return (len);
}

int	ft_put_x_left(t_args *args, va_list ap, char c)
{
	unsigned int	ud;
	int				res;
	int				len;
	int				padding;

	res = 0;
	padding = 0;
	ud = va_arg(ap, unsigned int);
	len = get_x_length(args, ud, &padding);
	if (args->has_space && ud)
		res += ft_putchar(' ');
	if (ud && args->has_sharp)
	{
		if (c == 'x')
			res += ft_putstr("0x");
		else
			res += ft_putstr("0X");
	}
	if (!(args->has_precision && !args->precision))
		res += ft_putx(ud, args, padding, args->has_width);
	while ((args->width-- - len) > 0 && !args->has_zero)
		res += ft_putchar(' ');
	if (args->has_precision && !args->precision && !ud)
		return (res);
	return (res);
}

int	ft_put_x(t_args *args, va_list ap, char c)
{
	unsigned int	ud;
	int				res;
	int				len;
	int				padding;

	if (args->has_hyphen)
		return (ft_put_x_left(args, ap, c));
	res = 0;
	padding = 0;
	ud = va_arg(ap, unsigned int);
	len = get_x_length(args, ud, &padding);
	if (args->has_space && ud)
		res += ft_putchar(' ');
	while ((args->width-- - len) > 0 && !args->has_zero)
		res += ft_putchar(' ');
	if (args->has_precision && !args->precision && !ud)
		return (res);
	if (ud && args->has_sharp)
	{
		if (c == 'x')
			res += ft_putstr("0x");
		else
			res += ft_putstr("0X");
	}
	return (res + ft_putx(ud, args, padding, args->width - len + 1));
}
