#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	ft_putdi(int di, t_args *args, int padding, int width)
{
	int		res;

	res = 0;
	if (di == -2147483648)
	{
		res += ft_putchar('-');
		while (padding-- > 0)
			res += ft_putchar('0');
		res += ft_putstr("2147483648");
		return (res);
	}
	if (di < 0)
	{
		res += ft_putchar('-');
		di *= -1;
	}
	if (args->has_zero && !args->has_hyphen)
		while (width-- > 0)
			res += ft_putchar('0');
	while (padding-- > 0)
		res += ft_putchar('0');
	if (di / 10)
		res += ft_putdi(di / 10, args, padding, width);
	res += ft_putchar((di % 10) + '0');
	return (res);
}

int	get_di_length(t_args *args, int di, int *padding)
{
	int	len;

	len = ft_get_digits(di);
	if (args->has_precision && !args->precision && !di)
		len = 0;
	if (di < 0 && (len - 1) < args->precision)
		*padding = args->precision - (len - 1);
	if (di >= 0 && len < args->precision)
		*padding = args->precision - len;
	len += *padding;
	if (args->has_plus && di >= 0)
		len++;
	return (len);
}

int	ft_put_di_left(t_args *args, va_list ap)
{
	int	di;
	int	res;
	int	len;
	int	padding;

	res = 0;
	padding = 0;
	di = va_arg(ap, int);
	len = get_di_length(args, di, &padding);
	if (args->has_space && !args->has_plus && di >= 0)
		res += ft_putchar(' ');
	if (args->has_plus && di >= 0)
		res += ft_putchar('+');
	if (!(args->has_precision && !args->precision))
		res += ft_putdi(di, args, padding, args->width);
	while ((args->width-- - len) > 0 && !args->has_zero)
		res += ft_putchar(' ');
	if (args->has_precision && !args->precision && !di)
		return (res);
	return (res);
}

int	ft_put_di(t_args *args, va_list ap)
{
	int	di;
	int	res;
	int	len;
	int	padding;

	if (args->has_hyphen)
		return (ft_put_di_left(args, ap));
	res = 0;
	padding = 0;
	di = va_arg(ap, int);
	len = get_di_length(args, di, &padding);
	if (args->has_space && !args->has_plus && di >= 0)
		res += ft_putchar(' ');
	while ((args->width-- - len) > 0 && !args->has_zero)
		res += ft_putchar(' ');
	if (args->has_plus && di >= 0)
		res += ft_putchar('+');
	if (args->has_precision && !args->precision && !di)
		return (res);
	return (res + ft_putdi(di, args, padding, args->width - len + 1));
}
