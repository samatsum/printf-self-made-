/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:36:56 by samatsum          #+#    #+#             */
/*   Updated: 2023/06/09 16:20:31 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"
// Function to print hexadecimal values (unsigned) with format
// 35... Output the value of a pointer in hexadecimal format
// 38... Output an unsigned int in hexadecimal format
// 40... Output an unsigned int in uppercase hexadecimal format
// p...Consider the argument as void pointer, 
// and output its value (address value) in hexadecimal representation.
static size_t	ft_print_formatted_hexadecimal(\
int fd, const char *format, va_list var_arg_list)
{
	size_t		output_num;
	const char	*hex;
	const char	*big_hex;
	size_t		p;

	hex = "0123456789abcdef";
	big_hex = "0123456789ABCDEF";
	output_num = 0;
	if (*format == 'p')
	{
		p = (size_t)va_arg(var_arg_list, void *);
		output_num += ft_print_string(fd, "0x");
		output_num += ft_print_unsigned_int_base(fd, p, hex);
	}
	else if (*format == 'x')
		output_num += ft_print_unsigned_int_base(\
		fd, va_arg(var_arg_list, unsigned int), hex);
	else if (*format == 'X')
		output_num += ft_print_unsigned_int_base(\
		fd, va_arg(var_arg_list, unsigned int), big_hex);
	return (output_num);
}

// Function to print output based on the format specifier
static size_t	print_formatted(\
int fd, const char *format, va_list var_arg_list)
{
	size_t		output_num;
	const char	*ten = "0123456789";

	output_num = 0;
	if (*format == 'c')
		output_num += ft_print_character(fd, va_arg(var_arg_list, int));
	else if (*format == '%')
		output_num += ft_print_character(fd, '%');
	else if (*format == 's')
		output_num += ft_print_string(fd, va_arg(var_arg_list, char *));
	else if (*format == 'd' || *format == 'i')
		output_num += ft_print_int_base(fd, va_arg(var_arg_list, int), ten);
	else if (*format == 'u')
		output_num += ft_print_unsigned_int_base(\
		fd, va_arg(var_arg_list, unsigned int), ten);
	else if (*format == 'p' || *format == 'x' || *format == 'X')
		output_num += ft_print_formatted_hexadecimal(fd, format, var_arg_list);
	return (output_num);
}

// Function to process the format string and perform the output
static int	ft_variable_args_print_formatted(\
int fd, const char *format, va_list var_arg_list)
{
	size_t	i;
	int		output_num;

	i = 0;
	output_num = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			output_num += (int)print_formatted(fd, &format[i], var_arg_list);
		}
		else
		{
			ft_print_character(fd, format[i]);
			output_num++;
		}
		i++;
	}
	return (output_num);
}

int	ft_printf(const char *format, ...)
{
	int		output_num;
	va_list	var_arg_list;

	va_start(var_arg_list, format);
	output_num = ft_variable_args_print_formatted(\
	STDOUT_FILENO, format, var_arg_list);
	va_end(var_arg_list);
	return (output_num);
}
// #include <stdio.h>
// #include <limits.h>
// int main(void)
// {
// 	int i;
// 	int j;
// 	int	k;

// 	i = 0;
// 	j = INT_MIN;
// 	k = INT_MAX;
// 	char *str;
// 	str = NULL;
// 	int a = printf("original = [%#X][%++i][%s]@\n", -1,345,"");
// 	int b = ft_printf("    mine = [%#X][%++i][%s]@\n", -1,345,"");
// 	printf("a = %d\n", a);
// 	printf("b = %d\n", b);
// 	return (0);
// }