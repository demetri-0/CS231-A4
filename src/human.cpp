#include <vector>
#include <algorithm>

#include "humanData.h"

Human::Human(SortBy sortBy) {
	this-> sortBy = sortBy;
}

vector<Employee> Human::operator() (vector<Employee> employees) {
	sort(employees.begin(), employees.end(), [&](Employee e1, Employee e2) {
		if (sortBy == NAME) {
			return e1.name < e2.name;
		}
		else if (sortBy == EDUCATION) {
			return e1.education < e2.education;
		}
		else { // if (sortBy == SALARY)
			return e1.salary < e2.salary;
		}
	});

	return employees;
}

vector<Person> Human::operator() (vector<Person> persons) {
	sort(persons.begin(), persons.end(), [&](Person p1, Person p2) {
		if (sortBy == NAME) {
			return p1.name < p2.name;
		}
		else if (sortBy == SEX) {
			return p1.sex < p2.sex;
		}
		else { // if (sortBy == AGE)
			return p1.age < p2.age;
		}
	});

	return persons;
}

