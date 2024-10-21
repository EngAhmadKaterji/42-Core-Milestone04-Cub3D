/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array_to_y.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:15:11 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/03 12:16:11 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array_to_y(char **array, int y)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array && i < y && array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
