#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
	char name[101], brand[101];
	int units_left;
	double price;
} product_t;

void product_update(product_t*);
void read_line(char[], int);
int str_to_int(char[]);
int my_pow(int, int);

int main(void) {
	product_t product;
	read_line(product.name, 101);
	read_line(product.brand, 101);
	char units_left_str[101];
	read_line(units_left_str, 101);
	product.units_left = str_to_int(units_left_str);
	char price_str[101];
	read_line(price_str, 101);
	sscanf(price_str, "%lf", &product.price);
	
	product_update(&product);
	
	printf("Name: %s\nBrand: %s\nUnits left: %d\nPrice: $%.2f\n", product.name, product.brand, product.units_left, product.price);

	return 0;
}

void product_update(product_t *p) {
	p->units_left *= 2;
	p->price *= 0.8;
}

void read_line(char str[], int len) {
	fgets(str, len, stdin);
	while(str[strlen(str) - 1] == '\n' || str[strlen(str) - 1] == '\r')
		str[strlen(str) - 1] = '\0';
	scanf(" ");
}

int str_to_int(char str[]) {
	int n = 0;
	int len = strlen(str);
	for(int i = 0; i < len; i++)
		n += (str[i] - '0') * my_pow(10, len - i - 1);
	return n;
}

int my_pow(int a, int b) {
	if(b <= 0)
		return 1;
	return a * my_pow(a, b - 1);
}