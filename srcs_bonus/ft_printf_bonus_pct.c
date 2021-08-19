#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	ft_putpct(t_args *args)
{
	int		res;

	res = 0;
	if (args->has_zero && !args->has_hyphen)
		while ((args->width-- - 1) > 0)
			res += ft_putchar('0');
	res += ft_putchar('%');
	return (res);
}

int	ft_put_pct_left(t_args *args)
{
	int	res;

	res = 0;
	res += ft_putpct(args);
	while ((args->width-- - 1) > 0 && !args->has_zero)
		res += ft_putchar(' ');
	return (res);
}

int	ft_put_pct(t_args *args)
{
	int	res;

	if (args->has_hyphen)
		return (ft_put_pct_left(args));
	res = 0;
	while ((args->width-- - 1) > 0 && !args->has_zero)
		res += ft_putchar(' ');
	args->width++;
	return (res + ft_putpct(args));
}
