/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:32:36 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/31 18:01:15 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_numlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char		c;
	int			temp;
	long int	l;
	int			temp2;

	l = n;
	if (l < 0)
	{
		write(1, "-", 1);
		l *= -1;
	}
	if (l <= 9)
	{
		c = '0' + l;
		write(1, &c, 1);
	}
	else
	{
		temp = l / 10;
		temp2 = l % 10;
		c = '0' + temp2;
		ft_putnbr(temp);
		write(1, &c, 1);
	}
	return (ft_numlen(n));
}
