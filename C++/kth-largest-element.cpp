#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    // Method 1: Using Min Heap (Priority Queue)
    int findKthLargestHeap(std::vector<int>& nums, int k) {
        // Create a min heap
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        
        // Push elements into the heap
        for (int num : nums) {
            pq.push(num);
            // If heap size exceeds k, remove the smallest element
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        // The top element is the kth largest
        return pq.top();
    }

    // Method 2: Using QuickSelect Algorithm
    int findKthLargestQuickSelect(std::vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size() - 1, nums.size() - k);
    }

private:
    int quickSelect(std::vector<int>& nums, int left, int right, int k) {
        // If the list contains only one element, return that element
        if (left == right) return nums[left];
        
        // Select a pivot randomly
        int pivotIndex = left + rand() % (right - left + 1);
        pivotIndex = partition(nums, left, right, pivotIndex);
        
        // The pivot is in its final sorted position
        if (k == pivotIndex) {
            return nums[k];
        }
        // If k is less than the pivot index, search the left subarray
        else if (k < pivotIndex) {
            return quickSelect(nums, left, pivotIndex - 1, k);
        }
        // If k is greater than the pivot index, search the right subarray
        else {
            return quickSelect(nums, pivotIndex + 1, right, k);
        }
    }
    
    int partition(std::vector<int>& nums, int left, int right, int pivotIndex) {
        int pivotValue = nums[pivotIndex];
        std::swap(nums[pivotIndex], nums[right]);
        int storeIndex = left;
        
        for (int i = left; i < right; i++) {
            if (nums[i] < pivotValue) {
                std::swap(nums[storeIndex], nums[i]);
                storeIndex++;
            }
        }
        
        std::swap(nums[right], nums[storeIndex]);
        return storeIndex;
    }
};

// Test function
void runTest(std::vector<int>& nums, int k, int expected) {
    Solution sol;
    int resultHeap = sol.findKthLargestHeap(nums, k);
    int resultQuickSelect = sol.findKthLargestQuickSelect(nums, k);
    
    std::cout << "Input: [";
    for (size_t i = 0; i < nums.size(); ++i) {
        std::cout << nums[i];
        if (i < nums.size() - 1) std::cout << ", ";
    }
    std::cout << "], k = " << k << std::endl;
    
    std::cout << "Expected: " << expected << std::endl;
    std::cout << "Heap Result: " << resultHeap << std::endl;
    std::cout << "QuickSelect Result: " << resultQuickSelect << std::endl;
    
    if (resultHeap == expected && resultQuickSelect == expected) {
        std::cout << "Test Passed!" << std::endl;
    } else {
        std::cout << "Test Failed!" << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    // Test case 1: Regular case
    std::vector<int> nums1 = {3, 2, 1, 5, 6, 4};
    int k1 = 2;
    runTest(nums1, k1, 5);

    // Test case 2: K is 1 (maximum element)
    std::vector<int> nums2 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k2 = 1;
    runTest(nums2, k2, 6);

    // Test case 3: K is the size of the array (minimum element)
    std::vector<int> nums3 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k3 = 9;
    runTest(nums3, k3, 1);

    // Test case 4: Array with duplicate elements
    std::vector<int> nums4 = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k4 = 4;
    runTest(nums4, k4, 4);

    // Test case 5: Single element array
    std::vector<int> nums5 = {1};
    int k5 = 1;
    runTest(nums5, k5, 1);

    return 0;
}