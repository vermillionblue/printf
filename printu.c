/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printu.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:02:56 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/31 18:02:22 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numlenu(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	printu(unsigned int n)
{
	int		numlen;
	int		temp;
	char	*num;
	int		i;

	numlen = numlenu(n);
	i = numlen;
	num = malloc(numlen + 1);
	while (i > 0)
	{
		temp = n % 10;
		num[i - 1] = '0' + temp;
		n = n / 10;
		i--;
	}
	num[numlen] = '\0';
	ft_putstr(num);
	free (num);
	return (numlen);
}
