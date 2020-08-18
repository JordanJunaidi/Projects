#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

// put your solution here:
std::string lowercase(std::string s) {
	std::string r = s;
	for (unsigned int i = 0; i < s.size(); i++) {
		if (isupper(r[i])) {
			r[i] = tolower(r[i]);
		}
	}
	return r;
}

void solve(std::vector<std::string> words) {
	std::vector<std::string> lower;
	std::vector<std::string> sorted;
	for (unsigned int i = 0; i < words.size(); i++) {
		lower.push_back(lowercase(words[i]));
	}
	std::sort(lower.begin(), lower.end());
	for (unsigned int n = 0; n < lower.size(); n++) {
		for (unsigned int x = 0; x < words.size(); x++) {
			if (lower[n] == lowercase(words[x])) {
				sorted.push_back(words[x]);
				words[x] = "//";
				break;
			}
		}
	}

	for (unsigned int y = 0; y < sorted.size(); y++) {
		std::cout << sorted[y] << std::endl;
	}

}


void test() {
  std::vector<std::string> v = {"james", "James", "Z", "z", "A", "B", "AA", "ABC", "abc", "bca"};

  std::cout << "Expected Answer:" << std::endl << "A" << std::endl << "AA" << std::endl << 
    "abc" << std::endl << "ABC" << std::endl <<  "B" << std::endl << "bca" << std::endl << "James" <<
    std::endl << "james" << std::endl << "z" << std::endl << "Z" << std::endl;

  std::cout << "Your Answer: " << std::endl;
  solve(v);
}


int main(void) {
  test();

  return 0;
}

