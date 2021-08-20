#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

int	ft_put_s(t_args *args, va_list ap)
{
	int			res;
	const char	*str;

	(void)args;
	str = va_arg(ap, const char *);
	if (!str)
		str = "(null)";
	res = 0;
	return (res + ft_putstr((char *)str));
}
