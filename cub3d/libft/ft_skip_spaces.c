/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 12:54:14 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/12 16:51:23 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_skip_spaces(char *str, int i)
{
	int	j;

	j = 0;
	while (ft_is_whitespace(str[i + j]))
		j++;
	return (j);
}
