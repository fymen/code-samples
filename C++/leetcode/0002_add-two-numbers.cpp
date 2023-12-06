/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include<iostream>
#include<vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* nodeA = l1;
    ListNode* nodeB = l2;
    ListNode* nodeO, *NodeOut;
    nodeO = NodeOut = new ListNode();

    int value = 0;
      
    while (nodeA != nullptr || nodeB != nullptr) {
      if (nodeA != nullptr) {
        nodeO->val += nodeA->val;
        nodeA = nodeA->next;
      }

      if (nodeB != nullptr) {
        nodeO->val += nodeB->val;
        nodeB = nodeB->next;
      }

      if (nodeO->val / 10) {
        nodeO->next = new ListNode(1);
      }
      
      nodeO->val %= 10;

      if (nodeO->next == nullptr) {
        if (nodeA != nullptr || nodeB != nullptr) {
          nodeO->next = new ListNode(0);
          nodeO = nodeO->next;
        }
        else {
          break;
        }
      }
      else  {
        nodeO = nodeO->next;
      }
    }
    
    return NodeOut;
  }

  ListNode* formNode(const std::vector<int> & nums) {
    if (nums.size() <= 0)
      return NULL;

    ListNode *node = nullptr;
    ListNode *nodeHead = node = new ListNode();
    int size = nums.size(); 
    int i = 0;
    while (1) {
      if (i < size) {
        node->val = nums[i];
        if (++i < size) {
          node->next = new ListNode();
          node = node->next;
        }
      }
      else {
        break;
      }
    }
    return nodeHead;
  }
  
  void releaseNode(ListNode *node) {
    ListNode* tmp = node;
    while (tmp != nullptr) {
      ListNode *next = tmp->next;
      free(tmp);
      tmp = next;
    }
  }
  
  void printNode(ListNode *node) {
    if (node != nullptr) {
      printNode(node->next);
      std::cout << node->val;
    }
  }
};

int main(int argc, char *argv[])
{
  ListNode *Output = nullptr;
  
  Solution solution;

  ListNode *InputA = solution.formNode({9,9,9,9,9,9});
  ListNode *InputB = solution.formNode({5,6});

  std::cout << "Inputs: ";
  solution.printNode(InputA);
  std::cout << ", ";
  solution.printNode(InputB);
  std::cout << std::endl;
  
  Output = solution.addTwoNumbers(InputA, InputB);

  std::cout << "Output: ";
  solution.printNode(Output);
  std::cout << std::endl;

  solution.releaseNode(InputA);
  solution.releaseNode(InputB);
  solution.releaseNode(Output);

  return 0;
}
