#include <iostream>
#include <string>
#include <vector>



template <typename T>
class vector: public std::vector<T> {

public:

	vector swap(int& i, int& j) {

		T tmp;
		vector v(*this);
		tmp = this->at(i);
		v[i] = v[j];
		v[j] = tmp;
		return v;

	}


};


template<typename T>
void print_vector(std::vector<T> v) {

	for(T el : v){

		std::cout <<  "| " << el << " | ";

	}
	std::cout << std::endl;

}


typedef std::vector<char> char_vector;


//size - number of elements to choose, recursion depth always till size
template<typename T>
void combinations(vector<T> elements, int index, std::vector<vector<T>>& container, int size, vector<T> combination) {


	if(size == 0) {
		container.push_back(combination);
		return;
	} 

	for(int i = index; i < elements.size(); i++) {

		vector<T> new_comb(combination), elem_copy(elements);
		combination.push_back(elements[i]);
		elem_copy.erase(elem_copy.begin()+i);
		combinations(elem_copy, i, container, size-1, combination);
	}


}



template<typename T>
void permutations(vector<T>& v, int left, std::vector<vector<T>>& container) {

	int right = v.size() - 1;
	if(left == v.size()-1)
		container.push_back(v);

	for(int i = right; i >= left; --i) {

		vector<char> swapped = v.swap(left, i);
		permutations(swapped, left+1,  container);

	}

}



int main(int argc, char** argv) {

	vector<char> characters;
	std::cout << "Characters: " << argv[1] << std::endl; 
	

	std::string arg(argv[1]);
	for(char c : arg) {

		characters.push_back(c);

	}
	

	std::vector<vector<char>> comb, perm;

	int index = characters.size()-2;
	combinations(characters, 0, comb, 2, vector<char>());
	permutations(characters, 0, perm);

	//std::cout << comb.size() << std::endl; 
	// for(char_vector c : perm) {

	// 	print_vector(c);

	// }

	std::cout << "Number of combinations: " <<  comb.size() << std::endl;
	std::cout << "Number of permutations: " <<  perm.size() << std::endl;

	std::cout << "Finished program" << std::endl;
	return 0;
}