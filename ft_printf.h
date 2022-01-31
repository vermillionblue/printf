/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danisanc <danisanc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:15:26 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/31 18:27:24 by danisanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

int		ft_numlenhex(unsigned long n);
int		printpointer(unsigned long n);
int		ft_putchar(char c);
int		ft_numlen(long n);
int		ft_putnbr(int n);
int		ft_putstr(char *s);
char	*ft_tohex(unsigned long n);
char	*ft_toupperhex(unsigned long n);
int		printu(unsigned int n);
int		ft_printf(const char *fmt, ...);
int		printhex(unsigned int n);
int		printupperx(unsigned int n);
#endif