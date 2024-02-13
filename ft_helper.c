/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:10:53 by aneekhra          #+#    #+#             */
/*   Updated: 2023/12/11 15:11:08 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	print_string(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!str)
	{
		if (write (1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[i])
	{
		len = len + print_char(str[i]);
		i++;
	}
	return (len);
}

int	print_digit(int n)
{
	int	len;

	len = 0;
	if (n == -2147483648)
	{
		len = print_string("-2147483648");
	}
	else if (n < 0)
	{
		len = len + print_char('-');
		len = len + print_digit(-n);
	}
	else if (n >= 10)
	{
		len = len + print_digit (n / 10);
		len = len + print_char (n % 10 + '0');
	}
	else
		len = len + print_char(n + '0');
	return (len);
}

int	print_unsigned_int(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
	{
		len = len + print_unsigned_int(n / 10);
		len = len + print_unsigned_int(n % 10);
	}
	else
		len = len + print_char(n + '0');
	return (len);
}

int	print_hexa(long int n, char c)
{
	int		len;
	char	*hexa;

	len = 0;
	hexa = "0123456789abcdef";
	if (c == 'X')
		hexa = "0123456789ABCDEF";
	if (n >= 16)
		len = len + print_hexa(n / 16, c);
	len = len + print_char(hexa[n % 16]);
	return (len);
}
