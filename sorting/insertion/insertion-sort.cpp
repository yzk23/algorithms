#include <iostream>

using namespace std;

void print_array(int *array, int length) {
	for(int i = 0; i < length; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

int main() {
	int length = 6;
	int array [length] = {5, 2, 4, 6, 1, 3};
	print_array(array, length);

	for(int j = 1; j < length; j++) {
		int key = array[j];

		int i = j - 1;
		while(i > -1 && array[i] > key){
			array[i + 1] = array[i];
			i = i - 1;
		}
		array[i + 1] = key;

		print_array(array, length);
	}

	return 0;
}
