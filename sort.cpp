#include <iostream>
#include <queue>
#include <array>
#include <sstream>

using namespace std;

static int mergecount = 0;
void merge(std::vector<int>& a, int low, int middle, int high) {
	std::queue<int> al;
	std::queue<int> ar;
	int size = high - low;
	for (int i = low; i <= middle; i++) {
		al.push(a[i]);
		mergecount++;
	}
	for (int i = middle + 1; i <= high; i++) {
		ar.push(a[i]);
		mergecount++;
	}

	int i = low;
	while (al.size() && ar.size()) {
		if (al.front() < ar.front()) {
			a[i++] = al.front();
			al.pop();
		} else {
			a[i++] = ar.front();
			ar.pop();
		}
		mergecount++;
	}
	while (al.size()) {
		a[i++] = al.front();
		al.pop();
		mergecount++;
	}
	while (ar.size()) {
		a[i++] = ar.front();
		ar.pop();
		mergecount++;
	}
}

void mergesort(std::vector<int>& a, int low, int high) {
	if (low < high) {
		int middle = (high - low)/2 + low;
		// cout << "l=" << a[low] << " m=" << a[middle] << " h=" << a[high] << endl;
		mergesort(a, low, middle);
		mergesort(a, middle + 1, high);
		merge(a, low, middle, high);
	}
}

static int quickcount = 0;
int partition(std::vector<int>& a, int l, int h) {
	int p = h;
	int fh = l-1;
	int i;
	int tmp;
	for (i = l; i < h; i++) {
		if (a[i] < a[p]) {
			fh++;
			tmp = a[i];
			a[i] = a[fh];
			a[fh] = tmp;
		}
		quickcount++;
	}
	fh++;
	tmp = a[p];
	a[p] = a[fh];
	a[fh] = tmp;
	return fh;
}

void quicksort(std::vector<int>& a, int l, int h) {
	int p;
	quickcount++;
	if (l < h) {
		p = partition(a, l, h);
		quicksort(a, l, p-1);
		quicksort(a, p+1, h);
	}
}

void insertionsort(std::vector<int>& a) {
	int size = a.size();
	int count = 0;
	for (int i = 1; i < size; i++) {
		int j = i;
		if (a[j] > a[j - 1]) {
			count++;
		}
		while (a[j] < a[j - 1] && j > 0) {
			int temp = a[j];
			a[j] = a [j-1];
			a[j - 1] = temp;
			count++;
			j--;
		}
	}
	cout << "Insertion sort: " << count << " iterations" << endl;
}

void bubblesort(std::vector<int>& a) {
	int size = a.size();
	bool swapped = true;
	int count = 0;
	while (swapped) {
		swapped = false;
		for (int i = 0; i < size - 1; i++) {
			if (a[i+1] < a[i]) {
				swap(a[i], a[i + 1]);
				swapped = true;
			}
			count++;
		}
	}
	cout << "Bubble sort: " << count << " iterations" << endl;
}

void selectionsort(std::vector<int>& a) {
	int size = a.size();
	int count = 0;
	for (int i = 0; i < size - 1; i++) {
		int mina = a[i];
		int j = i;
		int min_ind = j;
		while (j < size) {
			if (a[j] < mina) {
				mina = a[j];
				min_ind = j;
			}
			j++;
			count++;
		}
		a[min_ind] = a[i];
		a[i] = mina;
	}
	cout << "Selection sort: " << count << " iterations" << endl;
}

int main() {
	std::vector<int> mya1 = {24,78,3,57,9,56,36,678,8,67,345,23,55,82,7,4,29,37,6,98,25,73,455,234,26,68,95,231};
	std::vector<int> mya2 = mya1;
	std::vector<int> mya3 = mya1;
	std::vector<int> mya4 = mya1;
	std::vector<int> mya5 = mya1;
	std::ostringstream a1out;
	std::ostringstream a2out;
	std::ostringstream a3out;
	std::ostringstream a4out;
	std::ostringstream a5out;

	cout << "n = " << mya1.size() << endl;

	mergesort(mya1, 0, mya1.size()-1);
	cout << "Merge sort: " << mergecount << " iterations" << endl;
	quicksort(mya2, 0, mya2.size()-1);
	cout << "Quick sort: " << quickcount << " iterations" << endl;
	insertionsort(mya3);
	bubblesort(mya4);
	selectionsort(mya5);

	for (int i = 0; i < mya1.size(); i++) {
		a1out << mya1[i] << " ";
		a2out << mya2[i] << " ";
		a3out << mya3[i] << " ";
		a4out << mya4[i] << " ";
		a5out << mya5[i] << " ";
	}
	cout << a1out.str() << endl;
	cout << a2out.str() << endl;
	cout << a3out.str() << endl;
	cout << a4out.str() << endl;
	cout << a5out.str() << endl;

	return 0;
}