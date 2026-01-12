#include <iostream>



// Abstract base class for sorting algorithms choosing by consturctor the sorting algorithm
class Sorter {
public:
    virtual void sort(int arr[], int size) = 0; // Pure virtual function
    virtual void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }

protected:
    void merge(int arr[], int left, int mid, int right);
    void mergeSort(int arr[], int left, int right);

    void quickSort(int arr[], int low, int high);
};

class QuickSorter : public Sorter {
public:
    void sort(int arr[], int size) override {
        quickSort(arr, 0, size - 1);
    }
};

class MergeSorter : public Sorter {
public:
    void sort(int arr[], int size) override {
        mergeSort(arr, 0, size - 1);
    }
};


void Sorter::merge(int arr[], int left, int mid, int right){
    const int n1 = mid - left + 1;
    const int n2 = right - mid;

    // Create temp vectors
    int L[n1];
    int R[n2];

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;


    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Sorter::mergeSort(int arr[], int left, int right){

    if (left >= right) // No more dividing
        return;

    int mid = left + (right-left)/2;

    mergeSort(arr, mid+1, right);
    mergeSort(arr, left, mid);

    merge(arr, left, mid, right);
}



int main (){
    int input [] = {4, 3, 421, 5, 2, 11 , 1, 6, 43};
    const int N = 9;
    MergeSorter sort1;
    sort1.sort(input, N);
    sort1.printArray(input, N);
    return 0; 

}