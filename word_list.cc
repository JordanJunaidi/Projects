#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main(void) {

	string line;
	ifstream myfile ("words.txt");

	vector<string> words;
	vector<string>::iterator it;
	string userword;

	if (myfile.is_open()) {
		while (getline(myfile, line)) {
			words.push_back(line);
		}
		myfile.close();
	}

	cout << "Enter a word:" << endl;

	while (getline(cin, userword) && userword != "") {

		it = find(words.begin(), words.end(), userword);
		if (it != words.end()) {
			cout << endl << "Your word was found in the list." << endl;
			cout << endl << "Enter a word:" << endl;
		}
		else {
			cout << endl << "Your word was not found." << endl;
			cout << endl << "Enter a word:" << endl;
		}

	}

	if (myfile.eof()) {
		sort(words.begin(), words.end());
		ofstream outputfile;
		outputfile.open("sorted.txt");
		for (unsigned int i = 0; i < words.size(); i++) {
			outputfile << words[i] << endl;
		}
		outputfile.close();
		cout << "Created sorted file." << endl;

		return 0;

	}


}