/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/19 14:26:17 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_temp(char *ret, char **temp, char flag_letter)
{
    char    *t;
	if (ret == NULL && (flag_letter == 's' || flag_letter == 'S'))
		ret = ft_strdup("(null)");
	else if (ret && ft_strequ(ret, "-1") && ft_strchr("CS", flag_letter))
		return (ret);
	else if (ret && ret[0] == '\0' && ft_strchr("cC", flag_letter))
	{
		*temp = ft_strdup("@");
        ft_strdel(&ret);
		ret = ft_strdup("@");
	}
	else if (ft_strchr("SC", flag_letter) && !ft_strequ(ret, "(null)"))
	{
		*temp = ft_strdup(ret);
		t = ft_strndup(ret, ft_strlen(ret) / 3);
        ft_strdel(&ret);
        ret = t;
	}
	else if (!ft_strchr("sSpdDioOuUxXcC%", flag_letter))
    {
        ft_strdel(&ret);
		ret = ft_ctos(flag_letter);
    }
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
    char    *t;

	temp = 0;
	length_f = get_length_flag(flag);
	ret = handle_flags(length_f, flag, args);
	flag_letter = flag[ft_strlen(flag) - 1];
	if (ft_strchr("cs", flag_letter) && ft_strchr(length_f, 'l'))
		flag_letter = ft_toupper(flag_letter);
	if (ft_strchr("CS", flag_letter) && ret && !valid_unicode(ret))
    {
        ft_strdel(&ret);
		return ("-1");
    }
	if (!(ret = get_temp(ret, &temp, flag_letter)))
		return (0);
	if ((ft_strequ(ret, "-1")) && ft_strchr("CS", flag_letter))
    {
        ft_strdel(&length_f);
        ft_strdel(&temp);
		return (ret);
    }
    t = ft_strdup(flag);
    conversion = handle_conversion(flag, ret);
	str = replacestr(str, t, ft_strdup(conversion));
	print_content(ret, temp, conversion, flag_letter);
	ft_strdel(&temp);
	*i += ft_strlen(conversion) - 1;
    if (ft_strlen(conversion) > 0)
        ft_strdel(&conversion);
//    if (ft_strlen(ret) > 0)
//        ft_strdel(&ret);
    ft_strdel(&length_f);
	return (str);
}

int			ft_printf(const char *format, ...)
{
	va_list			args;
	int				i;
	char			*flag;
	char			*str;
	int				len;
    char            *t;

	str = ft_strdup((char*)format);
	if (!format)
		return (0);
	i = -1;
	va_start(args, format);
	while (str[++i])
		if (str[i] == '%')
		{
			flag = get_flag(&str[i]);
			t = apply_flag(flag, str, &i, &args);
            ft_strdel(&str);
            str = t;
			if (ft_strequ(str, "-1") &&
					ft_strchr("CS", flag[ft_strlen(flag) - 1]))
            {
                ft_strdel(&flag);
				return (-1);
            }
            if (flag && flag[0] == '%')
                ft_strdel(&flag);
		}
		else
			ft_putchar(str[i]);
	va_end(args);
	len = (int)ft_strlen(str);
	ft_strdel(&str);
	return (len);
}
