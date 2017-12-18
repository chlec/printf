/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 15:09:10 by clecalie          #+#    #+#             */
/*   Updated: 2017/12/18 15:14:46 by clecalie         ###   ########.fr       */
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
					((ft_strlen(dest) - ft_strlen(after_flag)) + ft_strlen(content) + 1000))))
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

int		check_flag(char **str, char *flag)
{
	char	*validchar;
	int		i;

	i = (int)ft_strlen(flag) - 1;
	validchar = " +-#0123456789.sSpdDioOuUxXcChljzi%";
	while (flag[i] && ft_strchr(validchar, flag[i]))
		i--;
	if (i > 0 || ft_strlen(flag) == 1)
	{
		if (i < 0)
			i = 0;
		*str = replacestr(*str, ft_strndup(flag, (i > 0 ? i : (size_t)ft_strlen(flag))), "");
		return (0);
	}
	return (1);
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
	int				h;
	char			*flag;
	char			*conversion;
	char			*ret;
	int				idx;
	unsigned char	nb;
	char			*temp;
	char			*temp2;
	char			flag_letter;
	char			*str;
	char			*length_f;

	str = ft_strdup((char*)format);
	setlocale(LC_ALL, "");
	if (!format)
		return (0);
	i = 0;
	flag = 0;
	temp = 0;
	va_start(args, format);
	while (str[i])
	{
		flag = get_flag(&str[i]);
		if (str[i] == '%' && check_flag(&str, flag))
		{	
			length_f = get_length_flag(flag);
			ret = handle_flags(length_f, flag, &args);
			flag_letter = flag[ft_strlen(flag) - 1];
			if (ret == NULL && (flag_letter == 's' || flag_letter == 'S'))
			{
				ret = "(null)";
			}
			else if (ret[0] == '\0'  && ft_strchr("cC", flag_letter))
			{
				temp = "@";
				ret = "@";
			}
			else if  (ft_strchr("SC", flag_letter) && !ft_strequ(ret, "(null)"))
			{
				temp = ft_strdup(ret);
				ret = ft_strndup(ret, ft_strlen(ret) / 3);
				temp2 = ft_strdup(ret);
			}
			conversion = handle_conversion(flag, ret);	
			str = replacestr(str, flag, conversion);
			if (ft_strchr("SC", flag_letter) && !ft_strequ(ret, "(null)"))
			{
				idx = get_index(conversion, ret);
				j = 0;
				while ((size_t)j < ft_strlen(conversion))
				{
					if (j == idx)
					{
						h = 0;
						while (temp[h])
						{
							if (h % 3 == 0)
							{
								nb = (unsigned char)ft_atoi(ft_strndup(&temp[h], 3));
								write(1, &nb, 1);
							}
							h++;
						}
						j += ft_strlen(ret) - 1;
					}
					else
						ft_putchar(conversion[j]);
					j++;
				}
			}
			else if (flag_letter == 'c' && temp && temp[0] == '@')
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
