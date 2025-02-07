#include "balancedGroups.h"

// your includes here
#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

int vecSum(vector<int> vec){
    int sum = 0;
    for(int i = 0; i < vec.size(); i++){
        sum += vec[i];
    }
    return sum;
}

Assignment balancedGroups(std::vector<int> const &birthdays) {

    vector<int> sortedBirthdays = birthdays;
    sort(sortedBirthdays.begin(), sortedBirthdays.end());

    vector<int> va;
    vector<int> vb;

    int first = 0;
    int last = sortedBirthdays.size() - 1;

    //cout << "size: " << last;

    while(sortedBirthdays.size() - va.size() - vb.size() > 3){
        if(first % 2 == 0){
            va.push_back(sortedBirthdays[first]);
            va.push_back(sortedBirthdays[last]);
        }
        else{
            vb.push_back(sortedBirthdays[first]);
            vb.push_back(sortedBirthdays[last]);

        }

        first++;
        last--;
    }

    cout << "FIRST: " << first << endl;
    cout << "LAST: " << last << endl;

    //Three leftover values
    if(first + 2 == last){
        va.push_back(sortedBirthdays[first]);
        vb.push_back(sortedBirthdays[last]);
        if(vecSum(va) > vecSum(vb)){
            vb.push_back(sortedBirthdays[first + 1]);
        }
        else{
            va.push_back(sortedBirthdays[first + 1]);
        }
    }
    //Two leftover values
    else if(first + 1 == last){
        int smaller = min(sortedBirthdays[first],sortedBirthdays[last]);
        int larger = max(sortedBirthdays[first],sortedBirthdays[last]);
        if(vecSum(va) > vecSum(vb)){
            va.push_back(smaller);
            vb.push_back(larger);
        }
        else{
            vb.push_back(smaller);
            va.push_back(larger);
        }


    }
    else{
        cout << "what the fuck happened" << endl;
    }

    int diff = abs(vecSum(va) - vecSum(vb));

    cout << "Difference: " << diff << endl;
	return Assignment(diff, va, vb); // Don't forget to change this
}

/* your helper function here if you have any */




int main(){

    vector<int> myBirthdays = {3, 27, 4, 5, 20, 6};
    Assignment myAss = balancedGroups(myBirthdays);
    myAss.printAssignment();
}