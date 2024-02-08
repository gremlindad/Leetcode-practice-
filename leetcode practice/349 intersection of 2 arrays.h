#pragma once
#include<vector>
#include<iostream>
#include<string>

using namespace std;


vector<int> mySort(vector<int> v);
bool myBinSearch(int num, const vector<int>& nums);


vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    //sort the arrays so that we can search them more efficiently
    nums1 = mySort(nums1);
    nums2 = mySort(nums2);


    //create two pointers, one of them at the start and one just after so that we are 
    //able to compare two different values initially
    int i = 0;
    int j = 1;
    //store output
    vector<int> output;


    //initially set which list is bigger and smaller so that we can use the 
    //smaller array as the set of common values and thus do less checks
    vector<int> smaller = nums1;
    vector<int> bigger = nums2;

    //if different reassign
    if (nums1.size() > nums2.size()) {
        bigger = nums1;
        smaller = nums2;
    }

    //do one initial check on the first value
    //because we know the first value is always unique 
    if (myBinSearch(smaller[0], bigger))output.push_back(smaller[0]);

    //iterate over the smaller array
    while (j < smaller.size()) {
        //check to see if we have duplicate values
        //if we do, them move along one and check again
        if (smaller[i] == smaller[j])j++;
        //
        //
        else {
            //if we find a different number check if its in the other larger array
            if (myBinSearch(smaller[j], bigger))output.push_back(smaller[j]);
            //then snap i to j and move j along one 
            i = j;
            j++;
        }
    }

    return output;

}

vector<int> mySort(vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    
    return v;
}

bool myBinSearch(int num, const vector<int>& nums) {
    int l = 0;
    //have to cast the .size() value to an int because 
    //the size type is unsigned
    int r = static_cast<int>(nums.size() - 1);
    int m = 0;

    //as we are not returning the value of l
    //i need to run the loop one more time to see if the final output is 
    //the target value
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == num)return true;
        else if (nums[m] > num) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    //if we didnt find it
    return false;
}