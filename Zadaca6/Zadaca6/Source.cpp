#include<iostream>
#include<string>
#include<vector>

class IShape
{
public:
	virtual float getArea() = 0;
	virtual float getPerimiter() = 0;
	virtual  std::string getName() = 0;
};

class Triangle : public IShape
{
public:
	float a, b, c;

	float getArea()
	{
		float s = getPerimiter() / 2;
		return sqrt(s*(s - a)*(s - b)*(s - c));
	}
	float getPerimiter()
	{
		return a + b + c;
	}
	std::string getName()
	{
		return "Triangle";
	}
};

class Circle : public IShape
{
public:
	float radius;

	float getArea()
	{
		return 2 * radius * _Pi;
	}
	float getPerimiter()
	{
		return radius * radius * _Pi / 2;
	}
	std::string getName()
	{
		return "Circle";
	}

private:
	float _Pi = 3.14f;
};

class Rectangle : public IShape
{
public:
	float a, b;

	float getArea()
	{
		return 2 * a + 2 * b;
	}
	float getPerimiter()
	{
		return a * b;
	}
	std::string getName()
	{
		return "Rectangle";
	}
};

void printShapeInfo(IShape* shape)
{
	std::cout << "Shape type: " << shape->getName() << std::endl;
	std::cout << "Shape area: " << shape->getArea() << std::endl;
	std::cout << "Shape perimiter: " << shape->getPerimiter() << std::endl;
	std::cout << "***********************************" << std::endl;
}

int getUserInputNuber(int start, int end)
{
	int choice;

	while (true)
	{
		std::cin >> choice;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
		if (choice >= start && choice <= end)
			break;
		else
			std::cout << "Invalid choice!" << std::endl;
	}

	return choice;
}

float getUserFloatNumber(std::string prompt)
{
	float uNum;
	while (true)
	{
		std::cout << " > " << prompt;
		std::cin >> uNum;
		std::cin.clear();
		std::cin.ignore(1000, '\n');

		if (uNum != 0)
			break;
		else
			std::cout << "Invalid number!" << std::endl;
	}
	return uNum;
}

void newShape(std::vector<IShape*> &shapes)
{
	int choice;
	Triangle* triangle;
	Rectangle* rectangle;
	Circle* circle;

	std::cout << "1 - triangle" << std::endl;
	std::cout << "2 - rectangle" << std::endl;
	std::cout << "3 - circle" << std::endl;

	choice = getUserInputNuber(1, 3);

	switch (choice)
	{
	case 1:
		triangle = new Triangle();
		triangle->a = getUserFloatNumber("side a: ");
		triangle->b = getUserFloatNumber("side b: ");
		triangle->c = getUserFloatNumber("side c: ");
		shapes.push_back(triangle);
		break;
	case 2:
		rectangle = new Rectangle();
		rectangle->a = getUserFloatNumber("side a: ");
		rectangle->b = getUserFloatNumber("side b: ");
		shapes.push_back(rectangle);
		break;
	case 3:
		circle = new Circle();
		circle->radius = getUserFloatNumber("radius: ");
		shapes.push_back(circle);
		break;
	}
}

int main()
{
	std::vector<IShape*> shapes;
	int choice = 1;

	while (choice != 2)
	{
		std::cout << "1 - Enter the new shape" << std::endl;
		std::cout << "2 - Exit and print shape info" << std::endl;

		choice = getUserInputNuber(1, 2);

		if (choice == 1)
			newShape(shapes);
	}

	if (shapes.size() > 0)
	{
		std::cout << "*********** Shape info ************" << std::endl;

		for (IShape* it : shapes)
		{
			printShapeInfo(it);
		}
	}
	else
	{
		std::cout << "There is no shape in list!" << std::endl;
	}

	std::cin.get();
};