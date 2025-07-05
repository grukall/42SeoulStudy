#include <stdio.h>

extern int* ft_map(int *tab, int length, int (*f)(int));

int func(int a) {
	return (2 * a);
}

int main() {
	int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; i++) {
		printf("%d ", tab[i]);
	}
	printf("\n");

	int* arr = ft_map(tab, 10, &func);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
