#pragma once
#include<iostream>
#include<fstream>
#include<string>		//Объявлен класс std::string
#include<string.h>	
#include"СlassHuman.h"	

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience
class Teacher :public Human
{
	static const int SPECIALITY_WIDTH = 25;
	static const int EXPERIENCE_WIDTH = 5;
	std::string speciality;
	int experience;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	int get_experience()const
	{
		return experience;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(int experience)
	{
		this->experience = experience;
	}

	////////		Constructors:		////////
	Teacher(HUMAN_TAKE_PARAMETERS, TEACHER_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}

	//////////		   Methods:			////////
	std::ostream& print(std::ostream& os)const
	{
		return Human::print(os) << " " << speciality << " " << experience << " years";
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Human::print(ofs);
		ofs.width(SPECIALITY_WIDTH);
		ofs << speciality;
		ofs.width(EXPERIENCE_WIDTH);
		ofs << experience;
		return ofs;
	}
	std::ifstream& read(std::ifstream& ifs)override
	{
		Human::read(ifs);
		char sz_speciality[SPECIALITY_WIDTH + 1]{};	//sz_ - String Zero (Строка, заканчивающаяся нулем)
		ifs.read(sz_speciality, SPECIALITY_WIDTH);
		for (int i = SPECIALITY_WIDTH - 2; sz_speciality[i] == ' '; i--)sz_speciality[i] = 0;
		while (sz_speciality[0] == ' ')for (int i = 0; sz_speciality[i]; i++)sz_speciality[i] = sz_speciality[i + 1];
		speciality = sz_speciality;
		ifs >> experience;
		return ifs;
	}
};

#define GRUDUATE_TAKE_PARAMETERS const std::string& subject
#define GRUDUATE_GIVE_PARAMETERS subject
class  Gruduate : public Student
{
	std::string subject;
public:
	const std::string& get_subject()const
	{
		return subject;
	}
	void set_subject(const std::string& subject)
	{
		this->subject = subject;
	}

	///			constructor			////		

	Gruduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRUDUATE_TAKE_PARAMETERS) :
		Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		this->subject = subject;
		cout << "GConstructor: \t" << this << endl;
	}
	Gruduate(const Student& student, const std::string& subject) :Student(student)
	{
		set_subject(subject);
		cout << "GConstructor: \t" << this << endl;
	}
	~Gruduate()
	{
		cout << "TDestructor: \t" << this << endl;
	}

	///			 Methods			///
	std::ostream& print(std::ostream& os) const override
	{
		return Student::print(os) << " " << subject;
	}
	std::ofstream& print(std::ofstream& ofs)const override
	{
		Student::print(ofs) << subject;
		return ofs;
	}

	std::ifstream& read(std::ifstream& ifs) override
	{
		Student::read(ifs);
		std::getline(ifs, subject);
		return ifs;
	}
};
