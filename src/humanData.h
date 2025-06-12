/*
	Author: Demetri Karras
	Assignment Number: 4
	Date of Submission: June 12th, 2025

	File Name: humanData.h
*/

#include <string>

using namespace std;

enum Education {
	HIGH_SCHOOL,
	BACHELORS,
	MASTERS,
	DOCTORATE
};

enum Sex {
	MALE,
	FEMALE
};

enum SortBy {
	NAME,
	EDUCATION,
	SALARY,
	SEX,
	AGE
};

typedef struct {
	string name;
	Education education;
	int salary;
} Employee;

typedef struct {
	string name;
	Sex sex;
	int age;
} Person;

class Human {
private:
	SortBy sortBy;
public:
	Human(SortBy sortBy);
	vector<Employee> operator() (vector<Employee> employees);
	vector<Person> operator() (vector<Person> persons);
};
