#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string word1, string word2){
            return word1.length() < word2.length();
        });
        int longest_len = 0;
        unordered_map<string, int> word_chain;
        for (string word: words) {
            int current_len = 1;
            int n = word.length();
            for (int i = 0; i < n; i++) {
                // predecessor = word.substr(0, i) + word.substr(i + 1);
                string predecessor = word.substr(0, n - i - 1) + word.substr(n - i);
                if (word_chain.find(predecessor) != word_chain.end()) {
                    current_len = max(word_chain[predecessor] + 1, current_len);
                }
            }
            // Update the longest word chain from the previous chain
            word_chain[word] = current_len;
            longest_len = max(current_len, longest_len);
        }
        
        return longest_len;
    }


    // int longestStrChain(std::vector<std::string>& words) {
    //     // Sort the words by length
    //     std::sort(words.begin(), words.end(), [](const std::string& a, const std::string& b) {
    //         return a.length() < b.length();
    //     });
        
    //     int maxLength = 1;
    //     std::unordered_map<std::string, int> wordChainLength;
        
    //     for (const std::string& word : words) {
    //         int currentLength = 1;
    //         // Generate all possible predecessors by removing one character
    //         for (int i = 0; i < word.length(); ++i) {
    //             string word1 = word.substr(0, i);
    //             string word2 = word.substr(i + 1);
    //             std::string predecessor = word1 + word2;
    //             if (wordChainLength.find(predecessor) != wordChainLength.end()) {
    //                 currentLength = std::max(currentLength, wordChainLength[predecessor] + 1);
    //             }
    //         }
    //         wordChainLength[word] = currentLength;
    //         maxLength = std::max(maxLength, currentLength);
    //     }
        
    //     return maxLength;
    // }
};


int main()
{
    vector<string> words = {"a","b","bdacx","ba","abc","bca","cba","bac","cbda","bdac"};
    Solution obj;

    obj.longestStrChain(words);

    return 0;
}