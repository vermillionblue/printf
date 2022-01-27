/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:15:26 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/27 20:00:42 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>

int 	ft_numlenhex(unsigned long n);
int    printpointer(unsigned long n);
int 	ft_putchar(char c);
int		ft_numlen(int n);
char	*ft_itoa(int n);
int 	ft_putstr(char *s);
char	*ft_tohex(unsigned long n);
char	*ft_toHEX(unsigned long n);
int     printu(unsigned int n);
int     ft_printf(const char *fmt, ...);

#endif