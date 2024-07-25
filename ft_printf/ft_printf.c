/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:13:11 by mmarinov          #+#    #+#             */
/*   Updated: 2024/07/24 12:45:14 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf(char const *s, ...)
{
	int	count;
	va_list	string;

	count = 0;
	va_start(string, s);
	if (*s == '%')
	{
		s++;
	}
	if (*s == 'c')
	{
		ft_putchar_fd(va_arg(string, int), 1);
		s++;
		count++;
	}
	va_end(string);
	return (count);
}

int	main(void)
{
	char	c;

	c = 'f';
	printf("original: %c\n", c);
	ft_printf("%c", c);
	return(0);
}
