/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:31:13 by seungule          #+#    #+#             */
/*   Updated: 2023/01/19 11:59:55 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strupsize(char *ch);

char	*ft_strcapitalize(char *str)
{
	char	*ch;

	ch = str;
	while (*ch)
	{
		if (ch == str || *(ch - 1) < '0')
			ft_strupsize(ch);
		else if (*(ch - 1) > '9' && *(ch - 1) < 'A')
			ft_strupsize(ch);
		else if (*(ch - 1) > 'Z' && *(ch - 1) < 'a')
			ft_strupsize(ch);
		else if (*(ch - 1) > 'z')
			ft_strupsize(ch);
		else if (*ch >= 'A' && *ch <= 'Z')
			*ch += 32;
		ch++;
	}
	return (str);
}

void	ft_strupsize(char *ch)
{
	if (*ch >= 'a' && *ch <= 'z')
	{
		*ch -= 32;
	}
}
