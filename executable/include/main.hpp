#pragma once
#include <iostream>
#include <string>
#include <vector>

// Make sure to change the namespace EXECUTABLE to something more specific
namespace lush::EXECUTABLE {
	
	using namespace std;
	
	const vector<vector<string>> input_frame_1;
	const vector<vector<string>> input_frame_2;

	const string particle;
	const string empty;
	const string obstacle;

	vector<vector<string>> step(vector<vector<string>> const& incoming_frame);

	vector<vector<string>> rotate_clockwise(vector<vector<string>> const& frame);

}  // namespace lush::EXECUTABLE