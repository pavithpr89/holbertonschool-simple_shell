#include <stdio.h>

int main(void)
{
	char *path;

	path = _getenv("PATH");
	if (path)
		printf("PATH=%s\n", path);
	else
		printf("PATH not found\n");

	return (0);
}
