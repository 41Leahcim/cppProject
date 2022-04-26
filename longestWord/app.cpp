#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>

bool isValid(std::string word){
    for(int i = 0;i < word.length();i++){
        const char c = word[i];
        if(c == 'D' || c == 'g' || c == 'G' || c == 'i' || c == 'I' || c == 'j' || c == 'k' ||
           c == 'K' || c == 'm' || c == 'M' || c == 'q' || c == 'Q' || c == 't' || c == 'T' ||
           c == 'v' || c == 'V' || c == 'w' || c == 'W' || c == 'x' || c == 'X' || c == 'z' ||
           c == 'Z'){
            return false;
        }
        if(i >= 2 && word[i] == word[i - 1] && word[i] == word[i - 2]){
            return false;
        }
    }
    return true;
}

void getLongestWords(std::istream& source, std::vector<std::string>& longest7SegmentWords, std::vector<std::string>& longestWords){
    std::string word;
    longest7SegmentWords.assign({""});
    longestWords.assign({""});
    while(std::getline(source, word)){
        if(word.length() >= longest7SegmentWords[0].length() && isValid(word)){
            if(word.length() == longest7SegmentWords[0].length()){
                longest7SegmentWords.push_back(word);
            }else if(word.length() > longest7SegmentWords[0].length()){
                longest7SegmentWords.clear();
                longest7SegmentWords.assign({word});
            }
        }
        if(word.length() == longestWords[0].length()){
            longestWords.push_back(word);
        }else if(word.length() > longestWords[0].length()){
            longestWords.clear();
            longestWords.assign({word});
        }
    }
}

void displayWords(const std::vector<std::string>& words){
    for(std::string longWord : words){
        std::cout << longWord << "\n";
    }
}

int main(){
    std::string word;
    std::ifstream file("words.txt");
    std::vector<std::string> longest7SegmentWords;
    std::vector<std::string> longestWords;
    getLongestWords(file, longest7SegmentWords, longestWords);
    std::cout << "Longest word(s) (" << longestWords[0].length() << "):\n";
    displayWords(longestWords);
    std::cout << "Longest word(s) on a 7-segment display (" << longest7SegmentWords[0].length() << "):\n";
    displayWords(longest7SegmentWords);
}
