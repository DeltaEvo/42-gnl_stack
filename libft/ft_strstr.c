/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:40:40 by dde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 15:15:07 by dde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*o_needle = needle;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && *needle)
		if (*haystack++ == *needle)
			needle++;
		else
		{
			haystack -= needle - o_needle;
			needle = o_needle;
		}
	return (*needle ? 0 : (char *)(haystack - (needle - o_needle)));
}
