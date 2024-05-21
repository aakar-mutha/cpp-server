#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;
string directory = "./";

int main(int argc, char* argv[]) {
	if(argc >= 2){
		directory = argv[1];
	}
	else {
		cout << "Enter a directory." << endl;
		exit(1);
	}

	cout << directory << endl;
	
	for (const auto& entry : fs::directory_iterator(directory)) {
		std::cout << entry.path() << std::endl;
	}
	return 0;
}