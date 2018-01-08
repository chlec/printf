/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacestr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clecalie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:51:09 by clecalie          #+#    #+#             */
/*   Updated: 2018/01/08 15:55:46 by clecalie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*replacestr(char *dest, char *flag, char *content)
{
	char	*after_flag;
	char	*temp;

	if (!(after_flag = ft_strstr(dest, flag)))
		return (dest);
	after_flag = &after_flag[ft_strlen(flag)];
	if (!(temp = (char*)malloc(sizeof(char) *
					((ft_strlen(dest) - ft_strlen(after_flag))
					 + ft_strlen(content) + 1000))))
		return (0);
	ft_strcat(temp, ft_strndup(dest, ft_strlen(dest)
				- ft_strlen(after_flag) - ft_strlen(flag)));
	if (content)
		ft_strcat(temp, content);
	else if (flag[ft_strlen(flag) - 1] == 's')
		ft_strcat(temp, "(null)");
	ft_strcat(temp, after_flag);
	dest = temp;
	return (dest);
}
