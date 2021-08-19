#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdarg.h>

# define CONV "cspdiuxX%"
# define STRSIZE 42

typedef struct s_args
{
	int	c;
	int	width;
	int	has_width;
	int	precision;
	int	has_precision;
	int	has_hyphen;
	int	has_zero;
	int	has_space;
	int	has_n;
	int	has_sharp;
	int	has_plus;
	int	type;
}				t_args;

// ft_printf_main
int		ft_printf(const char *format, ...);
char	*read_args(t_args *args, char *itr, va_list ap);
void	initialize_args(t_args *args);
int		ft_put_conv(t_args *args, va_list ap, int res);

// ft_printf_c
int		ft_put_c(t_args *args, va_list ap);

// ft_printf_s
int		ft_put_s(t_args *args, va_list ap);

// ft_printf_p
int		ft_putp(void *addr);
int		ft_put_p(t_args *args, va_list ap);

// ft_printf_di
int		ft_putdi(int d, t_args *args);
int		ft_put_di(t_args *args, va_list ap);

// ft_printf_u
int		ft_putu(unsigned int ud);
int		ft_put_u(t_args *args, va_list ap);

// ft_printf_x
int		ft_putx(unsigned int ud, char c);
int		ft_put_x(t_args *args, va_list ap, char c);

// ft_printf_pct
int		ft_put_pct(t_args *args);
int		ft_putpct(void);

#endif
