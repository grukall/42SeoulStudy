/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 21:57:07 by seungule          #+#    #+#             */
/*   Updated: 2023/01/17 22:29:07 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*ch;

	ch = str;
	while (*ch)
	{
		if (*ch >= 'a' && *ch <= 'z')
		{
			*ch -= 32;
		}
		ch++;
	}
	return (str);
}
