/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:10:46 by aneekhra          #+#    #+#             */
/*   Updated: 2023/12/11 15:10:49 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long long ptr, int c)
{
	int		len;
	char	*hex;

	hex = "0123456789abcdef";
	len = 0;
	if (!c)
	{
		len += write(1, "0x", 2);
		c++;
	}
	if (ptr >= 16)
		len += print_ptr(ptr / 16, c);
	len += print_char(hex[ptr % 16]);
	return (len);
}
