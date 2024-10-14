/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdel-fra <rdel-fra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:55:04 by rdel-fra          #+#    #+#             */
/*   Updated: 2024/10/14 17:09:33 by rdel-fra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_rside(char const *ptrs1, char const *ptrset, int i);
int	ft_lside(char const *ptrs1, char const *ptrset);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptrim;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (s1[i] != '\0')
		i++;
	k = ft_lside(s1, set);
	i = ft_rside(s1, set, i);
	j = 0;
	ptrim = (char *)malloc(((i - k) + 1) * sizeof(char));
	if (!ptrim)
		return (NULL);
	while (k < i)
	{
		ptrim[j] = s1[k];
		j++;
		k++;
	}
	ptrim[j] = '\0';
	return (ptrim);
}

int	ft_rside(char const *ptrs1, char const *ptrset, int i)
{
	int	j;

	j = 0;
	while (ptrset[j] != '\0')
	{
		if (ptrs1[i - 1] == ptrset[j])
		{
			i--;
			j = 0;
		}
		j++;
	}
	return (i);
}

int	ft_lside(char const *ptrs1, char const *ptrset)
{
	int	j;
	int	k;

	k = 0;
	j = 0;
	while (ptrset[j] != '\0')
	{
		if (ptrs1[k] == ptrset[j])
		{
			k++;
			j = -1;
		}
		j++;
	}
	return (k);
}
