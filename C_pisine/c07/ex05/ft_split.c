/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <seungule@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:44:08 by seungule          #+#    #+#             */
/*   Updated: 2023/01/31 17:10:39 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_charset(char c, char *sep);
int		count_words(char *str, char *charset);
char	*make_str(char *str, char *charset);

char	**ft_split(char *str, char *charset)
{
	int		str_count;
	int		str_arr_index;
	char	**str_arr;
	int		i;

	i = 0;
	str_arr_index = 0;
	str_count = count_words(str, charset);
	str_arr = (char **)malloc((str_count + 1) * sizeof(char *));
	while (str[i])
	{
		while (str[i] && is_charset(str[i], charset))
			i++;
		if (str[i] && !is_charset(str[i], charset))
		{
			str_arr[str_arr_index] = make_str(str + i, charset);
			str_arr_index++;
		}
		while (str[i] && !is_charset(str[i], charset))
			i++;
	}
	str_arr[str_arr_index] = 0;
	return (str_arr);
}

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (is_charset(str[i], charset) && !is_charset(str[i + 1], charset))
			count++;
		i++;
	}
	return (count);
}

char	*make_str(char *str, char *charset)
{
	int		str_len;
	int		i;
	char	*new_str;

	str_len = 0;
	i = 0;
	while (*(str + str_len) && !is_charset(*(str + str_len), charset))
		str_len++;
	if (str_len == 0)
		return (0);
	new_str = (char *)malloc(str_len * sizeof(char) + 1);
	while (i < str_len)
	{
		new_str[i] = *str;
		i++;
		str++;
	}
	new_str[i] = 0;
	return (new_str);
}
