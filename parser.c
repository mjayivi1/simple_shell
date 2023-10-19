#include "main.h"

/**
 * parser - parsers a buffer with a delimiter
 * @arguments: buffer to parser
 * @delimiter: delimiter to parser along
 *
 * Return: pointer to an array of pointers to the tokens
 */
char **parser(char *arguments, char *delimiter)
{
	char **tokens = NULL;
	size_t i = 0, count = 10;

	if (arguments == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * count);
	if (tokens == NULL)
	{
		perror("Fatal Error");
		return (NULL);
	}
	while ((tokens[i] = _strtok(arguments, delimiter)) != NULL)
	{
		i++;
		if (i == count)
		{
			tokens = _realloc(tokens, &count);
			if (tokens == NULL)
			{
				perror("Fatal Error");
				return (NULL);
			}
		}
		arguments = NULL;
	}
	return (tokens);
}
