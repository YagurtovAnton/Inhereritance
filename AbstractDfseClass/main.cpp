#include <iostream>
using namespace std;

class Vehicle
{
public:
	virtual void move() = 0;
};
class GroudVehicle :public Vehicle {};

class Bike :public GroudVehicle
{
public:
	void move()override
	{
		cout << "Harley едет на двух колёсах " << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");

	Bike harley_davidson;
	harley_davidson.move();

}