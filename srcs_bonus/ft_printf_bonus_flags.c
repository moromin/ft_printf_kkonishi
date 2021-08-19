#include "../includes/ft_printf_bonus.h"
#include "../includes/ft_printf_bonus_utils.h"

int	read_args_width(t_args *args, char *itr)
{
	char	*str;

	str = itr;
	while (*str != '.' && !ft_strchr(CONV, *str))
	{
		if (*str == ' ')
			str += (args->has_space = 1);
		if (*str == '-')
			str += (args->has_hyphen = 1);
		if (*str == '0')
			str += (args->has_zero = 1);
		if (ft_isdigit(*str))
		{
			args->has_width = 1;
			args->width = ft_atoi(str);
			str += ft_get_digits(args->width);
		}
		if (*str == '#')
			str += (args->has_sharp = 1);
		if (*str == '+')
			str += (args->has_plus = 1);
	}
	return (str - itr);
}

int	read_args_precision(t_args *args, char *itr)
{
	char	*str;

	str = itr;
	str++;
	args->has_precision = 1;
	if (ft_isdigit(*str))
	{
		args->has_precision = 1;
		args->precision = ft_atoi(str);
		str += ft_get_digits_c(str);
	}
	return (str - itr);
}
