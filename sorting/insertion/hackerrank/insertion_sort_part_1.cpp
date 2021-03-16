/**
 * Hackerrank - Insertion Sort - Part 1
 * https://www.hackerrank.com/challenges/insertionsort1/problem
 */


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool verified_unsorted(vector<int> array, int n) {
    int previous = array[0];

    for(int i = 1; i < n; i++) {
        if(previous > array[i]) {
            return true;
        }
    }

    return false;
}

void print_array(vector<int> array, int n) {
    for(int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }

    cout << endl;
}

// Complete the insertionSort1 function below.
void insertionSort1(int n, vector<int> arr) {
    for(int j = n - 1; j >= 0; j--) {
        int key = arr[j];
        int i = j - 1;

        while(i > -1 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i = i - 1;
	    print_array(arr, n);
        }

        arr[i + 1] = key;
    }

    print_array(arr, n);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
