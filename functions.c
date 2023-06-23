#include "main.h"
/**
 * _realloc -- reallocates memory
 * @ptr: pointer
 * @ptr_size: size of pointer
 *
 * Return: void
 */
void *_realloc(void *ptr, size_t ptr_size)
{
	char *src;
	char *dest;
	size_t i = 0;
	void *new_ptr;

	if (ptr_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(sizeof(size_t) * ptr_size);

	if (new_ptr != NULL)
	{
		if (ptr != NULL)
		{
			src = ptr;
			dest = new_ptr;

			for (; i < ptr_size; i++)
			{
				dest[i] = src[i];
			}
			free(ptr);
		}
	}
	return (new_ptr);
}
