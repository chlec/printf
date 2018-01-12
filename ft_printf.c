/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/12 12:58:29 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_temp(char *ret, char **temp, char flag_letter)
{
	if (ret == NULL && (flag_letter == 's' || flag_letter == 'S'))
		ret = "(null)";
	else if (ft_strequ(ret, "-1") && ft_strchr("CS", flag_letter))
		return (ret);
	else if (ret[0] == '\0' && ft_strchr("cC", flag_letter))
	{
		*temp = "@";
		ret = "@";
	}
	else if (ft_strchr("SC", flag_letter) && !ft_strequ(ret, "(null)"))
	{
		*temp = ft_strdup(ret);
		ret = ft_strndup(ret, ft_strlen(ret) / 3);
	}
	else if (!ft_strchr("sSpdDioOuUxXcC%", flag_letter))
		ret = ft_ctos(flag_letter);
	return (ret);
}

static void	print_content(char *ret, char *temp,
		char *conversion, char flag_letter)
{
	int		j;

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
}

static char	*apply_flag(char *flag, char *str, int *i, va_list *args)
{
	char	flag_letter;
	char	*conversion;
	char	*temp;
	char	*ret;
	char	*length_f;

	temp = 0;
	length_f = get_length_flag(flag);
	ret = handle_flags(length_f, flag, args);
//	printf("ret vaut: %s\n", ret);
	flag_letter = flag[ft_strlen(flag) - 1];
	if (ft_strchr("cs", flag_letter) && ft_strchr(length_f, 'l'))
		flag_letter = ft_toupper(flag_letter);
	if (ft_strchr("CS", flag_letter) && ret && !valid_unicode(ret))
		return ("-1");
	if (!(ret = get_temp(ret, &temp, flag_letter)))
		return (0);
	if ((ft_strequ(ret, "-1")) && ft_strchr("CS", flag_letter))
		return (ret);
	conversion = handle_conversion(flag, ret);
	str = replacestr(str, flag, conversion);
	print_content(ret, temp, conversion, flag_letter);
	*i += ft_strlen(conversion) - 1;
	return (str);
}

int			ft_printf(const char *format, ...)
{
	va_list			args;
	int				i;
	char			*flag;
	char			*str;
	int				err;

	err = 0;
	str = ft_strdup((char*)format);
	if (!format)
		return (0);
	i = -1;
	va_start(args, format);
	while (str[++i])
		if (str[i] == '%')
		{
			flag = get_flag(&str[i]);
			str = apply_flag(flag, str, &i, &args);
			if (ft_strequ(str, "-1") &&
					ft_strchr("CS", flag[ft_strlen(flag) - 1]))
				return (-1);
		}
		else
			ft_putchar(str[i]);
	va_end(args);
	return (err ? -1 : ft_strlen(str));
}
