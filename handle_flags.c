/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/05 12:31:21 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*char_to_str(char c)
{
	char	*buf;

	if (!(buf = ft_strnew(1)))
		return (0);
	buf[0] = c;
	return (buf);
}

char			*handle_other_flags(char *flag, va_list *args)
{
	char	*ret;
	char	flag_letter;
	char	*temp;

	ret = 0;
	temp = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	if (flag_letter == 'p')
	{
		temp = ft_strtolower(ft_itoa_base(va_arg(*args, long int), 16));
		if (!(ret = ft_strnew(ft_strlen(temp + 3))))
			return (0);
		ft_strcat(ret, "0x");
		ft_strcat(ret, temp);
	}
	return (ret);
}

char			*handle_flags(char *flag, va_list *args)
{
	char	*ret;
	char	flag_letter;

	ret = 0;
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
	else
		ret = handle_other_flags(flag, args);
	return (ret);
}
