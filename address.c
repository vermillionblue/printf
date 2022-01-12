/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:19:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/12 17:51:13 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void printpointer(unsigned long n)
{
    ft_putstr("0x");
    ft_putstr(ft_tohex(n));
}