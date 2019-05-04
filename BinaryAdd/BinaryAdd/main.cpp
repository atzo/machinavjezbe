#include<iostream>

int binaryAdd(int a, int b) 
{
	int xorBroj;
	do {
		xorBroj = a ^ b;
		b = (a & b) <<1;		
		a = xorBroj;
	} while (b != 0);	
	return xorBroj;
}

int main()
{
	std::cout << "Zbrajanje: 214748 + 7172483" << std::endl;
	std::cout << binaryAdd(214748, 7172483) << " = " << 214748 + 7172483 << std::endl << std::endl;

	std::cout << "Zbrajanje sa minus brojevima: 214748 + (-7172483)" << std::endl;
	std::cout << binaryAdd(214748, -7172483) << " = " << 214748 + (-7172483) << std::endl << std::endl;

	std::cout << "Zbrajanje kada je rezultat prevelik: 2147483052 + 2147483011" << std::endl;
	std::cout << binaryAdd(2147483052, 2147483011) << " = " << 2147483052 + 2147483011 << std::endl << std::endl;

	std::cin.get();
}