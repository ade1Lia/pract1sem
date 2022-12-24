#include <iostream>
#include <math.h>

void output_number(unsigned short number) {
	unsigned short num = 0;
	for (int i = 0; i < 6; i++) {
		int b = (number >> i) & 0b0000000000000001;
		num += b * pow(2, i * b);
	}
	std::cout << num << std::endl;
	number = number >> 6;
	num = 0;
	for (int i = 0; i < 6; i++) {
		int b = (number >> i) & 0b0000000000000001;
		num += b * pow(2, i * b);
	}
	std::cout << num << std::endl;
	
}



unsigned short input_number(unsigned short number) {				//numbers 0-63. 6 bits. 2^6=64
	unsigned short box = 0b0000000000000000;
	box = box | number;
	box = box | (number << 6);
	std::cout << "number in bytes ";
	for (int i = 15; i >= 0; --i)
		std::cout << ((box >> i) & 0b0000000000000001);
	std::cout << std::endl << std::endl;
	return box;
}

int main()
{
	unsigned short a;
	std::cin >> a;
	std::cout << std::endl;
	input_number(a);
	std::cout << std::endl;
	output_number(input_number(a));



	return 0;
}