
#include "main.hpp"


// Lets keep it simple!
namespace lush::particles {

	using namespace std;

	const vector<vector<string>> input_frame_1 = {{"#", "#", ".", ".", ".", ".", "."},
       										{"#", "#", "#", ".", ".", ".", "."},
      										{"#", "#", "#", ".", ".", "#", "."}};
	
	const vector<vector<string>> input_frame_2 = {{"#", "#", ".", ".", ".", "#", "."},
       										{"#", "#", "#", ".", ".", "*", "."},
       										{"#", "#", "#", "*", ".", "#", "."}};

	const string particle = "#";
	const string obstacle = "*";
	const string empty = ".";

	vector<vector<string>> step(vector<vector<string>> const& incoming_frame) { 

		// We actually want to calculate the movements of the particles before we rotate the frame.
		// Its easier to calculate the movement of the transposed columns since they don't affect each other.
		// start from the end.

		vector<vector<string>> new_frame;

		// loop for each row
		for(int i = 0; i < incoming_frame.size(); i++) {

			vector<string> new_row = incoming_frame[i];
			
			// loop backwards through each element in the row
			for(int j = incoming_frame[i].size() - 1; j >= 0; --j) {
				
				// we don't do anything to the first row, previous computation should have corrected it
				if(j == 0){
					continue;
				}

				// copy out our values to compare
				const string& current_value = incoming_frame[i][j];
				const string& next_value = incoming_frame[i][j-1];

				// the most common case is that the value we're looking at is the current value is an empty
				if(current_value == empty){

					// if the value above an empty is a particle, then we drop the particle into the empty
					// then, we declare the next value as empty, as it was previously occupied by a particle
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

			new_frame.push_back(new_row);

		}

		return new_frame;

	}

	vector<vector<string>> rotate_clockwise(vector<vector<string>> const& frame) {

		// transpose
		// reverse order

	}

	void print_frame(vector<vector<string>> const& frame) {
		for (const auto& row : frame) {
			for (const auto& element : row) {
				std::cout << element << " ";
			}
			std::cout << std::endl;
		}
	}


}  // namespace lush::particles

int main(int argc, char** argv) {

	using namespace lush;

	particles::print_frame(particles::input_frame_1);

}