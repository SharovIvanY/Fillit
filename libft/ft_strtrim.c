/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbashiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 14:59:27 by jbashiri          #+#    #+#             */
/*   Updated: 2018/12/13 05:54:50 by jbashiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_flag(const char *s)
{
	int		flag;
	int		x;

	flag = 0;
	x = 0;
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
	{
		x++;
		if (s[x] == 0)
			flag = 1;
	}
	return (flag);
}

static int	f_x(const char *s)
{
	int		x;

	x = 0;
	while (s[x] == ' ' || s[x] == '\n' || s[x] == '\t')
		x++;
	return (x);
}

static int	f_len_str(char const *s, int flag, int x)
{
	int		len;

	len = 0;
	while (s[x] != 0 && flag == 0)
	{
		len++;
		x++;
	}
	len--;
	x--;
	while ((s[x] == ' ' || s[x] == '\n' || s[x] == '\t') && flag == 0)
	{
		x--;
		len--;
	}
	return (len);
}

static int	f_x_s(char const *s, int flag, int x)
{
	int		len;

	len = 0;
	while (s[x] != 0 && flag == 0)
	{
		len++;
		x++;
	}
	len--;
	x--;
	while ((s[x] == ' ' || s[x] == '\n' || s[x] == '\t') && flag == 0)
	{
		x--;
		len--;
	}
	return (x);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		x;
	int		len;
	int		flag;

	if (!s)
		return (NULL);
	flag = f_flag(s);
	x = f_x(s);
	len = f_len_str(s, flag, x);
	x = f_x_s(s, flag, x);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (flag == 1)
		str[0] = 0;
	str[len + 1] = 0;
	while (len >= 0)
		str[len--] = s[x--];
	return (str);
}
