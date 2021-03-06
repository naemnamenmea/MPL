#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <set>
#include <memory>
#include <functional>
#include <iterator>
#include <numeric>
#include <utility>
#include <sstream>
#include <clocale>
//#include <windows.h>
#include <codecvt>

#include "mplAux.hpp"
#include "mplSpiralMatrix.hpp"
#include "mplQuickSort.hpp"

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	srand((unsigned int)time(NULL));
/* SpiralMatrix ---*/
	int n = 2;
	int m = 7;
	auto mtrx = getSpiralMatrix(n, m);
	printSpiralMatrix(mtrx);

	/*int pos = 27;
	auto ij = getPosCoord(n, m, pos);
	std::cout << "pos = " << pos << ". (i,j) = (" << std::get<0>(ij) << "," << std::get<1>(ij) << ")." << std::endl << std::endl;*/
/*--- SpiralMatrix */
/* QuickSort ---*/
	std::vector<int> v{ 15,1,9,0,-4,5 };

	QuickSort<int>(v);
	//QuickSort<int>(v, [](const int& a, const int& b) {return a > b;});
	//QuickSort<int>(v, 0, v.size() - 1, [](const int& a, const int& b) {return a < b;});
	for (auto i : v) //std::cout << i << ' '; std::cout << std::endl;
	std::cout << std::endl;


	std::vector<Student> stds(21, Student());
	Student::init(stds);

	QuickSort<Student>(stds);
	//QuickSort<Student>(stds, [](const Student& a, const Student& b) {return a.getMark() > b.getMark();});
	//QuickSort<Student>(stds, 0, stds.size() - 1, [](const Student& a, const Student& b) {return a.getMark() < b.getMark();});
	for (auto i : stds) //std::cout << i << std::endl;
	std::cout << std::endl;
/*--- QuickSort */
	return 0;
}