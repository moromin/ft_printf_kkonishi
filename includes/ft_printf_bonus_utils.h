#ifndef FT_PRINTF_BONUS_UTILS_H
# define FT_PRINTF_BONUS_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf_bonus.h"

// ft_printf_utils_1
int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_strchr(char *str, int c);
int		sign_check(char s);
int		ft_atoi(const char *str);

// ft_printf_utils_2
int		ft_get_digits(int d);
int		ft_get_digits_c(char *str);
int		ft_get_digits_u(unsigned int ud);
int		ft_get_digits_x(unsigned int ud);
int		ft_get_digits_p(void *addr);

// ft_printf_utils_3
int		ft_isdigit(char c);
int		ft_strlen(char *str);

#endif
