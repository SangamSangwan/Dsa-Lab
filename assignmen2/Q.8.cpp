#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
   int arr[] = {1, 2, 2, 3, 4, 1};
    int n = 6;

    int count = 0;
    for(int i=0; i<n; i++) {
        bool found = false;
        for(int j=0; j<i; j++) {
            if(arr[i] == arr[j]) {
                found = true;
                break;
            }
        }
        if(!found) count++;
    }
    cout << "Distinct count: " << count;
    return 0;
}
