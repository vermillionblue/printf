/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:38:52 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/27 22:11:23 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char *ft_tohex(unsigned long n)
{
    int k;
    int rem;
    char *hex;
    char x;

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
            x = *ft_itoa(rem);
             hex[k - 1] = x;
        }
           
        if (rem == 10)
            hex[k - 1] = 'a'; 
        if (rem == 11)
            hex[k - 1] = 'b'; 
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