#pragma once
#ifndef __mplSpiralMatrix__
#define __mplSpiralMatrix__

//#include <vector>
//#include <tuple>

template <typename T = int>
std::vector< std::vector<T> > getSpiralMatrx(
	const int& n,
	const int& m,
	const T& step = 1,
	const std::pair<bool, bool>& corner = std::pair<bool, bool>(true, true)
);

std::vector< std::vector<int> > getSpiralMatrx(const int& n, const int& m);

void printSpiralMatrx(const std::vector<std::vector<int>>&);

std::tuple<int, double, double> solveQuadEq(const double &a, const double &b, const double &c);

std::tuple<int, int, bool> getPosCoord(int n, int m, int pos);

double arithmSum(const double& a, const double& d, const int& n);

#endif // __mplSpiralMatrix__