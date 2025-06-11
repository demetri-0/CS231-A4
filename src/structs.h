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


