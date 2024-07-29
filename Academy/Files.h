#pragma once
#include<iostream>
#include<fstream>
#include<string>		//Объявлен класс std::string
#include<string.h>	
#include"СlassHuman.h"	
#include"ClassStudent.h"	
#include"ClassTeacher.h"

#define delimiter "\n------------------------------------\n"

using std::cin;
using std::cout;
using std::endl;

void Print(Human* group[], const int n)
{
	cout << delimiter << endl;
	for (int i = 0; i < n; i++)
	{
		//group[i]->print();
		if (group[i])cout << *group[i] << endl;
		cout << delimiter << endl;
	}
	cout << "Колиество человек в группе: " << n << endl;
}
void Save(Human* group[], const int n, const std::string& filename)
{
	std::ofstream fout(filename);
	for (int i = 0; i < n; i++)
	{
		fout << *group[i] << endl;
	}
	fout.close();
	std::string cmd = "notepad " + filename;
	system(cmd.c_str());//Функция system(const char*) выполняет любую досутпную коданду операционной системы
	//Метод c_str() возвращает C-string (NULL Terminated Line), обвернутый в объект класса std::string.
}
Human* HumanFactory(const std::string& type)
{
	Human* human = nullptr;
	if (type == "Human:")human = new Human("", "", 0);
	if (type == "Teacher:")human = new Teacher("", "", 0, "", 0);
	if (type == "Student:")human = new Student("", "", 0, "", "", 0, 0);
	if (type == "Graduate:")human = new Gruduate("", "", 0, "", "", 0, 0, "");
	return human;
}
bool NotAppropriateType(const std::string& buffer)
{
	//Несоответствуюший тип:
	return buffer.find("Human:") == std::string::npos &&
		buffer.find("Student:") == std::string::npos &&
		buffer.find("Teacher:") == std::string::npos &&
		buffer.find("Graduate:") == std::string::npos;
}
Human** Load(const std::string& filename, int& n)
{
	Human** group = nullptr;
	std::ifstream fin(filename);
	if (fin.is_open())
	{
		//1) Bыичсляем размер файла (количество записей в файле):
		n = 0;
		while (!fin.eof())
		{
			std::string buffer;
			//fin.getline();	//НЕ перегружен для объектов класса std::string
			std::getline(fin, buffer);	//читает все до конца строки
			//move DST, SRC;
			//strcat(DST, SRC);
			if (
				buffer.find("Human:") == std::string::npos &&
				buffer.find("Student:") == std::string::npos &&
				buffer.find("Teacher:") == std::string::npos &&
				buffer.find("Graduate:") == std::string::npos
				)continue;
			n++;
		}
		cout << "количество записей в файле: " << n << endl;

		//2)  Выделяем память для группы:
		group = new Human * [n] {};

		//3)   Возвращаемся в начало файла, для того чтобы прочитать содержимое этого файла:
		cout << "Позиция курсора на чтение: " << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << "Позиция курсора на чтение: " << fin.tellg() << endl;

		//4) Читаем файл:
		for (int i = 0; !fin.eof(); i++)
		{
			std::string type;
			fin >> type;

		}

		fin.close();
	}
	else
	{
		std::cerr << "Error: File not found" << endl;
	}
	return group;
}
void Clear(Human* group[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[]group[i];
	}
}
