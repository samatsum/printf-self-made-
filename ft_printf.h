/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <samatsum@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 15:38:39 by samatsum          #+#    #+#             */
/*   Updated: 2023/06/09 15:56:38 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *format, ...);
size_t	ft_print_character(int fd, size_t c);
size_t	ft_print_string(int fd, char *s);
size_t	ft_print_unsigned_int_base(int fd, size_t n, const char *digits);
size_t	ft_print_int_base(int fd, intmax_t n, const char *digits);
size_t	ft_strlen(const char *str);

#endif
