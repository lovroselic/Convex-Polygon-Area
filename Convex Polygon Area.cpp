// https://www.codeabbey.com/index/task_view/convex-polygon-area
// https://www.codeabbey.com/index/task_view/triangle-area

#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <chrono>
#include <cmath>
#include <cassert>
#include <limits>
#include <numeric>
#include <tuple>

#include "Console.h"
#include "CodeAbbey.h"
#include "LS_library.h"
#define VERSION "1.0"

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;

double TriangleArea(int x1, int y1, int x2, int y2, int x3, int y3);
double TriangleArea(vector<int> p1, vector<int> p2, vector<int> p3);
double ConvexPolygonArea(vector<vector<int>> points);

int main() {
	auto t1 = high_resolution_clock::now();
	cout << "Convex Polygon Area v" << VERSION << "!\n\n";
	//string path = "Test.txt";
	string path = "Try.txt";
	vector<string> raw_data = loadData(path);
	/***********************/
	vector<string> solution;

	vector<vector<int>> data;
	for (int i = 1; i < raw_data.size(); i++) {
		data.push_back(splitToInt(raw_data[i], " "));
	}

	cout << "\nSolution: " << FloatToString(ConvexPolygonArea(data),1) << endl;

	/***********************/
	auto t2 = high_resolution_clock::now();
	auto ms_int = duration_cast<milliseconds>(t2 - t1);
	cout << "Execution time: " << ms_int.count() << " ms" << endl;
}

double ConvexPolygonArea(vector<vector<int>> points) {
	double Area = 0;
	for (int i = 1; i < points.size() - 1; i++) {
		Area += TriangleArea(points[0], points[i], points[i + 1]);
	}
	return Area;
}

double TriangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
	double a = sqrt(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2));
	double b = sqrt(pow(abs(x2 - x3), 2) + pow(abs(y2 - y3), 2));
	double c = sqrt(pow(abs(x3 - x1), 2) + pow(abs(y3 - y1), 2));
	double s = (a + b + c) / 2.0;
	double A = sqrt(s * (s - a) * (s - b) * (s - c));
	return A;
}


double TriangleArea(vector<int> p1, vector<int> p2, vector<int> p3) {
	double a = sqrt(pow(abs(p1[0] - p2[0]), 2) + pow(abs(p1[1] - p2[1]), 2));
	double b = sqrt(pow(abs(p2[0] - p3[0]), 2) + pow(abs(p2[1] - p3[1]), 2));
	double c = sqrt(pow(abs(p3[0] - p1[0]), 2) + pow(abs(p3[1] - p1[1]), 2));
	double s = (a + b + c) / 2.0;
	double A = sqrt(s * (s - a) * (s - b) * (s - c));
	return A;
}