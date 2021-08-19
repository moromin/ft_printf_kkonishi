#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

int	ft_putpct(void)
{
	int		res;

	res = 0;
	res += ft_putchar('%');
	return (res);
}

int	ft_put_pct(t_args *args)
{
	int	res;

	(void)args;
	res = 0;
	return (res + ft_putpct());
}
