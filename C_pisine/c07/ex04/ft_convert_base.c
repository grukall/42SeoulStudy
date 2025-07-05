/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:04:23 by seungule          #+#    #+#             */
/*   Updated: 2023/02/01 22:47:59 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int	basevalid_check(char *base);
long int	baselen_check(char *base);
long int	cgnum(char *str, char *base);
int			change_int(char stri, char *base);

long int	ft_atoi_base(char *str, char *base)
{
	long int	basevalid;
	long int	sign;
	long int	result;

	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	basevalid = basevalid_check(base);
	if (basevalid)
	{
		result = cgnum(str, base);
		return (result * sign);
	}
	else
	{
		base = NULL;
		return (0);
	}
}

long int	basevalid_check(char *base)
{
	long int	num;
	long int	index;
	long int	base_len;

	base_len = baselen_check(base);
	num = 0;
	if (base_len <= 1)
		return (0);
	while (num < base_len)
	{
		if (base[num] == '+' || base[num] == '-')
			return (0);
		if ((base[num] >= 9 && base[num] <= 13) || base[num] == ' ')
			return (0);
		index = num + 1;
		while (index < base_len)
		{
			if (base[num] == base[index])
				return (0);
			index++;
		}
		num++;
	}
	return (1);
}

long int	baselen_check(char *base)
{
	long int	num;

	num = 0;
	while (base[num])
		num++;
	return (num);
}

long int	cgnum(char *str, char *base)
{
	long int	i;
	long int	result;
	long int	base_len;

	base_len = baselen_check(base);
	i = 0;
	result = 0;
	while (i != base_len)
	{
		i = 0;
		while (i < base_len)
		{
			if (*str == base[i])
			{
				result = result * base_len + change_int(*str, base);
				str++;
				break ;
			}
			i++;
		}
	}
	return (result);
}

int	change_int(char stri, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (stri == base[i])
			return (i);
		i++;
	}
	return (0);
}
