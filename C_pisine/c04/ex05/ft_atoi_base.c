/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 21:13:26 by seungule          #+#    #+#             */
/*   Updated: 2023/01/29 00:23:00 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	basevalid_check(char *base, long int base_len);
long int	baselen_check(char *base);
long int	cgnum(char *str, char *base, long int base_len);
int			change_int(char stri, char *base);

int	ft_atoi_base(char *str, char *base)
{
	long int	base_len;
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
	base_len = baselen_check(base);
	basevalid = basevalid_check(base, base_len);
	if (basevalid)
	{
		result = cgnum(str, base, base_len);
		return (result * sign);
	}
	else
		return (0);
}

long int	basevalid_check(char *base, long int base_len)
{
	long int	num;
	long int	index;

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

long int	cgnum(char *str, char *base, long int base_len)
{
	long int	i;
	long int	result;
	int			flag;

	i = 0;
	result = 0;
	flag = 0;
	while (1)
	{
		while (i < base_len)
		{
			if (*str == base[i])
			{
				result = result * base_len + change_int(*str, base);
				str++;
				flag = 1;
			}
			i++;
		}
		if (flag == 0)
			break ;
		i = 0;
		flag = 0;
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
