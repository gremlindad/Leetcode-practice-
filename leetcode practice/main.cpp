#include<vector>
#include<iostream>
#include<string>

using namespace std;


vector<int> mySort(vector<int> v);
bool myBinSearch(int num, const vector<int>& nums);

 
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

    nums1 = mySort(nums1);
    nums2 = mySort(nums2);

    int i = 0;
    int j = 1;
    vector<int> output;


    //get shorter list and use that
    vector<int> smaller = nums1;
    vector<int> bigger = nums2;

    if (nums1.size() > nums2.size()) {
        bigger = nums1;
        smaller = nums2;
    }

    if (myBinSearch(smaller[0], bigger))output.push_back(smaller[0]);

    while (j < smaller.size()) {
        if (smaller[i] == smaller[j])j++;//if we're on the same number move along one
        else {
            //if we find a different number check if its in the other list
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
        for (int j = i+1; j < v.size(); j++) {
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
    int r = static_cast<int>(nums.size() - 1);
    int m = 0;

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
    return false;
}



int main() 
{
    vector<int> v1 = { 1,2,3,4,5,6,6,7,7,8,6,3,2,1,10};
    vector<int> v2 = { 2,2,4,5,10 };

    for (auto& i : intersection(v1, v2)) {
        cout << i << '\n';
    }

    

    

}