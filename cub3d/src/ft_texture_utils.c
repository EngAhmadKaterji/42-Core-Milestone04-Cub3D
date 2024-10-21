/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:12:06 by akaterji          #+#    #+#             */
/*   Updated: 2024/09/19 17:36:09 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_clear_txtr(t_texture **txtr_list)
{
	t_texture	*cur_txtr;

	while (*txtr_list)
	{
		cur_txtr = *txtr_list;
		*txtr_list = (*txtr_list)->next;
		if (cur_txtr->key)
			free(cur_txtr->key);
		if (cur_txtr->value)
			free(cur_txtr->value);
		free(cur_txtr);
	}
	*txtr_list = NULL;
}

void	ft_new_txtr(char *str, t_texture *new_txtr)
{
	int	i;

	i = 0;
	new_txtr->key = NULL;
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	if (!ft_strncmp(str + i, "NO", 2) || !ft_strncmp(str + i, "SO", 2)
		|| !ft_strncmp(str + i, "WE", 2) || !ft_strncmp(str + i, "EA", 2)
		|| !ft_strncmp(str + i, "CP", 2) || !ft_strncmp(str + i, "FP", 2))
	{
		new_txtr->key = ft_substr(str, i, 2);
		i += 2;
	}
	else if (!ft_strncmp(str + i, "C", 1) || !ft_strncmp(str + i, "F", 1))
	{
		new_txtr->key = ft_substr(str, i, 1);
		i++;
	}
	while (str[i] && ft_is_whitespace(str[i]))
		i++;
	new_txtr->value = ft_substr(str, i, ft_strlen(str) - i -1);
	new_txtr->next = NULL;
}

void	ft_add_back_txtr(t_texture **txtr_list, t_texture *new_txtr)
{
	t_texture	*tmp_txtr;

	if (!new_txtr)
		return ;
	if (!*txtr_list)
		*txtr_list = new_txtr;
	else
	{
		tmp_txtr = *txtr_list;
		while (tmp_txtr && tmp_txtr->next)
			tmp_txtr = tmp_txtr->next;
		tmp_txtr->next = new_txtr;
	}
}
