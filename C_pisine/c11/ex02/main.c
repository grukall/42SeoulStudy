#include <stdio.h>
#include <string.h>

extern int ft_any(char** tab, int (*f)(char*));

int	func(char* str) {
	return strcmp(str, "abc") == 0;
}

int main() {
	char* tab[4] = {"hello", "world", "bye", 0};
	printf("%d\n", ft_any(tab, &func));

	char* tab2[4] = {"hello", "world", "abc", 0};
	printf("%d\n", ft_any(tab2, &func));

	char* tab3[4] = {"hello", "abc", "abc", 0};
	printf("%d\n", ft_any(tab3, &func));
	
	return 0;
}
