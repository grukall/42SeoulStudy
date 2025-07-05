/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:06:39 by seungule          #+#    #+#             */
/*   Updated: 2023/02/01 22:48:16 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long int		ft_atoi_base(char *str, char *base);
long int		baselen_check(char *base);
long int		basevalid_check2(char *base, long int base_len);
char			*cgnum2(long nbrk, char *base, int sign, char *result);
long int		base_index(long int nbrk, long int base_len);
char			*re(long nbrk, long base_i, char *result, char *base);

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	base_len;
	long int	basevalid;
	int			sign;
	long int	nbrk;
	char		*result;

	nbrk = ft_atoi_base(nbr, base_from);
	result = NULL;
	if (nbrk < 0)
	{
		sign = -1;
		nbrk *= -1;
	}
	base_len = baselen_check(base_to);
	basevalid = basevalid_check2(base_to, base_len);
	if (base_from == NULL || basevalid == 0)
		return (NULL);
	if (basevalid)
		result = cgnum2(nbrk, base_to, sign, result);
	return (result);
}

long int	basevalid_check2(char *base, long int base_len)
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

char	*cgnum2(long int nbrk, char *base, int sign, char *result)
{
	long int	base_i;
	long int	num;
	long int	base_len;

	base_len = baselen_check(base);
	num = base_index(nbrk, base_len);
	if (sign < 0)
	{
		result = (char *)malloc(sizeof(char) * (num + 2));
		result[0] = '-';
	}
	else
		result = (char *)malloc(sizeof(char) * (num + 1));
	if (result == 0)
		return (0);
	base_i = 1;
	while (num > 1)
	{
		base_i *= base_len;
		num--;
	}
	result = re(nbrk, base_i, result, base);
	return (result);
}

long int	base_index(long int nbrk, long int base_len)
{
	long int	num;
	long int	result;

	num = 0;
	result = 1;
	while (nbrk != 0)
	{
		nbrk /= base_len;
		num++;
	}
	return (num);
}

char	*re(long nbrk, long base_i, char *result, char *base)
{
	char	temp;
	int		i;
	long	base_len;

	base_len = baselen_check(base);
	if (result[0] == '-')
		i = 1;
	else
		i = 0;
	while (base_i > 0)
	{
		temp = base[nbrk / base_i];
		result[i] = temp;
		nbrk %= base_i;
		base_i /= base_len;
		i++;
	}
	result[i] = '\0';
	return (result);
}
