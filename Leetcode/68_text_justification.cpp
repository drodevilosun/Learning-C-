#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    // vector<string> fullJustify(vector<string>& words, int maxWidth) {
    //     vector<string> output;
    //     int maxLength = 0;
    //     int maxNumSpace = 0;
    //     int num_word = 0;
    //     string lineWord;
    //     for (auto it = words.begin(); it != words.end(); it++)
    //     {
    //         string word = *it;
    //         bool lastLine = false;
    //         if (it == words.end() - 1)
    //             lastLine = true;
    //         if (lastLine == true || maxLength + word.length() + maxNumSpace < maxWidth)
    //         {
    //             num_word++;
    //             lineWord += word;
    //             maxLength += word.length(); 
    //             lineWord += ' '; // at least 1 space
    //             maxNumSpace += 1;
    //         }

    //         if (maxLength + word.length() + maxNumSpace >= maxWidth || true == lastLine)
    //         {

    //             if (maxLength + word.length() + maxNumSpace == maxWidth)
    //                 lineWord += word.length();


    //             {
    //                 int num_space_slot = maxWidth - maxLength;
    //                 int maximum_additional_space_time = num_word != 1 ? num_space_slot % (num_word - 1) : num_space_slot % num_word;
    //                 int num_space_each_word = num_word != 1 ? num_space_slot / (num_word - 1) : num_space_slot / num_word;
    //                 int additional_each_space = num_space_each_word - maximum_additional_space_time;
    //                 int count_additional_space_time = 0;
    //                 if (lastLine == false)
    //                 {
    //                     for (int i = 0; i < lineWord.length(); i++)
    //                     {
    //                         if (lineWord[i] == ' ')
    //                         {
    //                             int count_original_space_time = 1;
    //                             int num_space = 0;
    //                             while (count_original_space_time < num_space_each_word)
    //                             {
    //                                 lineWord.insert(i, " ");
    //                                 count_original_space_time++;
    //                                 i++;
    //                             }
                                
    //                             while (num_space < additional_each_space - num_space_each_word && 
    //                                 count_additional_space_time < maximum_additional_space_time)
    //                             {
    //                                 lineWord.insert(i, " ");
    //                                 i++;
    //                             }
    //                             count_additional_space_time++;
    //                         }
    //                     }
    //                     // remove trailing white space
    //                     if (num_word != 1 && it != words.end() - 1)
    //                     {
    //                         int right = lineWord.length() - 1;
    //                         while (right > 0 && lineWord[right] == ' ')
    //                             right--;
    //                         lineWord = lineWord.substr(0 , right + 1);
    //                     }
    //                 }
    //                 else {
    //                     string remain_space(maxWidth - lineWord.length(),' ');
    //                     lineWord += remain_space;
    //                 }
    //             }

    //             output.push_back(lineWord);
    //             lineWord = word + ' ';
    //             maxLength = word.length(); // at least 1 space
    //             maxNumSpace = 1;
    //             num_word = 1;
    //         }
    //     }
    //     return output;
    // }

    // std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
    //     std::vector<std::string> result;
    //     int n = 0;
        
    //     while (n < words.size()) {
    //         int num_word = n + 1;
    //         int lineLength = words[n].length();
            
    //         while (num_word < words.size() && lineLength + words[num_word].length() + (num_word - n - 1) < maxWidth) { // at least 1 space
    //             lineLength += words[num_word].length();
    //             num_word++;
    //         }
            
    //         int numWords = num_word - n;
    //         int totalSpaces = maxWidth - lineLength;
            
    //         if (numWords == 1 || num_word == words.size()) {
    //             result.push_back(words[n]);
                
    //             for (int k = n + 1; k < num_word; k++) {
    //                 result.back() += " " + words[k];
    //             }
                
    //             result.back() += std::string(maxWidth - result.back().length(), ' ');
    //         } else {
    //             int spacesBetweenWords = totalSpaces / (numWords - 1);
    //             int extraSpaces = totalSpaces % (numWords - 1);
                
    //             std::string line = words[n];
                
    //             for (int k = n + 1; k < num_word; k++) {
    //                 int spaces = spacesBetweenWords + (extraSpaces-- > 0 ? 1 : 0);
    //                 line += std::string(spaces, ' ') + words[k];
    //             }
                
    //             result.push_back(line);
    //         }
            
    //         n = num_word;
    //     }
        
    //     return result;
    // }

    // simulate the solution
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        vector<string> result;
        int nth = 0;

        while (nth < words.size())
        {
            int num_word = nth + 1;
            int line_length = words[nth].length();
            while (num_word < words.size() && (line_length + words[num_word].length() + (num_word - nth - 1)) < maxWidth)
            {
                line_length += words[num_word].length();
                num_word++;
            }
            int total_space = maxWidth - line_length;

            if (num_word - nth == 1 || num_word == words.size())
            {
                string line = words[nth];
                for (int i = nth + 1; i < num_word; i++) {
                    line += ' ' + words[i];
                }
                line += string(maxWidth - line.length(), ' ');
                result.push_back(line);
            }
            else {
                int space_between_word = total_space / (num_word - nth - 1);
                int extra_space = total_space % (num_word - nth - 1);
                string line = words[nth];
                for (int i = nth + 1; i < num_word; i++)
                {
                    int spaces = space_between_word + (extra_space-- > 0 ? 1 : 0);
                    line += string(spaces, ' ') + words[i];
                }
                result.push_back(line);
            }
            nth = num_word;
        }
        return result;
    }
};

int main()
{
    Solution obj;
    vector<string> words = {"ask","not","what","your","country","can","do","for","you","ask","what","you","can","do","for","your","country"};
    int maxWidth = 16;
    vector<string> output = obj.fullJustify(words, maxWidth);

    for (string line: output)
    {
        cout << line << endl;
    }

    return 0;
}