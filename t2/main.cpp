#include <iostream>
#include <stdio.h>


int charToint(char c) {
	return c - '0';
}

void sum(int a[], int b[], int size_a, int size_b) {

	int res[1001] = { 0 };
	res[0] = -5;
	if (size_a == size_b) {
		for (int i = size_a - 1; i >= 0; i--) {
			res[i + 1] += a[i] + b[i];
			if (res[i + 1] > 9) {
				res[i] = 1;
				res[i + 1] = res[i + 1] - 10;
			}	
		}

		if (res[0] != -5) {
			for (int i = 0; i <= size_a; i++) {
				std::cout << res[i];
			}
		}
		else for (int i = 1; i <= size_a; i++) {
			std::cout << res[i];
		}

	}
	else if (size_a < size_b) {
		int j = size_b - size_a;
		for (int i = size_b - 1; i >= 0; i--) {
			if (size_b - 1 - j < 0) {
				res[i + 1] += b[i] ;
			}
			else {
				res[i + 1] += a[size_b - 1 - j] + b[i] ;
				j++;
			}
			if (res[i + 1] > 9) {
				res[i] = 1;
				res[i + 1] = res[i + 1] - 10;
			}	
		}
		if (res[0] != -5) {
			for (int i = 0; i <= size_b; i++) {
				std::cout << res[i];
			}
		}
		else for (int i = 1; i <= size_b; i++) {
			std::cout << res[i];
		}
	}
	else if (size_a > size_b) {
		int j = size_a - size_b;
		for (int i = size_a - 1; i >= 0; i--) {
			if (size_a - 1 - j < 0) {
				res[i + 1] += a[i];
			}
			else {
				res[i + 1] += a[i] + b[size_a - 1 - j];
				j++;
			}
			if (res[i + 1] > 9) {
				res[i] = 1;
				res[i + 1] = res[i + 1] - 10;
			}
		}

		if (res[0] != -5) {
			for (int i = 0; i <= size_a; i++) {
				std::cout << res[i];
			}
		}
		else for (int i = 1; i <= size_a; i++) {
			std::cout << res[i];
		}
	}
	
}


void multiplication(int a[], int b[], int len_1, int len_2) {

	int mult[2000] = {};
	int carry = 0;
	int carryd = 0;
	int k = 0;

	for (int i = 0; i < len_2; i++) {
		k = i;
		for (int j = 0; j <= len_1; j++) {
			if (j == len_1) {
				mult[k] = carry;
			}
			else {
				if (j == 0) {
					carry = 0;
				}
				carryd = mult[k];
				mult[k] = (b[len_2 - 1 - i] * a[len_1 - 1 - j] + mult[k] + carry) % 10;
				carry = (b[len_2 - 1 - i] * a[len_1 - 1 - j] + carryd + carry) / 10;
				k += 1;
			}
		}

	}
	if (carry != 0) {
		std::cout << carry;
	}

	for (int i = len_1 + len_2 - 2; i >= 0; i--) {
		std::cout << mult[i];
	}

}


int main()
{

	char num_1[1000] = { '\0' };
	char num_2[1000] = { '\0' };
	int num1[1000] = { 0 };
	int num2[1000] = { 0 };


	std::cout << "input number A.\nafter entering A, input number B\n";
	gets_s(num_1, 1000);
	std::cout << std::endl;
	gets_s(num_2, 1000);
	std::cout << std::endl;


	for (int i = 0; i < strlen(num_1); i++) {
		num1[i] = charToint(num_1[i]);
	}
	for (int i = 0; i < strlen(num_2); i++) {
		num2[i] = charToint(num_2[i]);
	}

	sum(num1, num2, strlen(num_1),strlen(num_2));

	std::cout << std::endl;
	std::cout << std::endl;

	multiplication(num1, num2, strlen(num_1), strlen(num_2));


	return 0;
}