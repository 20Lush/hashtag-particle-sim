#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

namespace lush::particles {
	
	using namespace std;
	
	const vector<vector<string>> input_frame_1 = {	{"#", "#", ".", ".", ".", ".", "."},
													{"#", "#", "#", ".", ".", ".", "."},
													{"#", "#", "#", ".", ".", "#", "."}};

	const vector<vector<string>> solution_1 = {	{".", ".", "."},
												{".", ".", "."},
												{".", ".", "."},
												{"#", ".", "."},
												{"#", "#", "."},
												{"#", "#", "#"},
												{"#", "#", "#"}};

	const vector<vector<string>> input_frame_2 = {	{"#", "#", ".", ".", ".", "#", "."},
													{"#", "#", "#", ".", ".", "*", "."},
													{"#", "#", "#", "*", ".", "#", "."}};

	const vector<vector<string>> solution_2 = {	{"#", ".", "."},
												{"#", ".", "."},
												{"#", "#", "."},
												{"*", "#", "."},
												{".", "#", "#"},
												{".", "*", "#"},
												{"#", ".", "#"} };

	const string particle = "#";
	const string obstacle = "*";
	const string empty = ".";

}  // namespace lush::particles