/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:10:39 by aneekhra          #+#    #+#             */
/*   Updated: 2023/12/11 15:12:41 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_flag(va_list ap, const char specifier)
{
	int	len;

	len = 0;
	if (specifier == 'c')
		len = len + print_char(va_arg(ap, int));
	else if (specifier == 's')
		len = len + print_string(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		len = len + print_digit(va_arg(ap, int));
	else if (specifier == 'u')
		len = len + print_unsigned_int(va_arg(ap, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len = len + print_hexa(va_arg(ap, unsigned int), specifier);
	else if (specifier == 'p')
		len = len + print_ptr(va_arg(ap, unsigned long long), 0);
	else if (specifier == '%')
		len = len + print_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		len;
	va_list	ap;

	i = 0;
	len = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			len = len + check_flag(ap, format[i + 1]);
			i++;
		}
		else
			len = len + print_char(format[i]);
		i++;
	}
	va_end(ap);
	return (len);
}

/* #include <stdio.h>
int	main()
{
	//Test with different format specifiers
	ft_printf("Hello,!\n", "world", 54);
	printf("Hello, !\n", "world");

	ft_printf("Number: %d%d\n", 42,5);
	printf("Number: %d\n", 42);

	ft_printf("Character: %c\n", 'A');
	printf("Character: %c\n", 'A');

	ft_printf("Hexadecimal: %x\n", 255);
	printf("Hexadecimal: %x\n", 255);

	int len1 = ft_printf("Pointer address: %p\n", (void *)-1);
	int len2 = printf("Pointer address: %p\n", (void *)-1);

	printf("%i %i\n", len1, len2);

	//Test with a custom format specifier ('%')
	ft_printf("Double percent: %%\n");
	printf("Double percent: %%\n");

	return 0;
} */