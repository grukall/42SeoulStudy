/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 16:56:55 by seunlee2          #+#    #+#             */
/*   Updated: 2023/02/02 00:44:07 by seungule         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFO_H
# define INFO_H

typedef struct s_map_info
{
	int		x;
	int		y;
	char	dot;
	char	block;
	char	answer;
	int		res_x;
	int		res_y;
	int		res_size;
}t_map_info;

#endif
