#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	ft_put_conv(t_args *args, va_list ap, int res)
{
	(void)res;
	if (args->c == 'c')
		return (ft_put_c(args, ap));
	else if (args->c == 's')
		return (ft_put_s(args, ap));
	else if (args->c == 'p')
		return (ft_put_p(args, ap));
	else if (args->c == 'd' || args->c == 'i')
		return (ft_put_di(args, ap));
	else if (args->c == 'u')
		return (ft_put_u(args, ap));
	else if (args->c == 'x' || args->c == 'X')
		return (ft_put_x(args, ap, args->c));
	else if (args->c == '%')
		return (ft_put_pct(args));
	return (0);
}

void	initialize_args(t_args *args)
{
	args->c = 0;
	args->width = 0;
	args->has_width = 0;
	args->precision = 0;
	args->has_precision = 0;
	args->has_hyphen = 0;
	args->has_zero = 0;
	args->has_space = 0;
	args->has_sharp = 0;
	args->has_plus = 0;
}

char	*read_args(t_args *args, char *itr, va_list ap)
{
	(void)ap;
	itr++;
	while (*itr)
	{
		initialize_args(args);
		itr += read_args_width(args, itr);
		if (*itr == '.')
			itr += read_args_precision(args, itr);
		if (ft_strchr(CONV, *itr))
		{
			args->c = *itr;
			itr++;
			return (itr);
		}
		itr++;
	}
	return (itr);
}

int	ft_printf(const char *format, ...)
{
	char	*itr;
	int		res;
	t_args	args;
	va_list	ap;

	itr = (char *)format;
	if (!itr)
		return (0);
	res = 0;
	va_start(ap, format);
	while (*itr)
	{
		if (*itr == '%')
		{
			itr = read_args(&args, itr, ap);
			res += ft_put_conv(&args, ap, res);
			continue ;
		}
		res += ft_putchar(*itr);
		itr++;
	}
	va_end(ap);
	return (res);
}
