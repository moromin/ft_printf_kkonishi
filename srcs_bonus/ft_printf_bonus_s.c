#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	ft_putstr_len(char *str, int len)
{
	int	res;
	int	i;

	if (!str)
		return (0);
	res = 0;
	i = 0;
	while (str[i] && i < len)
	{
		res += ft_putchar(str[i]);
		i++;
	}
	return (res);
}

int	ft_put_s_left(t_args *args, va_list ap)
{
	int			res;
	const char	*str;
	int			len;

	res = 0;
	str = va_arg(ap, const char *);
	if (!str)
		str = "(null)";
	len = ft_strlen((char *)str);
	if (args->has_precision && (len > args->precision))
		len = args->precision;
	res += ft_putstr_len((char *)str, len);
	while ((args->width-- - len) > 0)
		res += ft_putchar(' ');
	return (res);
}

int	ft_put_s(t_args *args, va_list ap)
{
	int			res;
	const char	*str;
	int			len;

	if (args->has_hyphen)
		return (ft_put_s_left(args, ap));
	res = 0;
	str = va_arg(ap, const char *);
	if (!str)
		str = "(null)";
	len = ft_strlen((char *)str);
	if (args->has_precision && (len > args->precision))
		len = args->precision;
	while ((args->width-- - len) > 0)
		res += ft_putchar(' ');
	return (res + ft_putstr_len((char *)str, len));
}
