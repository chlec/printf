/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/08 11:10:25 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_index(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (!needle[0])
		return (0);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] && needle[j] && haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		if (!needle[j])
			return (i - j);
		i -= j;
		i++;
	}
	return (0);
}

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
	char	*flags;

	flags = "sSpdDioOuUxXcC%";
	i = 1;
	while (str[i])
	{
		if (ft_strchr(flags, str[i])) //|| str[i + 1] == ' ')
		{
			ret = ft_strndup(str, i + 1);
			return (ret);
		}
		i++;
	}
	ret = ft_strdup(str);
	return (ret);
}

char	*replacestr(char *dest, char *flag, char *content)
{
	char	*after_flag;
	char	*temp;

	if (!(after_flag = ft_strstr(dest, flag)))
		return (dest);
	after_flag = &after_flag[ft_strlen(flag)];
	if (!(temp = (char*)malloc(sizeof(char) *
					((ft_strlen(dest) - ft_strlen(after_flag)) + ft_strlen(content) + 1))))
		return (0);
	ft_strcat(temp, ft_strndup(dest, ft_strlen(dest) - ft_strlen(after_flag) - ft_strlen(flag)));
	if (content)
		ft_strcat(temp, content);
	else if (flag[ft_strlen(flag) - 1] == 's')
		ft_strcat(temp, "(null)");
	ft_strcat(temp, after_flag);
	dest = temp;
	return (dest);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	int			i;
	int			j;
	char		*flag;
	char		*conversion;
	char		*ret;
	int			idx;

	setlocale(LC_ALL, "");
	if (!format)
		return (0);
	i = 0;
	flag = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			flag = get_flag((char*)&format[i]);
			ret = handle_flags(flag, &args);
			conversion = handle_conversion(flag, ret);
			format = replacestr((char*)format, flag, conversion);
			if (flag[ft_strlen(flag) - 1] == 'S')
			{
				idx = get_index(conversion, ret);
				j = 0;
				while ((size_t)j < ft_strlen(conversion))
				{
					if (j == idx)
					{
						/*
							Maintent recuperer le contenu du wchar et l'afficher ...
						*/
						ft_putstr(ret);
						//ft_wputstr(L"我是一只猫。");
						j += ft_strlen(ret) - 1;
					}
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
			ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	//ft_putstr(format);
	return (ft_strlen(format));
}
