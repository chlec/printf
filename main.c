/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/08 13:51:34 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	arg_len(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	return (count);
}

char	*get_flag(char *str)
{
	int		i;
	char	*ret;
	char	*validchar;

	validchar = " +-#0123456789.hljz";
	i = 1;
	while (str[i])
	{
		if (ft_strchr(validchar, str[i]))
			i++;
		else
			return (ft_strndup(str, i + 1));
	}
	ret = ft_strdup(str);
	return (ret);
}

char	*get_length_flag(char *flag)
{
	char	*valid;
	int		i;
	int		j;
	char	*ret;

	ret = 0;
	valid = "hljz";
	i = 0;
	while (!ft_strchr(valid, flag[i]))
		i++;
	if (flag[i])
	{
		j = i;
		while (ft_strchr(valid, flag[j]))
			j++;
		ret = ft_strsub(flag, i, j - i);
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	va_list			args;
	int				i;
	int				j;
	char			*flag;
	char			*conversion;
	char			*ret;
	char			*temp;
	char			flag_letter;
	char			*str;
	char			*length_f;

	str = ft_strdup((char*)format);
	if (!format)
		return (0);
	i = 0;
	flag = 0;
	temp = 0;
	va_start(args, format);
	while (str[i])
	{
		if (str[i] == '%')
		{
			flag = get_flag(&str[i]);
			length_f = get_length_flag(flag);
			ret = handle_flags(length_f, flag, &args);
			flag_letter = flag[ft_strlen(flag) - 1];
			if (ft_strchr("cs", flag_letter) && ft_strchr(length_f, 'l'))
				flag_letter = ft_toupper(flag_letter);
			if (ret == NULL && (flag_letter == 's' || flag_letter == 'S'))
				ret = "(null)";
			else if (ret[0] == '\0' && ft_strchr("cC", flag_letter))
			{
				temp = "@";
				ret = "@";
			}
			else if (ft_strchr("SC", flag_letter) && !ft_strequ(ret, "(null)"))
			{
				temp = ft_strdup(ret);
				ret = ft_strndup(ret, ft_strlen(ret) / 3);
			}
			else if (!ft_strchr("sSpdDioOuUxXcC%", flag_letter))
			{
				ret = ft_ctos(flag_letter);
			}
			conversion = handle_conversion(flag, ret);
			str = replacestr(str, flag, conversion);
			if (ft_strchr("SC", flag_letter) && !ft_strequ(ret, "(null)")
					&& !ft_strequ(ret, "@"))
				manip_sc_up(conversion, ret, temp);
			else if (ft_strchr("cC", flag_letter) && temp && temp[0] == '@')
			{
				j = 0;
				while (conversion[j])
				{
					if (conversion[j] == '@')
						ft_putchar(0);
					else
						ft_putchar(conversion[j]);
					j++;
				}
			}
			else
				ft_putstr(conversion);
			i += ft_strlen(conversion) - 1;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (ft_strlen(str));
}
