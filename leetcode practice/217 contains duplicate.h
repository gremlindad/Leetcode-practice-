#pragma once
#include <vector>
#include <unordered_set> 

using namespace std;

//O(n) time complexity because it only has to run through the size of the array once
//O(n) space complexity because it has to create a hash map potentially the size of the 
//initial array


    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> elements;


        for (auto& n : nums) {
            //the insert function returns a bool and an iterator so we can check
            //if it inserted correctly
            if (!((elements.insert(n)).second))return true;
        }
        return false;
    }
