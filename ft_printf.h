/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:10:48 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/07 15:26:43 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <locale.h>
# include "libft.h"

int			ft_printf(const char *format, ...);
char		*handle_flags(char *flag, va_list *args);
char		*handle_conversion(char *flag, char *ret);
char		*replacestr(char *dest, char *flag, char *content);
char		*add_begin(char *str, char *add);
char		*add_end(char *str, char *add);
char		*get_flag(char *str);

#endif
