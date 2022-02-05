#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string x;
        for (unsigned int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && i != s.size() - 1) {
                x.push_back(s[i]);
            }
            else if (i == s.size() - 1) {
                x.push_back(s[i]);
                words.push_back(x);
            }
            else {
                words.push_back(x);
                x = "";
            }
        }
        
        vector<string> wordsx;
        string reversed;
        for (unsigned int i = 0; i < words.size(); i++) {
            string current = words[i];
            for (int a = current.size() - 1; a >= 0; a--) {
                reversed.push_back(current[a]);
            }
            wordsx.push_back(reversed);
            reversed = "";
        }

        string finished;
        finished.append(wordsx[0]);
        for (unsigned int i = 1; i < wordsx.size(); i++) {
            finished.push_back(' ');
            finished.append(wordsx[i]);
        }
        
        return finished;
    }
    
};
