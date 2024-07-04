#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n------------------------------------\n"

#define HUMAN_TAKE_PARAMETERS const std::string& last_name, const std::string& first_name, int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age

class Human
{
	std::string last_name;
	std::string first_name;
	int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(int age)
	{
		this->age = age;
	}
	
	////////		Constructors:		////////
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;

	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	////////	       Methods:			////////
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << endl;
	}
	
};


#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, rating, attendance

class Student : public Human
{
	std::string speciality;
	std::string group;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return speciality;
	}
	const std::string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	////////	Constructors:		////////
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	Student(const Human& human,STUDENT_TAKE_PARAMETERS):Human(human)
	{
		set_speciality(speciality);
		set_group(group);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	////////		Methods:		////////
	void print()const
	{
		Human::print();
		cout << speciality << " " << group << " " << rating << " " << attendance << endl;
	}
};

#define TEACHER_TAKE_PARAMETERS const std::string& speciality, int experience
#define TEACHER_GIVE_PARAMETERS speciality, experience
class Teacher :public Human
{
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
	void print()const
	{
		Human::print();
		cout << speciality << " " << experience << " years" << endl;
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

	///   constructor

	Gruduate(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS, GRUDUATE_TAKE_PARAMETERS) :
		Student(HUMAN_GIVE_PARAMETERS, STUDENT_GIVE_PARAMETERS)
	{
		this->subject = subject;
			cout<<"GConstructor: \t" <<this << endl;
	}
	Gruduate(const Student& student,const std::string&subject) :Student(student)
	{
		set_subject(subject);
		cout << "GConstructor: \t" << this << endl;
	}
	~Gruduate()
	{
		cout << "TDestructor: \t" << this << endl;
	}
	
	/// </summary>
	void print()const
	{
		Student::print();
		cout << subject << endl;
	}

};

//#define INHERERITANCE_1
//#define INHERERITANCE_2

void main()
{

	setlocale(LC_ALL, "");
	cout << "HelloAcademy" << endl;
#ifdef INHERERITANCE_1
	Human human("Richter", "Jeffrey", 40);
	human.print();
	cout << delimiter << endl;

	Student student("Pinkman", "Jessie", 20, "Chenistry", "WW_220", 95, 90);
	student.print();
	cout << delimiter << endl;

	Teacher teacher("White", "Walter", 50, "Chemistry", 25);
	teacher.print();
	cout << delimiter << endl;

	Gruduate graduate("Schrader", "Hank", 40, "Criminalist", "OBN", 50, 70, "How to catch Heisenber");
	graduate.print();
	cout << delimiter << endl;
#endif // INHERERITANCE_1

#ifdef INHERERITANCE_2
	Human human("Vercety", "Tomy", 30);
	human.print();
	cout << delimiter << endl;

	Student student(human, "Theft", "Vice", 95, 98);
	student.print();
	cout << delimiter << endl;

	Gruduate graduate(student, "How to catch Heisenber");
	graduate.print();
	cout << delimiter << endl;
#endif // INHERERITANCE_2



	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 20, "Chenistry", "WW_220", 95, 90),
		new	Teacher("White", "Walter", 50, "Chemistry", 25),
		new Gruduate ("Schrader", "Hank", 40, "Criminalist", "OBN", 50, 70, "How to catch Heisenber"),
		new Student("Vercety", "Tomy", 30,"Theft", "Vice",95,98),
		new	Teacher("Diaz","Ricardo",50,"Weapons distrubution",20)

	};
	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << delimiter << endl;
	}
}