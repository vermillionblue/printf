/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:33:19 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/12 17:51:34 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "libftprintf.h"

int ft_numlenhex(unsigned long n)
{
    int i;

    i = 0;

    while(n >= 1)
    {
        n = n / 16;
        i++;
    }
    return (i);
}


int ft_numlen(int n)
{
    int i;

    i = 0;
    if(n < 0)
    {
        n *= -1;
    }
    while(n >= 1)
    {
        n = n / 10;
        i++;
    }
    return (i);
}

char *ft_itoa(int n)
{
    char *p;
    int temp;
    int k;
    int i;
    int x;
    
    i = 0;
    k = ft_numlen(n);
    if(n < 0)
    {
        n *= -1;
        x = -1;
    }
    p = malloc(k);
    if(n == 0)
    {
        *p = '0';
        return(p);
    }
    if(p == NULL) 
        return(NULL);

    while(k > 0)
    {
 
        temp = '0' + (n % 10);
        n = n / 10;
        if(x < 0)
        {
            p[k] = temp;
            p[0] = '-';
        }
        else
        {
            p[k - 1] = temp;
        }
        k--;
        i++;
    }
    
    p[i + 1] = '\0';
    return (p);
}

void ft_putchar(char c)
{
    write( 1, &c, 1);
}

void ft_putstr(char *s)
{
    while(*s != '\0')
    {
        write(1, s, 1);
        s++;
    }
}

char * ft_toHEX(unsigned long n)
{
    int k;
    int rem;
    char * hex;

    k = ft_numlenhex(n);
    int s=k;
    hex = malloc(k + 1);
    if (hex == NULL)
        return(NULL);
    while(k > 0)
    {
        rem = n % 16;
        n = n / 16;
        if(rem >= 0 && rem <= 9)
        {
            hex[k - 1] = *ft_itoa(rem);
        }
        if (rem == 10)
        {
            hex[k - 1] = 'A'; 
        }
        if (rem == 11)
        {
            hex[k - 1] = 'B'; 
        }
        if (rem == 12)
        {
            hex[k - 1] = 'C'; 
        }
        if (rem == 13)
        {
            hex[k - 1] = 'D';  
        }
        if (rem == 14)
        {
            hex[k - 1] = 'E';  
        }
        if (rem == 15)
        {
            hex[k - 1] = 'F'; 
        }
        k--;
    }
    hex[s] = '\0';
    return(hex);
}

char * ft_tohex(unsigned long n)
{
    int k;
    int rem;
    char * hex;

    k = ft_numlenhex(n);
    int s=k;
    hex = malloc(k + 1);
    if (hex == NULL)
        return(NULL);
    while(k > 0)
    {
        rem = n % 16;
        n = n / 16;
        if(rem >= 0 && rem <= 9)
        {
            hex[k - 1] = *ft_itoa(rem);
        }
        if (rem == 10)
        {
            hex[k - 1] = 'a'; 
        }
        if (rem == 11)
        {
            hex[k - 1] = 'b'; 
        }
        if (rem == 12)
        {
            hex[k - 1] = 'c'; 
        }
        if (rem == 13)
        {
            hex[k - 1] = 'd';  
        }
        if (rem == 14)
        {
            hex[k - 1] = 'e';  
        }
        if (rem == 15)
        {
            hex[k - 1] = 'f'; 
        }
        k--;
    }
    hex[s] = '\0';
    return(hex);
}
void printpointer(unsigned long n)
{
    ft_putstr("0x");
    ft_putstr(ft_tohex(n));
}
int	ft_printf(const char *fmt, ...)
{
	va_list args;
	va_start(args, fmt);

	while(*fmt != '\0')
	{
		if(*fmt == '%')
		{
			if((char)*(fmt + 1) == '%')
			{
                ft_putchar('%');
				fmt = fmt + 2;
			}
			else if(*(fmt + 1) == 'c')
			{
				ft_putchar(va_arg(args, int));
				fmt = fmt + 2;
			}
			else if(*(fmt + 1) == 's')
			{
				ft_putstr(va_arg(args, char *));
				fmt = fmt + 2;
			}
			else if(*(fmt + 1) == 'd' || *(fmt + 1) == 'i')
			{
				ft_putstr(ft_itoa(va_arg(args, int)));
				fmt = fmt + 2;
			}
			else if(*(fmt + 1) == 'p')
			{
				printpointer(va_arg(args, unsigned long));
				fmt = fmt + 2;
			}
			else if(*(fmt + 1) == 'x')
			{
				ft_putstr(ft_tohex(va_arg(args, unsigned long)));
				fmt = fmt + 2;
			}
			else if(*(fmt + 1) == 'X')
			{
				ft_putstr(ft_toHEX(va_arg(args, unsigned long)));
				fmt = fmt + 2;
			}
		}
		else
			ft_putchar(*fmt++);
	}
	return (0);
	va_end(args);
}

int	main()
{
	int a = 1;
	ft_printf("miau %c %s %p %% %x %X %i %d" , 'a', "abc", &a, 15 , 15, 77 ,  -123);
	printf("\n");
	printf("miau %c %s %p %% %x %X %i %d" , 'a', "abc", &a, 15, 15 , 77, -123);
}