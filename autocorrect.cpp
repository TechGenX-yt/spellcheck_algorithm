// c++ for applications 

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getDistance(const string& search_input, const string& word) {
    int a = search_input.length();
    int b = word.length();
    int addn_wt = 1, del_wt = 1, subs_wt = 1;

    // if search input is incomplete, i.e. a substring of word
    if (word.find(search_input) != string::npos) {
        return (b - a) * addn_wt * 0.25;
    }

    // initialization of matrix
    vector<vector<int>> distanceMatrix(a + 1, vector<int>(b + 1, 0));

    // storing non-recursive values
    for (int i = 0; i <= a; i++) {
        distanceMatrix[i][0] = i;
    }
    for (int j = 0; j <= b; j++) {
        distanceMatrix[0][j] = j;
    }

    // recursive steps
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (search_input[i - 1] == word[j - 1]) {  // if end characters match up
                distanceMatrix[i][j] = distanceMatrix[i - 1][j - 1];
            } else {
                distanceMatrix[i][j] = min({
                    distanceMatrix[i][j - 1] + addn_wt,
                    distanceMatrix[i - 1][j] + del_wt,
                    distanceMatrix[i - 1][j - 1] + subs_wt
                });
            }
        }
    }

    return distanceMatrix[a][b];
}
