/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 10:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/06 11:55:25 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*handle_other_flags(char *flag, va_list *args)
{
	char	*ret;
	char	flag_letter;

	ret = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	if (flag_letter == 'p')
		ret = add_begin(ft_strtolower(ft_itoa_base(va_arg(*args, long int), 16)), "0x");
	return (ret);
}

char	*get_0_param(char *str)
{
	int		i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))	
		i++;
	return (ft_strndup(str, i));
}

char			*handle_conversion(char *flag, va_list *args)
{
	int		i;
	char	flag_letter;
	char	*ret;
	char	*temp;
	int		nb;

	i = 0;
	ret = 0;
	flag_letter = flag[ft_strlen(flag) - 1];
	while (flag[i])
	{
		if (flag[i] == '#')
		{
			if (flag_letter == 'x')
				ret = add_begin(ft_strtolower(handle_flags(flag, args)), "0x");
			else if (flag_letter == 'X')
				ret = add_begin(handle_flags(flag, args), "0X");
			else if (flag_letter == 'o')
				ret = add_begin(handle_flags(flag, args), "0");
		}
		else if (flag[i] == '+')
		{
			if (ft_strchr("id", flag_letter) && ft_atoi((temp = handle_flags(flag, args))) >= 0)
				ret = add_begin(temp, "+");
		}
		else if (flag[i] == ' ' && !ft_strchr(flag, '+'))
		{
			
		}
		else if (flag[i] == '0' && !ft_strchr(flag, '-'))
		{
			nb = ft_atoi(&flag[i + 1]);
			ret = handle_flags(flag, args);
			while (ft_strlen(ret) < (size_t)nb)
				ret = add_begin(ret, "0");
			flag = replacestr(flag, get_0_param(&flag[i]), "");
		}
		i++;
	}
	if (ret)
		return (ret);
	return (handle_flags(flag, args));	
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
		ret = ft_ctos(va_arg(*args, int));
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
