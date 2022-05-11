/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   functions.c 										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: atrilles <atrilles@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2022/04/22 17:40:41 by atrilles		  #+#	#+#			 */
/*   Updated: 2022/04/22 17:41:03 by atrilles		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "../pipex.h"

int str_len(char const *str)
{
    int len;

	if (str == 0)
		return 0;
    len = 0;
    while (str[len])
        len++;
    return len;
}

char	*str_join(char *s1, char *s2)
{
	char		*res;
	int			i;
	int			j;
	const char	*s = "";

	if (s1 == 0)
		s1 = (char *)s;
	res = malloc((str_len(s1) + str_len(s2) + 1) * sizeof(char));
	if (res == 0)
		return (0);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = -1;
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = 0;
	return (res);
}

char    *emptystr()
{
    char    *res;

    res = malloc(sizeof(char));
    res[0] = 0;
    return res;
}

char	*sub_str(char const *s, unsigned int start, size_t len)
{
    char    *res;
    int i;

    i = 0;
    if (s == 0)
        return (0);
    if ((int)start > str_len((char *)s))
        return (emptystr());
    if (len > str_len((char *)s) - start)
        res = malloc((str_len((char *)s) - start + 1) * sizeof(char));
    else
        res = malloc((len + 1) * sizeof(char));
    if (res == 0)
        return 0;
    while (s[start + i] && i < (int)len)
    {
        res[i] = s[start + i];
        i++;
    }
    res[i] = 0;
    return (res);
}

int str_n_cmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		res;

	i = 0;
	res = 0;
	while (i < n)
	{
		res = s1[i] - s2[i];
		if (res != 0)
			return (res);
		if (s1[i] == 0 || s2[i] == 0)
			return (0);
		i++;
	}
	return (res);
}
