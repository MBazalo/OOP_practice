#include <iostream>
#include <string>
#include <cstring>

class Subject
{
	int course_id;
public:
	Subject(int i) {course_id=i;}

	int getCid()
	{
	return course_id;
	}


};

class Person
{
protected:
	char name[20];
	int id;
public:
	Person(char* n, int i) {strcpy(name,n); id=i;}

	virtual void printData() = 0;

};

class Student:public Person
{

	Subject** sptr;
	int subnum;

public:
	Student(char* n, int i, int num, Subject **sub):Person(n,i)
	{
		sptr=sub;
                subnum=num;
	}

	~Student() {delete[] sptr;}

	void printData()
	{
	std::cout<<"Student info:\n"<<std::endl;
	std::cout<<"Student name: "<<name<<std::endl;
	std::cout<<"Student id: "<<id<<std::endl;
	if (sptr!=NULL)
	{
		for (int i=0;i<subnum;i++)
			{
			std::cout<<"Student studies: "<<sptr[i]->getCid()<<std::endl;
			}
	}
	std::cout<<std::endl;
	}

};

class Staff:public Person
{
	Subject* subj;
	int salary;
public:
	Staff(char* n, int i, int s, Subject *sub):Person(n,i)

	{
	subj=sub;
	salary=s;
	}

	~Staff() {delete[] subj;}

	void printData()
	{
	std::cout<<"Staff info:\n"<<std::endl;
	std::cout<<"Staff name: "<<name<<std::endl;
	std::cout<<"Staff id: "<<id<<std::endl;
	std::cout<<"Staff salary: "<<salary<<std::endl;
	if (subj!=NULL)
	{
		std::cout<<"Teacher teaches: "<<subj->getCid()<<std::endl;
	}
	std::cout<<std::endl;
	}
};



class School
{
	//char name[10];
	Person** pptr;
	int pnum;
public:
	School(Person** p, int num)
	{
		pptr=p;
		pnum=num;

	}

        ~School() {delete[] pptr;}

	void print()
	{
		if (pptr!=NULL)
		{
			for (int j = 0; j<pnum; j++)
			{
				pptr[j]->printData();
			}
		}
	}


};

int main()
{
	Subject s1(1), s2(2), s3(3), s4(4);
	Staff t1("Teacher 1",1,1000,&s1);
	Staff t2("Teacher 2",2,200,&s4);
	Subject * subjects[] = {&s1,&s3,&s4};
	Student st("Student 1",60, 3, subjects);
	Person * people[] = {&t1, &t2, &st};
	School school(people, 3);
	school.print();
    return 0;
}
