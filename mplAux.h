#ifndef __mpl__
#define __mpl__

//#include <cstdlib>
//#include <iostream>
//#include <ctime>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <iomanip>
//#include <memory>
//#include <utility>
//#include <tuple>
//#include <functional>

class Student {
protected:
	int num;
	std::string name;
	std::string patronymic;
	std::string surname;
	int mark;
public:
	int getMark() const;
	void setMark(const int& val);
    int getNum() const;
	void setNum(const int& val);
	friend std::ostream& operator<<(std::ostream& os, Student student);
	friend bool operator<(const Student& a, const Student& b);

	static void init(std::vector<Student>& students);
	static void printStudents(std::vector<Student> students);
};

extern std::vector<std::string> names;

#endif // __mpl__