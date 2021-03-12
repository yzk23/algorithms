#include <iostream>

using namespace std;

void print_array(int* A, int length) {
	for(int i = 0; i < length; i++)
		cout << A[i] << " ";
	cout << endl;
}

int main() {
	int array_length = 6;
	int A[array_length] = {31, 41, 59, 26, 41, 58};

	print_array(A, array_length);
	for(int j = array_length - 2; j >= 0; j--){
		int key = A[j];
		int i = j + 1;

		while(i <= array_length - 1 && A[i] < key) {
			A[i - 1] = A[i];
			i = i + 1;
		}

		A[i - 1] = key;
		print_array(A, 6);
	}

	return 0;
}
