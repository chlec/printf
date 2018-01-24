/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <strings.h>
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}
char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (!needle[0])
		return ((char*)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i] && needle[j] && haystack[i] == needle[j])
		{
			i++;
			j++;
		}
		if (!needle[j])
			return ((char*)&haystack[i - j]);
		i -= j;
		i++;
	}
	return (0);
}
char	*replace_chars(char *dest, char *find, char *content)
{
	char		*part;
	size_t		i;
	size_t		j;
	size_t      length;
	char		*part2;

	part = ft_strstr(dest, find);
	part2 = &part[ft_strlen(find)];
	length = ft_strlen(dest) - ft_strlen(part);
	i = length;
	j = 0;
	while (i - length < ft_strlen(find))
		if (content[j])
			dest[i++] = content[j++];
		else
			break;
	j = 0;
	while (part2[j])
		dest[i++] = part2[j++];
	dest[i] = '\0';
	return (dest);
}

int main()
{
    char    t[] = "testmouahhhhhabcd";
    replace_chars(t, "test", "");
    printf("%s\n", t);

    return 0;
}
