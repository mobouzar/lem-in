/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobouzar <mobouzar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 00:55:05 by mobouzar          #+#    #+#             */
/*   Updated: 2020/02/08 10:41:55 by mobouzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	if (!(str = ft_strnew(len)))
		return (0);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	return (str);
}
