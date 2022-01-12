/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:32:36 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/12 17:36:14 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
	}
	while (n >= 1)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*itoa_iter(char *p, int n, int k, int x)
{
	int	temp;
	int	i;

	i = 0;
	while (k > 0)
	{
		temp = '0' + (n % 10);
		n = n / 10;
		if (x < 0)
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

char	*ft_itoa(int n)
{
	char	*p;
	int		k;
	int		x;

	k = ft_numlen(n);
	p = malloc(k);
	if (p == NULL)
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		x = -1;
	}
	if (n == 0)
	{
		*p = '0';
		return (p);
	}
	return (itoa_iter(p, n, k, x));
}

