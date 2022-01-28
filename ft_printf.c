/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:33:19 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/29 00:32:53 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "ft_printf.h"



void	checkfmts(va_list args, const char *fmt, int* totallen)
{
	char *p;
	if((char)*(fmt + 1) == '%')
		*totallen += ft_putchar('%');
	else if(*(fmt + 1) == 'c')
		*totallen += ft_putchar(va_arg(args, int));
	else if(*(fmt + 1) == 's')
		*totallen += ft_putstr(va_arg(args, char *));
	else if(*(fmt + 1) == 'd' || *(fmt + 1) == 'i')
		*totallen += ft_putstr(ft_itoa(va_arg(args, int)));
	else if(*(fmt + 1) == 'p')
	{
		p = ft_tohex(va_arg(args, unsigned long));
    	*totallen += ft_putstr("0x");
    	*totallen += ft_putstr(p);
    	free(p);
	}
		
	else if(*(fmt + 1) == 'x')
		*totallen += ft_putstr(ft_tohex(va_arg(args, unsigned long)));
	else if(*(fmt + 1) == 'X')
		*totallen += ft_putstr(ft_toHEX(va_arg(args, unsigned long)));
	else if(*(fmt + 1) == 'u')
		*totallen += printu(va_arg(args, unsigned long));
}

int	ft_printf(const char *fmt, ...)
{
	va_list args;
	int	*totallen;
	int x = 0;
	
	totallen = &x;
	va_start(args, fmt);
	while(*fmt != '\0')
	{
		if(*fmt == '%')
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

// int	main()
// {
// 	int a,b;
// 	ft_printf("miau %c %s %p %% %x %X %i %d %s miau %u" , 'a', "abc", &a, 15 , 15, 77 , -129, "sloth", -123);
// 	printf("\n");
// 	printf("miau %c %s %p %% %x %X %i %d %s miau %u" , 'a', "abc", &a, 15, 15 , 77, -129, "sloth", -123);
// 	printf("\n");
// 	a = printf("this sentence has %d\n", 21);
// 	b = ft_printf("this sentence has %d\n", 21);
// 	printf("%d\n", a);
// 	printf("%d\n", b);
// }