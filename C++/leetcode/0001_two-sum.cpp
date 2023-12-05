#include <iostream>
#include <vector>
#include <unordered_map>
// make -k 0001_two-sum && ./0001_two-sum

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> imap;
    int n = nums.size();

    for (int i {0}; i<n; i++) {
      auto compliment = target - nums[i];
      if (imap.count(compliment)) {
        return {i, imap[compliment]};
      }
      imap[nums[i]] = i;
    }

    return {};
  }
};

int main(int argc, char *argv[])
{
  vector<int> numbers {2,7,11,15};
  int target = 22;

  Solution tSolution;

  auto index = tSolution.twoSum(numbers, target);

  if (index.empty() != true) {
    cout << index[0] << " " << index[1] << endl;
  }
  else {
    cout << "Not found!" << endl;
  }

  return 0;
}
