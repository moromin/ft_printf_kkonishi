#include "../includes/ft_printf.h"
#include "../includes/ft_printf_utils.h"

int	ft_put_s(t_args *args, va_list ap)
{
	int		res;
	char	*str;

	(void)args;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	res = 0;
	return (res + ft_putstr(str));
}
