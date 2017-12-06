/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:10:48 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/06 11:40:40 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

int			ft_printf(const char *format, ...);
char		*handle_flags(char *flag, va_list *args);
char		*handle_conversion(char *flag, va_list *args);
char		*replacestr(char *dest, char *flag, void *content);
char		*add_begin(char *str, char *add);
char		*get_flag(char *str);

#endif
