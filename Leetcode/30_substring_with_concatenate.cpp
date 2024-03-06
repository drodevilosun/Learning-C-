#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // vector<int> findSubstring(string s, vector<string>& words) {
    //     vector<int> result;
    //     unordered_map<string, int> concat_words;
    //     int word_len = words[0].length();
    //     for (int i = 0; i < words.size(); i++)
    //     {
    //         concat_words[words[i]]++;
    //     }

    //     int concat_len = word_len * words.size();
    //     if (s.length() < concat_len)
    //         return {};
    //     unordered_map<string, int> s_comparison;
    //     for (int i = 0; i <= s.length() - concat_len; i++)
    //     {
    //         for (int num_word = i; num_word < concat_len + i; num_word += word_len)
    //         {
    //             string s_word = s.substr(num_word, word_len);
    //             s_comparison[s_word]++;
    //         }
            
    //         auto it = concat_words.begin();
    //         for (; it != concat_words.end(); it++)
    //         {
    //             if (s_comparison[it->first] != it->second)
    //                 break;
    //         }
    //         if (it == concat_words.end())
    //             result.push_back(i);
    //         s_comparison.clear();
    //     }
        
    //     return result;
    // }
    // My other way
    // vector<int> findSubstring(string s, vector<string>& words) {
    //     vector<int> res;
    //     int left = 0;
    //     int n = words[left].length();
    //     int right = words.size()*n;
    //     if (s.length() < right)
    //         return {};
    //     unordered_map<string, int> un_word;
    //     for (string word: words) {
    //         un_word[word]++;
    //     }
    //     while (right - left == n*words.size() && right <= s.size()) {
    //         int curr = left;
    //         unordered_map<string, int> compare;
    //         while (curr < right) {
    //             string word = s.substr(curr, n);
    //             compare[word]++;
    //             curr += n;
    //         }
    //         auto it = un_word.begin();
    //         for (; it != un_word.end(); it++) {
    //             if (it->second != compare[it->first])
    //                 break;
    //         }
    //         if (it == un_word.end()) {
    //             res.push_back(left);
    //         }

    //         left += 1;
    //         right += 1;

    //     }
    //     return res;
    // }

    vector<int> findSubstring(string s, vector<string>& words) {
        if (s.empty() || words.empty())
            return {};
        vector<int> res;
        int word_len = words[0].length();
        int total_len = word_len * words.size();
        unordered_map<string, int> un_words;
        for (string word: words) {
            un_words[word]++;
        }

        for (int i = 0; i < word_len; i++) {
            int left = i, right = i;
            unordered_map<string, int> curr_word;

            while (right + word_len <= s.length()) {
                string sub = s.substr(right, word_len);
                right += word_len;
                if (un_words.find(sub) != un_words.end()) {
                    curr_word[sub]++;
                    while (un_words[sub] < curr_word[sub]) {
                        curr_word[s.substr(left, word_len)]--;
                        left += word_len;
                    }
                    if (right - left == total_len) {
                        res.push_back(left);
                    }
                }
                else {
                    curr_word.clear();
                    left = right;
                }

            }
        }
        return res;
    }

    // Optimize way:
    // vector<int> findSubstring(string s, vector<string>& words) {
    //     if (s.empty() || words.empty()) {
    //     return {};
    //     }

    //     int word_len = words[0].size();
    //     int total_len = word_len * words.size();
    //     unordered_map<string, int> word_freq;
    //     vector<int> result;

    //     for (const string& word : words) {
    //         word_freq[word]++;
    //     }

    //     for (int i = 0; i < word_len; i++) {
    //         int left = i;
    //         int right = i;
    //         unordered_map<string, int> curr_freq;

    //         while (right + word_len <= s.size()) {
    //             string word = s.substr(right, word_len);
    //             right += word_len;

    //             if (word_freq.find(word) != word_freq.end()) {
    //                 curr_freq[word]++;

    //                 while (curr_freq[word] > word_freq[word]) {
    //                     curr_freq[s.substr(left, word_len)]--;
    //                     left += word_len;
    //                 }

    //                 if (right - left == total_len) {
    //                     result.push_back(left);
    //                 }
    //             } else {
    //                 curr_freq.clear();
    //                 left = right;
    //             }
    //         }
    //     }

    //     return result;
    // }
};

int main()
{
    Solution obj;
    // string s = "wordgoodgoodgoodbestwordword";
    // vector<string> words = {"word","good","best","word"};
    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    vector<string> words = {"fooo","barr","wing","ding","wing"};
    
    
    vector<int> out = obj.findSubstring(s, words);

    // cout << "Output is: " << out << endl;

    return 0;
}