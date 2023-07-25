/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 15:37:44 by samatsum          #+#    #+#             */
/*   Updated: 2023/06/09 16:01:33 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Function to print a string
size_t	ft_print_string(int fd, char *s)
{
	if (s == NULL)
		s = "(null)";
	return (write(fd, s, ft_strlen(s)));
}
