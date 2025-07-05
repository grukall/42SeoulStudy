/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungule <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:31:57 by seungule          #+#    #+#             */
/*   Updated: 2023/01/19 22:23:40 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned char	change_int(unsigned int a);
void			print_adress(unsigned long long memory_adress, char mem[16]);
void			*ft_print_memory(void *str, unsigned int size);
void			print_char(char *str, unsigned int size, unsigned int index);
void			print_str(char *str, unsigned int size, unsigned int index);

void	*ft_print_memory(void *str, unsigned int size)
{
	unsigned long long	memory_adress;
	char				mem[16];
	unsigned int		i;
	unsigned int		j;

	i = 0;
	j = 0;
	memory_adress = (unsigned long long)str;
	if (size == 0)
		return (str);
	while (i++ < 16)
		mem[i - 1] = '0';
	i = 0;
	while (i <= size / 16)
	{
		print_adress(memory_adress + (16 * i), mem);
		write(1, mem, 16);
		print_char((char *)str + (16 * i), size, j + (16 * i));
		print_str((char *)str + (16 * i), size, j + (16 * i));
		write(1, "\n", 1);
		i++;
	}
	return (str);
}

unsigned char	change_int(unsigned int temp)
{
	unsigned char	b;

	if (temp >= 10 && temp <= 15)
		b = temp + 87;
	else
		b = temp + '0';
	return (b);
}

void	print_adress(unsigned long long memory_adress, char mem[16])
{
	unsigned int		i;
	unsigned long long	temp;

	i = 0;
	while (i < 16)
	{
		mem[i] = '0';
		i++;
	}
	i = 0;
	while (memory_adress != 0)
	{
		temp = memory_adress % 16;
		memory_adress = memory_adress / 16;
		mem[15 - i] = change_int(temp);
		i++;
	}
}

void	print_char(char *str, unsigned int size, unsigned int index)
{
	unsigned int	i;
	unsigned int	left;
	unsigned int	right;
	char			char_num[2];

	i = 0;
	write(1, ":", 1);
	while (i < 16)
	{
		if (i % 2 == 0)
			write(1, " ", 1);
		if (index < size)
		{
			left = *(str + i) / 16;
			right = *(str + i) % 16;
			char_num[0] = change_int(left);
			char_num[1] = change_int(right);
			write(1, char_num, 2);
		}
		else
			write(1, "  ", 2);
		i++;
		index++;
	}
}

void	print_str(char *str, unsigned int size, unsigned int index)
{
	unsigned int	i;
	unsigned char	a;

	i = 0;
	write(1, " ", 1);
	while (i < 16 && index < size)
	{
		a = *(str + i);
		if (a < 32 || a > 126)
			write(1, ".", 1);
		else
			write(1, &a, 1);
		i++;
		index++;
	}
}

#include <stdio.h>
int main()
{//ex12
	printf("< ex12 >\n");
	char	c12[] = "Bonjour les aminches\t\n\tc  est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	
	printf("----------answer----------\n");
	printf("%s\n", "00007ffee16ab3e0: 426f 6e6a 6f75 7220 6c65 7320 616d 696e Bonjour les amin\n00007ffee16ab3f0: 6368 6573 090a 0963 2020 6573 7420 666f ches...c  est fo\n00007ffee16ab400: 7509 746f 7574 0963 6520 7175 206f 6e20 u.tout.ce qu on \n00007ffee16ab410: 7065 7574 2066 6169 7265 2061 7665 6309 peut faire avec.\n00007ffee16ab420: 0a09 7072 696e 745f 6d65 6d6f 7279 0a0a ..print_memory..\n00007ffee16ab430: 0a09 6c6f 6c2e 6c6f 6c0a 2000           ..lol.lol. .");
	printf("-------------------------\n");
	ft_print_memory((void *)c12, sizeof(c12));
	printf("----------output----------\n");
	return (0);
}
