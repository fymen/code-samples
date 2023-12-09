#include<iostream>
#include<vector>
#include<array>
#include<algorithm>

using namespace std;

class Solution {
public:
  double findMedianSortedArrays_v1(vector<int>& nums1, vector<int>& nums2) {
    vector<int> v;
    for (auto num : nums1) {
      v.push_back(num);
    }

    for (auto num : nums2) {
      v.push_back(num);
    }

    sort(v.begin(), v.end());
    int n = v.size();

    for(auto num:v) {
      cout << num <<endl;
    }
    return n%2 ? v[n/2] : ((v[n/2] + v[n/2-1]) * 1.0 / 2);
  }

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    array<int, 2000> num = {};
    int j, k;
    double retVal;

    k = j = 0;

    for(int i=0;i<nums1.size();i++) {
      if (j >= nums2.size()) {
        num[k] = nums1[i];
        k++;
        continue;
      }
      
      if (nums1[i] < nums2[j]) {
        num[k] = nums1[i];
        k++;
      }
      else if (nums1[i] == nums2[j]) {
        num[k] = nums2[j];
        j++;
        k++;
        num[k] = nums1[i];
        k++;

      }
      else {
        num[k] = nums2[j];
        k++;
        j++;
        while (j < nums2.size()) {
          if (nums2[j] < nums1[i]) {
            num[k] = nums2[j];
            k++;
            j++;
          }
          else {
            break;
          }
        }
        num[k] = nums1[i];
        k++;

      }

    }
    
    while (j < nums2.size()) {
      num[k] = nums2[j];
      k++;
      j++;
    }
    
    for (int l=0;l<k;l++) {
      cout << l << " " << num[l] << endl;
    }
    
    int median = (k) / 2;
    
    if ((k)%2 == 0) {
      retVal = (num[median] + num[median-1]) * 1.0 / 2.0;
    }
    else {
      retVal = num[median] * 1.0;
    }
    return retVal;
  }
};

int main(int argc, char *argv[])
{
  vector<int> numA = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22};
  vector<int> numB = {0,6};

  Solution sol;
  std::cout << sol.findMedianSortedArrays_v1(numA, numB) << std::endl;

  return 0;
}
