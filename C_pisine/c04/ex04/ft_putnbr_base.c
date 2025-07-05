/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrk_base.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:30:17 by seungule          #+#    #+#             */
/*   Updated: 2023/01/31 13:40:54 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

long int		baselen_check(char *base);
long int		basevalid_check(char *base, long int base_len);
void			cgnum(long int nbrk, char *base, long int base_len, int sign);
long int		base_index(long int nbrk, long int base_len);

void	ft_putnbr_base(int nbr, char *base)
{
	long int	base_len;
	long int	basevalid;
	int			sign;
	long int	nbrk;

	sign = 1;
	nbrk = (long int)nbr;
	if (nbrk < 0)
	{
		sign = -1;
		nbrk = (long int)nbr * -1;
	}
	base_len = baselen_check(base);
	basevalid = basevalid_check(base, base_len);
	if (basevalid)
		cgnum(nbrk, base, base_len, sign);
}

long int	baselen_check(char *base)
{
	long int	num;

	num = 0;
	while (base[num])
		num++;
	return (num);
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

void	cgnum(long int nbrk, char *base, long int base_len, int sign)
{
	long int	i;
	char		temp;
	long int	base_i;

	i = 0;
	base_i = base_index(nbrk, base_len);
	if (sign < 0)
		write(1, "-1", 1);
	while (i < base_i)
	{
		temp = base[nbrk / base_i];
		write(1, &temp, 1);
		nbrk %= base_i;
		base_i /= base_len;
	}
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
	while (num > 1)
	{
		result *= base_len;
		num--;
	}
	return (result);
}
