#include "main.hpp"

// Lets keep it simple!
namespace lush::particles {

	using namespace std;

	/// @brief a step function that computes the physics in each column of a '#' particle falling towards the bottom
	/// @param incoming_frame NON-ROTATED input frame
	/// @return a frame containing updated particle positions
	vector<vector<string>> step(vector<vector<string>> const& incoming_frame) { 
		
		// We actually want to calculate the movements of the particles before we rotate the frame.
		// Its easier to calculate the movement of the transposed columns since they don"t affect each other.
		vector<vector<string>> new_frame;

		// For each row in the matrix, we want to do some logic
		for(unsigned int i = 0; i < incoming_frame.size(); i++) {
			
			// Create a row that we'll push into the new frame, from a copy of the input
			vector<string> new_row = incoming_frame[i];
			
			// We start from the bottom/back of the row, as it simplifies the logic
			for(int j = incoming_frame[i].size() - 1; j >= 0; --j) {
				
				// The first element in the row needs nothing done to it, its already corrected by the pass before it
				if(j == 0){
					continue;
				}

				// We get some immutable ref values for the current value being looked at and the one "above" it
				const string& current_value = new_row[j];
				const string& next_value = new_row[j-1];

				// The only condition where we actually need to consider anything is if we are looking at an empty, and there is
				// a particle above it.
				if(current_value == empty){

					// If the value above an empty is a particle, then we drop the particle into the empty.
					// Then, we declare the next value as empty, as it was previously occupied by a particle
					if(next_value == particle){
						new_row[j] = particle;
						new_row[j-1] = empty;
					}

					// If there is anything other than a particle above the empty, nothing needs to happen
					else {
						continue;
					}
				}
			}

			// We push the updated row into the output frame.
			new_frame.push_back(new_row);
		}
		
		// Return the updated frame.
		return new_frame;
	}

	/// @brief Helper transpose function specifically catered to the string matrix frame in this prompt
	/// @param frame 
	/// @return A transposed frame
	vector<vector<string>> transpose(vector<vector<string>> const& frame) {
		
		// Get our frame measurements
		int rows = frame.size();
		int cols = frame[0].size();
		
		// Initialize our output container with the inverse dimensions (row size->cols, col size->rows)
		vector<vector<string>> transposed(cols, vector<string>(rows));

		// Fill in the row data from the input cols, vice versa for the col data.
		for(int i = 0; i < rows; ++i) {
			for(int j = 0; j < cols; ++j) {
				transposed[j][i] = frame[i][j];
			}
		}

		// Return our transposed frame
		return transposed;
	}

	/// @brief Helper reversal function specifically catered to the string matrix frame in this prompt
	/// @param frame 
	/// @return A frame of the same dimensions as the input with the rows reversed
	vector<vector<string>> reverse_row_order(vector<vector<string>> const& frame) {
		
		// Initialize our output container as the same as the input
		auto reversed = frame;
		
		// Utilize algorith.h reverse function to reverse the ordering of a std::vector (our rows, in this context)
		for(auto& row : reversed) {
			reverse(row.begin(), row.end());
		}

		// Return our frame with the row orders reversed
		return reversed;
	}

	/// @brief Takes a string-matrix-frame and rotates it 90deg clockwise, preserving value positions. NOT A TRANSPOSE.
	/// @param frame 
	/// @return The input parameter frame rotated 90deg
	vector<vector<string>> rotate_clockwise(vector<vector<string>> const& frame) {

		// Rotating a matrix 90deg is done by transposing it, and reversing the order of the rows.

		// Transpose the frame
		auto transposed = transpose(frame);
		// Reverse the row orders
		auto reversed = reverse_row_order(transposed);
		// Return the processed frame
		return reversed;
	}

	/// @brief Debug function that console prints a frame in a readable way
	/// @param frame 
	void print_frame(vector<vector<string>> const& frame) {
		for (const auto& row : frame) {
			for (const auto& element : row) {
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}
	}
}  // namespace lush::particles

int main() {

	using namespace lush;
	
	// Set up the first input frame
	auto frame = particles::input_frame_1;
	particles::print_frame(frame);
	std::cout << std::endl;

	// Step the physics until the rotated result looks like the solution
	while(particles::rotate_clockwise(frame) != particles::solution_1) {
		frame = particles::step(frame);
		particles::print_frame(frame);
		std::cout << std::endl;
	}

	// Print the successful result & a cute success line
	particles::print_frame(particles::rotate_clockwise(frame));
	std::cout << "Successfully computed solution 1" << std::endl;
	std::cout << std::endl;

	// Set up the second input frame
	frame = particles::input_frame_2;
	particles::print_frame(frame);
	std::cout << std::endl;

	// Step the physics until the rotated result looks like the solution
	while(particles::rotate_clockwise(frame) != particles::solution_2) {
		frame = particles::step(frame);
		particles::print_frame(frame);
		std::cout << std::endl;
	}
	
	// Print the successful result & a cute success line
	particles::print_frame(particles::rotate_clockwise(frame));
	std::cout << "Successfully computed solution 2" << std::endl;
}