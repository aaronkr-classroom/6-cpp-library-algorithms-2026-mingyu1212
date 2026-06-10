// grade.cpp
#include <list>
#include <vector>
#include <stdexcept>
#include <algorithm> // find()
#include "Student_info.h"
#include "grade.h"
#include "median.h"

// Student_info 계산
double grade(const Student_info& s) {
	return grade(s.getMidterm(), s.getFinal(), s.getHw());
}

// 학생의 과락 여부를 결정하는 서술 함수
bool fgrade(const Student_info& s) {
	return grade(s) < 60;
}

bool pgrade(const Student_info& s) {
	return !fgrade(s);
}

bool did_all_hw(const Student_info& s) {
	return (
		(find(
			s.homework.begin(),
			s.homework.end(), 0)
			) == s.homework.end()
		);
}

vector<Student_info> extract_fails(vector<Student_info>& students) {
	vector<Student_info> fail;
	// vector<Student_info>::size_type i = 0; 
	vector<Student_info>::iterator iter = students.begin();

	// 불변성: students 백터의 [0,i) 범위에 있는
	// 요소들은 과목을 통과한 학생들의 정보
	// while (i != students.size()) {
	while (iter != students.end()) {
		// if (fgrade(students[i])) {
		if (fgrade(*iter)) {
			// fail.push_back(students[i]);
			fail.push_back(*iter);
			// students.erase(students.begin() + i); // i번째 제거
			iter = students.erase(iter);
		}
		else {
			// ++i;
			++iter;
		}
	}
	return fail;
}

list<Student_info> extract_fails(list<Student_info>& students) {
	list<Student_info> fail;
	list<Student_info>::iterator iter = students.begin();

	// 불변성: students 백터의 [0,i) 범위에 있는
	// 요소들은 과목을 통과한 학생들의 정보
	while (iter != students.end()) {
		if (fgrade(*iter)) {
			fail.push_back(*iter);
			iter = students.erase(iter);
		}
		else {
			++iter;
		}
	}
	return fail;
}
