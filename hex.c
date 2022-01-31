/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:38:52 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/31 18:21:45 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numlenhex(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

char	*ft_tohex(unsigned long n)
{
	int		k;
	int		rem;
	char	*hex;
	int		s;

	k = ft_numlenhex(n);
	s = k;
	hex = malloc(k + 1);
	if (!hex)
		return (NULL);
	while (k > 0)
	{
		rem = n % 16;
		n = n / 16;
		if (rem >= 0 && rem <= 9)
			hex[k - 1] = '0' + rem;
		if (rem >= 10 && rem <= 15)
			hex[k - 1] = 'a' + (rem - 10);
		k--;
	}
	hex[s] = '\0';
	return (hex);
}

char	*ft_toupperhex(unsigned long n)
{
	int		k;
	int		rem;
	char	*hex;
	int		s;

	k = ft_numlenhex(n);
	s = k;
	hex = malloc(k + 1);
	if (hex == NULL)
		return (NULL);
	while (k > 0)
	{
		rem = n % 16;
		n = n / 16;
		if (rem >= 0 && rem <= 9)
			hex[k - 1] = '0' + rem;
		if (rem >= 10 && rem <= 15)
			hex[k - 1] = 'A' + (rem - 10);
		k--;
	}
	hex[s] = '\0';
	return (hex);
}

int	printhex(unsigned int n)
{
	int		i;
	char	*p;

	i = 0;
	p = ft_tohex(n);
	i += ft_putstr(p);
	free (p);
	return (i);
}

int	printupperx(unsigned int n)
{
	int		i;
	char	*p;

	i = 0;
	p = ft_toupperhex(n);
	i += ft_putstr(p);
	free (p);
	return (i);
}
