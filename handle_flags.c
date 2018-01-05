/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/05 13:01:32 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			wstrlen(wchar_t *s)
{
	int				i;
	unsigned int	c;
	size_t			count;

	i = 0;
	c = 0;
	count = 0;
	while (s[i])
	{
		c = s[i];
		if (c <= 0x7F)
			count++;
		else if (c <= 0x7FF)
			count += 2;
		else if (c <= 0xFFFF)
			count += 3;
		else if (c <= 0x1FFFFF)
			count += 4;
		i++;
	}
	return (count);
}

char			*handle_other_flags(char *flag, va_list *args)
{
	char	*ret;
	wchar_t	*ret_w;
	char	flag_letter;

	ret = "";
	ret_w = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	if (flag_letter == 'p')
		ret = add_begin(ft_strtolower(ft_itoa_base(va_arg(*args,
							long int), 16)), "0x");
	else if (flag_letter == 'S')
	{
		ret_w = va_arg(*args, wchar_t*);
		ret = ft_wputstr(ret_w);
	}
	else if (flag_letter == 'C')
	{
		ret_w = ft_ctos_up(va_arg(*args, wchar_t));
		ret = ft_wputstr(ret_w);
	}
	return (ret);
}

char			*get_0_param(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (ft_strndup(str, i));
}

char			*handle_conversion(char *flag, char *ret)
{
	char	*rep;

	if (!ret)
		return (0);
	rep = 0;
	if (ft_strcmp(flag, "%%") == 0)
		return (ret);
	if ((rep = handle_precision(flag, ret)))
		return (rep);
	else if ((rep = handle_diese(flag, ret)))
		return (rep);
	else if ((rep = handle_plus(flag, ret)))
		return (rep);
	else if ((rep = handle_space(flag, ret)))
		return (rep);
	else if ((rep = handle_neg(flag, ret)))
		return (rep);
	else if ((rep = handle_zero(flag, ret)))
		return (rep);
	else if ((rep = handle_digit(flag, ret)))
		return (rep);
	return (ret);
}

char			*handle_flags(char *length_flag, char *flag, va_list *args)
{
	char	*ret;
	char	flag_letter;

	ret = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	if (flag_letter == '%' && flag[0] == '%' && flag[1])
		ret = "%";
	else if (flag_letter == 'd' || flag_letter == 'i' || flag_letter == 'D')
	{
		if (!ft_strcmp(length_flag, "l") || flag_letter == 'D')
			ret = ft_intmaxtoa(va_arg(*args, long));
		else if (!ft_strcmp(length_flag, "hh"))
			ret = ft_itoa((signed char)va_arg(*args, int));
		else if (!ft_strcmp(length_flag, "h"))
			ret = ft_itoa((short)va_arg(*args, int));
		else if (!ft_strcmp(length_flag, "ll"))
			ret = ft_intmaxtoa(va_arg(*args, long long));
		else if (!ft_strcmp(length_flag, "j"))
			ret = ft_intmaxtoa(va_arg(*args, intmax_t));
		else if (!ft_strcmp(length_flag, "z"))
			ret = ft_intmaxtoa(va_arg(*args, size_t));
		else
			ret = ft_itoa(va_arg(*args, int));
	}
	else if (flag_letter == 'x' || flag_letter == 'X')
	{
		if (!ft_strcmp(length_flag, "hh"))
			ret = ft_itoa_base((unsigned char)va_arg(*args, int), 16);
		else if (!ft_strcmp(length_flag, "h"))
			ret = ft_itoa_base((unsigned short)va_arg(*args, int), 16);
		else if (!ft_strcmp(length_flag, "l"))
			ret = ft_uintmaxtoa_base(va_arg(*args, unsigned long), 16);
		else if (!ft_strcmp(length_flag, "ll"))
			ret = ft_uintmaxtoa_base(va_arg(*args, unsigned long long), 16);
		else if (!ft_strcmp(length_flag, "j"))
			ret = ft_uintmaxtoa_base(va_arg(*args, uintmax_t), 16);
		else if (!ft_strcmp(length_flag, "z"))
			ret = ft_uintmaxtoa_base(va_arg(*args, size_t), 16);
		else
			ret = ft_itoa_base(va_arg(*args, unsigned int), 16);
		if (flag_letter == 'x')
			ret = ft_strtolower(ret);
	}
	else if (flag_letter == 'o' || flag_letter == 'O')
	{
		if (!ft_strcmp(length_flag, "l") || flag_letter == 'O')
			ret = ft_uintmaxtoa_base(va_arg(*args, unsigned long), 8);
		else if (!ft_strcmp(length_flag, "hh"))
			ret = ft_itoa_base((unsigned char)va_arg(*args, int), 8);
		else if (!ft_strcmp(length_flag, "h"))
			ret = ft_itoa_base((unsigned short)va_arg(*args, int), 8);
		else if (!ft_strcmp(length_flag, "ll"))
			ret = ft_uintmaxtoa_base(va_arg(*args, unsigned long long), 8);
		else if (!ft_strcmp(length_flag, "j"))
			ret = ft_uintmaxtoa_base(va_arg(*args, uintmax_t), 8);
		else if (!ft_strcmp(length_flag, "z"))
			ret = ft_uintmaxtoa_base(va_arg(*args, unsigned long long), 8);
		else
			ret = ft_itoa_base(va_arg(*args, unsigned int), 8);
	}
	else if (flag_letter == 'u' || flag_letter == 'U')
	{
		if (!ft_strcmp(length_flag, "l") || flag_letter == 'U')
			ret = ft_uintmaxtoa(va_arg(*args, unsigned long));
		else if (!ft_strcmp(length_flag, "hh"))
			ret = ft_itoa((unsigned char)va_arg(*args, int));
		else if (!ft_strcmp(length_flag, "h"))
			ret = ft_itoa((unsigned short)va_arg(*args, int));
		else if (!ft_strcmp(length_flag, "ll"))
			ret = ft_uintmaxtoa(va_arg(*args, unsigned long long));
		else if (!ft_strcmp(length_flag, "j"))
			ret = ft_uintmaxtoa(va_arg(*args, uintmax_t));
		else if (!ft_strcmp(length_flag, "z"))
			ret = ft_uintmaxtoa(va_arg(*args, unsigned long long));
		else
			ret = ft_intmaxtoa(va_arg(*args, unsigned int));
	}
	else if (flag_letter == 's')
	{
		if (!ft_strcmp(length_flag, "l"))
		{
			flag = replacestr(flag, "s", "S");
			return (handle_other_flags(flag, args));
		}
		else
			ret = va_arg(*args, char*);
	}
	else if (flag_letter == 'c')
	{
		if (!ft_strcmp(length_flag, "l"))
		{
			flag = replacestr(flag, "c", "C");
			return (handle_other_flags(flag, args));
		}
		else
			ret = ft_ctos(va_arg(*args, int));
	}
	else
		ret = handle_other_flags(flag, args);
	return (ret);
}
