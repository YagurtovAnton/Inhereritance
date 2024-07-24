#define _USE_MATH_DEFINES
#include<Windows.h>
#include<iostream>

using namespace std;

namespace Geometry
{

	enum Color //enum (Enumeration - ������������) - ��� ����� ����������� ��������� ���� 'int'
	{
		RED			= 0x000000FF,
		GREEN		= 0x0000FF00,
		BLUE		= 0x00FF0000,
		YELLOW		= 0x0000FFFF,

		CONSOLE_RED = 0xCC,//������� 'C' - ���� ����, ������� 'C' - ���� ������.
		CONSOLE_GREEN = 0xAA,
		CONSOLE_BLUE = 0x99,
		CONSOLE_DEFAULT = 0x07
	};

#define SHAPE_TAKE_PARAMETERS unsigned int start_x, unsigned int start_y, unsigned int line_width, Color color
#define SHAPE_GIVE_PARAMETERS start_x, start_y, line_width, color

	class Shape
	{
	protected:
		unsigned int start_x;
		unsigned int start_y;
		unsigned int line_width;
		Color color;
	public:
		//�����-����������� ������� (Pure virtual function)
		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void draw()const = 0;

		Shape(SHAPE_TAKE_PARAMETERS) :color(color)
		{
			set_start_x(start_x);
			set_start_y(start_y);
			set_line_width(line_width);
		}
		virtual ~Shape() {}

		//////		Encapsulation		///////
		unsigned int get_start_x()const
		{
			return start_x;
		}
		unsigned int get_start_y()const
		{
			return start_y;
		}
		unsigned int get_line_width()const
		{
			return line_width;
		}
		void set_start_x(unsigned int start_x)
		{
			this->start_x = start_x;
		}
		void set_start_y(unsigned int start_y)
		{
			this->start_y = start_y;
		}
		void set_line_width(unsigned int line_width)
		{
			this->line_width = line_width;
		}
		
		virtual void info()const
		{
			cout << "�������  ������: " << get_area() << endl;
			cout << "�������� ������: " << get_perimeter() << endl;
			draw();
		}
	};
	/*class Square :public Shape
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
			cout << "����� �������: " << get_side() << endl;
			Shape::info();
		}
	};*/
	class Rectangle :public Shape
	{
		double width;	//������ ��������������
		double height;	//������ ��������������
	public:
		Rectangle(double width, double height, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_widht(width);
			set_height(height);
		}
		~Rectangle() {}
		void set_widht(double width)
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
			//WinGDI - Windows Grphics Device Interface
			//1) �������� ���� �������:
			//HWND hwnd = GetConsoleWindow();	//������� GetConsoleWindow() �������� ���� �������
			HWND hwnd = FindWindow(NULL, L"Inhereritance - Microsoft Visual Studio");
			//2) ��� ���� ����� ��������, ����� �������� ���������� (Device Context), 
					//	 ������� ���� � ������� ����. ��������� ���������� ����� �������� ��� ������ ������� GetDC();
			HDC hdc = GetDC(hwnd);	//�������� �������� ���� �������
			//�������� ���������� - ��� ��, �� ��� �� ����� ��������.

			//3) ������ ��� ����� ��, ��� �� ����� ��������:
			HPEN hPen = CreatePen(PS_SOLID, line_width, color);	//hPen		- ������ ������ ������;
			//SP_SOLID	- �������� �����
			//5			- ������� ����� 5 ��������
			HBRUSH hBrush = CreateSolidBrush(color);	//hBrush	- ������ ������� ������ (SolidBrush - �������� ����)

			//4) �������� ���, � �� ��� �� ����� ��������:
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			//5) ������ ������:
			::Rectangle(hdc, start_x, start_y, start_x + width, start_y + height);	//:: - Global Scope (���������� ������������ ����)

			//6) hdc, hPen � hBrush �������� �������, � ����� ����, ��� �� ��� ���������������, ������� ����� ����������:
			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "������ ��������������" << get_widht() << endl;
			cout << "������ ��������������" << get_height() << endl;
			Shape::info();
		}
	};

	class Square :public Rectangle
	{
	public:
		Square(double side, SHAPE_TAKE_PARAMETERS) :Rectangle(side, side, SHAPE_GIVE_PARAMETERS) {}
		~Square() {}
	};
	class Circle :public Shape
	{
		double radius;
	public:
		Circle(double radius, SHAPE_TAKE_PARAMETERS) :Shape(SHAPE_GIVE_PARAMETERS)
		{
			set_radius(radius);
		}
		~Circle()
		{

		}
		void set_radius(double radius)
		{
			this->radius = radius;
		}
		double get_radius() const
		{
			return radius;
		}
		double get_diameter() const
		{
			return 2*radius;
		}

		double get_area()const override
		{
			return M_PI * radius * radius;
		}
		double get_perimeter() const override
		{
			return M_PI * get_diameter();
		}
		void draw()const override
		{
			HWND hwnd = FindWindow(NULL, L"Inhereritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			::Ellipse(hdc, start_x, start_y, start_x + get_diameter(), start_y + get_diameter());

			DeleteObject(hBrush);
			DeleteObject(hPen);

			ReleaseDC(hwnd, hdc);
		}
		void info()const override
		{
			cout << typeid(*this).name() << endl;
			cout << "disk radius" << get_diameter() << endl;
			cout << "disk diameter" << get_diameter() << endl;
			Shape::info();
		}
	};
}

void main()
{
	setlocale(LC_ALL, "");
	//Shape shape(Color::CONSOLE_RED);
	Geometry::Square square(5, 100, 100, 5, Geometry::Color::RED);
	//cout << "����� �������: " << square.get_side() << endl;
	//cout << "������� ��������: " << square.get_area() << endl;
	//cout << "�������� ��������: " << square.get_perimeter() << endl;
	//square.draw();
	square.info();
	Geometry::Rectangle rect(100, 50, 2000, 100, 10, Geometry::Color::BLUE);
	rect.info();

	Geometry::Circle disk(100, 500, 100, 5, Geometry::Color::YELLOW);
	disk.info();


}	

