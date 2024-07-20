#include<Windows.h>
#include<iostream>

using namespace std;

namespace Geometry
{
	enum Color
	{
		CONSOLE_RED = 0xCC,
		CONSOLE_GREEN = 0xAA,
		CONSOLE_BLUE = 0x99,
		CONSOLE_DEFAULT = 0x07
	};

	class Shape
	{
	protected:

		Color color;
	public:
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;
		Shape(Color color) :color(color) {}
		virtual~Shape() {}
		virtual void info()const
		{
			cout << "площадь фигуры: " << get_area() << endl;
			cout << "gthtvtnh фигуры: " << get_perimeter() << endl;
			draw();
		}

	};
	class Square :public Shape
	{
		double side;
	public:
		Square(double side, Color color) :Shape(color)
		{
			set_side(side);
		}
		~Square()
		{

		}
		void set_side(double side)
		{
			this->side = side;
		}
		double get_side()const
		{
			return side;
		}
		double get_area()const override
		{
			return side * side;
		}
		double get_perimeter()const override
		{
			return side * 4;
		}
		void draw()const override
		{
			HANDLE hConsol = GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hConsol, color);
			for (int i = 0; i < side; i++)
			{
				for (int i = 0; i < side; i++)
				{
					cout << "* ";
				}
				cout << endl;
			}
			SetConsoleTextAttribute(hConsol, Color::CONSOLE_DEFAULT);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Длина стороны: " << get_side() << endl;
			Shape::info();
		}
	};
	class Rectangle :public Shape
	{
		double width;
		double height;
	public:
		Rectangle(double width, double height, Color color) :Shape(color)
		{
			set_widht(width);
			set_height(height);
		}
		~Rectangle() {}
		void set_widht(double widht)
		{
			this->width = width;
		}
		void set_height(double height)
		{
			this->height = height;
		}
		double get_widht()const
		{
			return width;
		}
		double get_height()const
		{
			return height;
		}
		double get_area()const override
		{
			return width * height;
		}
		double get_perimeter()const override
		{
			return (width + height) * 2;
		}
		void draw()const override
		{
			//1
			//HWND hwnd = GetActiveWindow();
			HWND hwnd = FindWindow(NULL,L"Inhereritance - Microsoft Visual Studio");
			//2
			HDC hdc = GetDC(hwnd);
			//3
			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);
			//4
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			//5
			::Rectangle(hdc, 100, 100, 900, 300);
			//6
			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "Ширина прямоугольныка" << get_widht() << endl;
			cout << "Высота прямоугольника" << get_height() << endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::CONSOLE_RED);
	Geometry::Square square(5, Geometry::Color::CONSOLE_RED);
	//cout << "Длина стороны: " << square.get_side() << endl;
	//cout << "Площадь квадрата: " << square.get_area() << endl;
	//cout << "Периметр квадрата: " << square.get_perimeter() << endl;
	//square.draw();
	square.info();
	Geometry::Rectangle rect(100, 50, Geometry::Color::CONSOLE_BLUE);
	rect.info();
}