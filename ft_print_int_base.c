/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_signed_int_base.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:38:08 by samatsum          #+#    #+#             */
/*   Updated: 2023/06/09 16:23:40 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to print a signed integer in the specified base
size_t	ft_print_int_base(int fd, intmax_t n, const char *digits)
{
	size_t	output_num;

	if (n >= 0)
		return (ft_print_unsigned_int_base(fd, (size_t)n, digits));
	output_num = ft_print_character(fd, '-');
	output_num += ft_print_unsigned_int_base(fd, (size_t)-n, digits);
	return (output_num);
}
