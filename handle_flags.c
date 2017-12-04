/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/11/30 16:50:43 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char*	char_to_str(char c)
{
	char	*buf;

	if (!(buf = ft_strnew(1)))
		return (0);
	buf[0] = c;
	return (buf);
}

char			*handle_flags(char *flag, va_list *args)
{
	char	*ret;
	char	flag_letter;

	flag_letter = flag[ft_strlen(flag) - 1];
	if (ft_strcmp(flag, "%%") == 0)
		ret = "%";
	else if (flag_letter == 'd' || flag_letter == 'i')
		ret = ft_itoa(va_arg(*args, int));
	else if (flag_letter == 's')
		ret = va_arg(*args, char*);
	else if (flag_letter == 'c')
		ret = char_to_str(va_arg(*args, int));
	else if (flag_letter == 'x')
		ret = ft_strtolower(ft_itoa_base(va_arg(*args, unsigned int), 16));
	else if (flag_letter == 'X')
		ret = ft_itoa_base(va_arg(*args, unsigned int), 16);
	else if (flag_letter == 'o')
		ret = ft_itoa_base(va_arg(*args, unsigned int), 8);
	else if (flag_letter == 'u')
		ret = ft_itoa(va_arg(*args, unsigned int));
	else if (flag_letter == 'p')
		ret = ft_strtolower(ft_itoa_base(va_arg(*args, unsigned long), 16));
	return (ret);
}