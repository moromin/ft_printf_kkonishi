#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	ft_putp(void *addr)
{
	char				addr_c[30];
	unsigned long long	addr_l;
	int					i;
	int					res;

	res = 0;
	if (addr == NULL)
		return (res += ft_putchar('0'));
	addr_l = (long)addr;
	i = 0;
	while (addr_l > 0)
	{
		addr_c[i] = addr_l % 16;
		if (addr_c[i] < 10)
			addr_c[i] += '0';
		else
			addr_c[i] += 87;
		addr_l /= 16;
		i++;
	}
	while (--i >= 0)
		res += ft_putchar(addr_c[i]);
	return (res);
}

int	ft_put_p_left(t_args *args, va_list ap)
{
	void	*ld;
	int		res;
	int		len;

	ld = va_arg(ap, void *);
	res = 0;
	len = ft_get_digits_p(ld);
	len += 2;
	res += ft_putstr("0x");
	res += ft_putp(ld);
	while ((args->width-- - len) > 0)
		res += ft_putchar(' ');
	return (res);
}

int	ft_put_p(t_args *args, va_list ap)
{
	void	*ld;
	int		res;
	int		len;

	if (args->has_hyphen)
		return (ft_put_p_left(args, ap));
	ld = va_arg(ap, void *);
	res = 0;
	len = ft_get_digits_p(ld);
	len += 2;
	while ((args->width-- - len) > 0)
		res += ft_putchar(' ');
	res += ft_putstr("0x");
	return (res + ft_putp(ld));
}
