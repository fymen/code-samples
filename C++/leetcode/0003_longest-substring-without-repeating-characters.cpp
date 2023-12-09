#include<iostream>
#include<vector>
#include<string>
#include <unordered_map>
// #include<map>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int last = 0;
    int count = 0;
    int max_count = 0;
    int j = 0;

    for (int i=0; i<s.size(); i++) {
      for (j=last;j<i;j++) {
        if (s[i] == s[j]) {
          last = j+1;
          count = i-j;
          break;
        }
      }

      if (j == i) {
        count++;
        max_count = (max_count > count) ? max_count : count;
      }
    }

    return max_count;
  }

  // With map
  int lengthOfLongestSubstring_v1(string s) {
    unordered_map<char, int> imap;
    int count = 0;
    int max_count = 0;
    int tmp = 0;

    for (int i=0; i<s.size(); i++) {
      if (imap.count(s[i]) && imap[s[i]] >= tmp) {
        count = i - imap[s[i]];
        tmp = imap[s[i]] + 1;
      }
      else {
        count++;
        max_count = (max_count > count) ? max_count : count;
      }

      imap[s[i]] = i;
    }
    return max_count;
  }
};

int main(int argc, char *argv[])
{
  std::string test {"abcabcbb"};
  Solution sol;
  std::cout << sol.lengthOfLongestSubstring_v1(test) << std::endl;

  return 0;
}
