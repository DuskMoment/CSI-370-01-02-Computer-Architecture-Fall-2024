#include <iostream>
extern "C" void asmMain();
extern "C" int testFunc()
{
	int num = 0;
	std::cout << "Please input a number" << std :: endl;
	std::cin >> num;

	return num;
};

int main()
{
	asmMain();
	return 0;
}