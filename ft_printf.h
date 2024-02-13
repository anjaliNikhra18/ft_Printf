/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aneekhra <aneekhra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:10:33 by aneekhra          #+#    #+#             */
/*   Updated: 2023/12/11 15:10:36 by aneekhra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	check_flag(va_list ap, const char specifier);
int	print_char(char c);
int	print_string(char *str);
int	print_digit(int n);
int	print_unsigned_int(unsigned int n);
int	print_hexa(long int n, char c);
int	print_ptr(unsigned long long ptr, int c);
#endif