#pragma once
#include<iostream>
#include<fstream>
#include<string>		//�������� ����� std::string
#include<string.h>	
#include"�lassHuman.h"	
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
	cout << "��������� ������� � ������: " << n << endl;
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
	system(cmd.c_str());//������� system(const char*) ��������� ����� ��������� ������� ������������ �������
	//����� c_str() ���������� C-string (NULL Terminated Line), ���������� � ������ ������ std::string.
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
	//����������������� ���:
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
		//1) B�������� ������ ����� (���������� ������� � �����):
		n = 0;
		while (!fin.eof())
		{
			std::string buffer;
			//fin.getline();	//�� ���������� ��� �������� ������ std::string
			std::getline(fin, buffer);	//������ ��� �� ����� ������
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
		cout << "���������� ������� � �����: " << n << endl;

		//2)  �������� ������ ��� ������:
		group = new Human * [n] {};

		//3)   ������������ � ������ �����, ��� ���� ����� ��������� ���������� ����� �����:
		cout << "������� ������� �� ������: " << fin.tellg() << endl;
		fin.clear();
		fin.seekg(0);
		cout << "������� ������� �� ������: " << fin.tellg() << endl;

		//4) ������ ����:
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
