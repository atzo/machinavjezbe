#include <iostream>

void kalkulator() {
	int a;
	int b;
	char op;

	while (true) {
		std::cout << "Uneseite operator: ";
		std::cin >> op;
		std::cout << std::endl;

		if (op == 'q')
			break;

		std::cout << "Uneseite prvi broj: ";
		std::cin >> a;
		std::cout << std::endl;

		std::cout << "Uneseite drugi broj: ";
		std::cin >> b;
		std::cout << std::endl;

		if (op == '+') 
		{
			std::cout << "rezultat je: " << a+b << std::endl;
		} else if (op == '-') 
		{
			std::cout << "rezultat je: " << a - b << std::endl;
		}
		else if (op == '*')
		{
			std::cout << "rezultat je: " << a * b << std::endl;
		}
		else if (op == '/')
		{
			if (b == 0) 
			{
				std::cout << "greška deljenje s nulom!" << std::endl;
			}
			else
			{
				std::cout << "rezultat je: " << a / b << std::endl;
			}
		}
	}
}

void fibonachi(int f, int g, int count) {
	if (count > 0) {
		std::cout << f << " " ;
		fibonachi(g, f+g, count - 1);
	}
}

int main()
{
	int userEntry;
	int userEntry2;
	int userEntry3;

	/*std::cout << "Uneseite broj: " << std::endl;
	std::cin >> userEntry;	
	std::cout << "Uneseni broj je " << userEntry << std::endl;

	std::cin.clear();
	std::cin.ignore(1000,"\n");

	std::cout << "Uneseite broj: " << std::endl;
	std::cin >> userEntry;
	std::cout << "Uneseni broj je " << userEntry << std::endl;*/

	//Napraviti program koji od korisnika zahtjeva uno 3 integera ipa podataka,
	//te odna ispisuje onoga koji je najveci te ga ispisuje u konzolu;



/*	std::cout << "Uneseite prvi broj: " << std::endl;
	std::cin >> userEntry;

	std::cout << "Uneseite drugi broj: " << std::endl;
	std::cin >> userEntry2;
    
	if (userEntry < userEntry2)
		userEntry = userEntry2;

	std::cout << "Uneseite treci broj: " << std::endl;
	std::cin >> userEntry3;

	if (userEntry < userEntry3)
		userEntry = userEntry3;

	std::cout << "Najveci uneseni broj je: " << userEntry << std::endl;*/

	//kalkulator();

	fibonachi(0,1,20);

	system("pause");
}