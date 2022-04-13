#include<iostream>
using namespace std;
void swapping(int &a, int &b) {      //swap the content of a and b
   int temp;
   temp = a;
   a = b;
   b = temp;
}
void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void bubbleSort(int *array, int size) {
    cout<<"\nSorting the Array using Bubble Sort Technique..\n";
   for(int i = 0; i<size; i++) {
      int swaps = 0;         //flag to detect any swap is there or not
      for(int j = 0; j<size-i-1; j++) {
         if(array[j] > array[j+1]) {       //when the current item is bigger than next
            swapping(array[j], array[j+1]);
            swaps = 1;    //set swap flag
         }
      }
      if(!swaps)
         break;       // No swap in this pass, so array is sorted
   }
}
int main() {
   int n;
   cout << "How many element you want to Enter?? : ";
   cin >> n;
   int arr[n];     //create an array with given number of elements
   cout << "Enter the elements:" << endl;
   for(int i = 0; i<n; i++) {
      cin >> arr[i];
   }
   cout << "Element of Array before Sorting: ";
   display(arr, n);
   bubbleSort(arr, n);
   cout<<"\nArray Sorted Successfully!\n";
   cout << "\nElement of Array after Sorting are: ";
   display(arr, n);
}
