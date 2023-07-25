/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_formatted_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 19:18:28 by samatsum          #+#    #+#             */
/*   Updated: 2023/06/14 16:03:44 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_handle_hash(int fd, const char *format, int temp_arg)
{
	size_t		output_num;

	output_num = 0;
	format++;
	if (temp_arg != 0)
	{
		if (*format == 'x')
			output_num += ft_print_string(fd, "0x");
		else if (*format == 'X')
			output_num += ft_print_string(fd, "0X");
	}
	return (output_num);
}

size_t	ft_print_flags_bonus(int fd, const char *format, va_list var_arg_list)
{
	size_t		output_num;
	int			temp_arg;
	va_list		arg_list_copy;

	output_num = 0;
	va_copy(arg_list_copy, var_arg_list);
	temp_arg = va_arg(arg_list_copy, int);
	va_end(arg_list_copy);
	if (*format == '+')
	{
		if (temp_arg >= 0)
			output_num += ft_print_character(fd, '+');
	}
	else if (*format == ' ')
	{
		if (temp_arg >= 0)
			output_num += ft_print_character(fd, ' ');
	}
	else if (*format == '#')
		output_num += ft_handle_hash(fd, format, temp_arg);
	return (output_num);
}
