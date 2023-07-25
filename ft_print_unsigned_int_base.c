/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int_base.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 15:37:25 by samatsum          #+#    #+#             */
/*   Updated: 2023/06/10 13:14:09 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to print an unsigned integer in the specified base
// 29... Calculate the number of digits
// 33... Print characters in the specified base
// digits_base_len... 10 for decimal, 16 for hexadecimal.
size_t	ft_print_unsigned_int_base(\
int fd, size_t number, const char *digits_base)
{
	size_t	i;
	size_t	digits_base_len;
	size_t	output_num;

	i = 1;
	digits_base_len = ft_strlen(digits_base);
	output_num = 0;
	while (i <= number / digits_base_len)
		i *= digits_base_len;
	while (i > 0)
	{
		output_num += ft_print_character(\
		fd, (int)digits_base[(number / i) % digits_base_len]);
		i /= digits_base_len;
	}
	return (output_num);
}
//number = 3, 10, 123