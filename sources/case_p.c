
#include "../includes/ft_printf.h"

int		case_p(t_flags *flags, va_list args)
{
	int		count;

	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_base_int(va_arg(args, unsigned long), "0123456789abcdef");	
	return (count);
}
