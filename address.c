/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:19:28 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/31 18:10:25 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printpointer(unsigned long n)
{
	int		i;
	char	*p;

	i = 0;
	p = ft_tohex(n);
	i += ft_putstr("0x");
	i += ft_putstr(p);
	free (p);
	return (i);
}
