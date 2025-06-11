#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "structs.h"

void parseEmployeeLine(string line, vector<Employee>& employees);
void parsePersonLine(string line, vector<Person>& persons);
void printEmployees(vector<Employee>& employees);
string getEducationString(Education education);
void printPersons(vector<Person>& persons);
string getSexString(Sex sex);

int main() {

	cout << "Welcome to the ***********!" << endl;

	/*
	 * Obtains the employee input file from the user.
	 */
	string employeeFileName;
	cout << "Please enter the name of the input file for employee data: " << flush;
	cin >> employeeFileName;
	cout << endl;
	ifstream employeeInputFile(employeeFileName);

	/*
	 * Obtains the person input file from the user.
	 */
	string personFileName;
	cout << "Please enter the name of the input file for person data: " << flush;
	cin >> personFileName;
	cout << endl;
	ifstream personInputFile(personFileName);

	if (employeeInputFile.is_open() && personInputFile.is_open()) {

		/*
		 * Reads the content of the employees input file line-by-line, storing data in the
		 * employees vector.
		 */
		string employeeLine;
		vector<Employee> employees;
		while (getline(employeeInputFile, employeeLine)) {
			parseEmployeeLine(employeeLine, employees);
		}

		/*
		 * Reads the content of the persons input file line-by-line, storing data in the
		 * persons vector.
		 */
		string personLine;
		vector<Person> persons;
		while (getline(personInputFile, personLine)) {
			parsePersonLine(personLine, persons);
		}

		printEmployees(employees);
		cout << endl;
		printPersons(persons);
	}

	return 0;
}

/*
 * Function Name: parseLine
 *
 * Input:
 * Param1(line) - the line from the input file from which data is obtained,
 * structured as follows: <name>,<education>,$<salary>
 * Param2(employees) - the vector of employees to which this function applies
 *
 * Output: None - changes are reflected in the input vector.
 *
 * Description:
 * Reads a line from the input file and obtains employee data. Creates a new
 * employee struct and adds it to the specified employees vector.
 */
void parseEmployeeLine(string line, vector<Employee>& employees) {

	/*
	 * The first comma in the line is found. The employee name is the substring
	 * from the beginning of the line to that comma. The line string is
	 * shortened up to the first character after the first comma.
	 */
	int indexOfComma = line.find(',');
	string name = line.substr(0, indexOfComma);
	line = line.substr(indexOfComma + 1);

	/*
	 * The next comma is found in the new line string. The employee education is
	 * the substring between the beginning of the line string, and the new
	 * comma, which gets converted to a valid Education enum. The line string is
	 * shortened again up to the first character after this comma.
	 */
	indexOfComma = line.find(',');
	string educationStr = line.substr(0, indexOfComma);
	Education education;
	if (educationStr == "Doctorate") {
		education = DOCTORATE;
	}
	else if (educationStr == "Masters") {
		education = MASTERS;
	}
	else if (educationStr == "Bachelors") {
		education = BACHELORS;
	}
	else {
		education = HIGH_SCHOOL;
	}
	line = line.substr(indexOfComma + 1);

	/*
	 * The dollar sign is found, and the salary is the substring from the
	 * character after the dollar sign to the end of the line. This substring is
	 * converted to an integer.
	 */
	string salaryStr = line.substr(line.find('$') + 1);
	int salary = stoi(salaryStr);

	/*
	 * A new employee struct is created using the above attributes and it is
	 * added to the employees vector.
	 */
	Employee employee = {
		name,
		education,
		salary
	};

	employees.push_back(employee);
}

/*
 * Function Name: parsePersonLine
 *
 * Input:
 * Param1(line) - the line from the input file from which data is obtained,
 * structured as follows: <name>,<sex>,<age>
 * Param2(persons) - the vector of persons to which this function applies
 *
 * Output: None - changes are reflected in the input vector.
 *
 * Description:
 * Reads a line from the input file and obtains person data. Creates a new
 * person struct and adds it to the specified persons vector.
 */
void parsePersonLine(string line, vector<Person>& persons) {

	/*
	 * The first comma in the line is found. The person's name is the substring
	 * from the beginning of the line to that comma. The line string is
	 * shortened up to the first character after the first comma.
	 */
	int indexOfComma = line.find(',');
	string name = line.substr(0, indexOfComma);
	line = line.substr(indexOfComma + 1);

	/*
	 * The next comma is found in the new line string. The person's sex is
	 * the substring between the beginning of the line string, and the new
	 * comma, which gets converted to a valid Sex enum. The line string is
	 * shortened again up to the first character after this comma.
	 */
	indexOfComma = line.find(',');
	string sexStr = line.substr(0, indexOfComma);
	Sex sex;
	if (sexStr == "M") {
		sex = MALE;
	}
	else {
		sex = FEMALE;
	}
	line = line.substr(indexOfComma + 1);

	/*
	 * The dollar sign is found, and the salary is the substring from the
	 * character after the dollar sign to the end of the line. This substring is
	 * converted to an integer.
	 */
	string ageStr = line;
	int age = stoi(ageStr);

	/*
	 * A new employee struct is created using the above attributes and it is
	 * added to the employees vector.
	 */
	Person person = {
		name,
		sex,
		age
	};

	persons.push_back(person);
}

/*
 * Function Name: printEmployees
 *
 * Input:
 * Param1(employees) - the vector of employees to which this function applies
 *
 * Output: None - output is printed to the console.
 *
 * Description:
 * Iterates through vector of employees, printing their names, education levels,
 * and salaries in a structured format.
 */
void printEmployees(vector<Employee>& employees) {
	cout << "== EMPLOYEES ==" << endl;
	for_each(employees.begin(), employees.end(), [](Employee& employee) {
		cout << "Name: " << employee.name << " // ";
		cout << "Education: " << getEducationString(employee.education) << " // ";
		cout << "Salary: $" << employee.salary << endl;
	});
}

/*
 * Function Name: getEducationString
 *
 * Input:
 * Param1(education) - the Education enum to be converted into a string
 *
 * Output: A string representation of the input Education enum.
 *
 * Description:
 * Returns a string corresponding to a specified education level.
 */
string getEducationString(Education education) {

	if (education == DOCTORATE) {
		return "Doctorate";
	}
	if (education == MASTERS) {
		return "Masters";
	}
	if (education == BACHELORS) {
		return "Bachelors";
	}
	return "High School";
}

void printPersons(vector<Person>& persons) {
	cout << "==PERSONS==" << endl;
	for_each(persons.begin(), persons.end(), [](Person& person) {
		cout << "Name: " << person.name << " // ";
		cout << "Sex: " << getSexString(person.sex) <<  " // ";
		cout << "Age: " << person.age << endl;
	});
}

string getSexString(Sex sex) {
	if (sex == MALE) {
		return "Male";
	}
	return "Female";
}
