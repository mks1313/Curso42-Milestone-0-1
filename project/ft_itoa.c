/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinov <mmarinov@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:32:57 by mmarinov          #+#    #+#             */
/*   Updated: 2024/07/04 16:02:35 by mmarinov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	sign = 0;
	len = num_len(n);
	str = (char *)ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	if (n == -2147483648)
	{
		str[--len] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	while (--len)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

int	main(void)
{
int	num = -2147483648;
char	*result = ft_itoa(num);

size_t	i;

i = 0;
while (result[i])
	printf("%c", result[i++]);
printf("\n");

if(result)
{
printf("resultado de conversion es: %s\n", result);
free(result);
}
else
{
printf("Error: Memoria insufuciente para convertit el numero.\n");
	}
return (0);
}
