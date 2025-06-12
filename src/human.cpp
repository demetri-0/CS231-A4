/*
	Author: Demetri Karras
	Assignment Number: 4
	Date of Submission: June 12th, 2025

	File Name: human.cpp
*/

#include <vector>
#include <algorithm>

#include "humanData.h"

Human::Human(SortBy sortBy) {
	this-> sortBy = sortBy;
}

/*
 * Function Name: operator
 *
 * Input:
 * Param1(employees) - the vector of employees to which this function applies
 *
 * Output: A copy of the employees vector that is sorted by the specified value
 * from sortBy.
 *
 * Description:
 * Sorts the employees using a copy to preserve the original vector. The
 * sorting attribute is defined in the Human constructor.
 */
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

/*
 * Function Name: operator
 *
 * Input:
 * Param1(persons) - the vector of persons to which this function applies
 *
 * Output: A copy of the persons vector that is sorted by the specified value
 * from sortBy.
 *
 * Description:
 * Sorts the persons using a copy to preserve the original vector. The sorting
 * attribute is defined in the Human constructor.
 */
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

