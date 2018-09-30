#include <stdio.h>
#include <vector>
#include <iostream>
#include <thread>
#include <fstream>
#include <complex>
#include <ctime>
#include <algorithm>
#include <set>
#include <bitset>
#include <memory>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>

#include "mplAux.h"
//#include "mplDocRanking.h"
#include "mplSpiralMatrix.h"
#include "mplQuickSort.h"

//#include "study.h"
//#include "study_tmp.h"

int main()
{
	setlocale(LC_ALL, "ru");
	srand((unsigned int)time(NULL));

	int n = 6;
	int m = 5;
	auto mtrx = getSpiralMatrx(n, m);
	printSpiralMatrx(mtrx);

	/*int pos = 27;
	auto ij = getPosCoord(n, m, pos);
	std::cout << "pos = " << pos << ". (i,j) = (" << std::get<0>(ij) << "," << std::get<1>(ij) << ")." << std::endl << std::endl;*/


	std::vector<int> v{ 15,1,9,0,-4,5 };

	QuickSort<int>(v);
	//QuickSort<int>(v, [](const int& a, const int& b) {return a > b;});
	//QuickSort<int>(v, 0, v.size() - 1, [](const int& a, const int& b) {return a < b;});
	for (auto i : v) std::cout << i << ' '; std::cout << std::endl;
	std::cout << std::endl;


	std::vector<Student> stds(21, Student());
	Student::init(stds);

	QuickSort<Student>(stds);
	//QuickSort<Student>(stds, [](const Student& a, const Student& b) {return a.getMark() > b.getMark();});
	//QuickSort<Student>(stds, 0, stds.size() - 1, [](const Student& a, const Student& b) {return a.getMark() < b.getMark();});
	for (auto i : stds) std::cout << i << std::endl;
	std::cout << std::endl;

	return 0;
}