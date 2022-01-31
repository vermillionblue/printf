/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:33:19 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/31 18:23:51 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ft_printf.h"

void	checkfmts(va_list args, const char	*fmt, int	*totallen)
{
	if ((char)*(fmt + 1) == '%')
		*totallen += ft_putchar('%');
	else if (*(fmt + 1) == 'c')
		*totallen += ft_putchar(va_arg(args, int));
	else if (*(fmt + 1) == 's')
		*totallen += ft_putstr(va_arg(args, char *));
	else if (*(fmt + 1) == 'd' || *(fmt + 1) == 'i')
		*totallen += ft_putnbr(va_arg(args, int));
	else if (*(fmt + 1) == 'p')
		*totallen += printpointer(va_arg(args, unsigned long));
	else if (*(fmt + 1) == 'x')
		*totallen += printhex(va_arg(args, unsigned int));
	else if (*(fmt + 1) == 'X')
		*totallen += printupperx(va_arg(args, unsigned int));
	else if (*(fmt + 1) == 'u')
		*totallen += printu(va_arg(args, unsigned long));
}

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	int		*totallen;
	int		x;

	x = 0;
	totallen = &x;
	va_start(args, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			checkfmts(args, fmt, totallen);
			fmt += 2;
		}
		else
		{
			ft_putchar(*fmt++);
			*totallen += 1;
		}
	}
	va_end(args);
	return (x);
}
