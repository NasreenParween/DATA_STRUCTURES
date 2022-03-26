#include<iostream>
using namespace std;

class heap{
	private:
		int *arr;
		int size;
		int occupied;
	public:
		heap(int size1){
			size=size1;
			arr=new int[size];
			occupied=0;
		}
		int parent(int i){
			return (i-1)/2;
		}
		int left(int i){
			return (i*2)+1;
		}
		int right(int i){
			return (2*i)*2;
		}
		void heapify(int i){
			while(i!=0 && arr[parent(i)]>arr[i]){
				int temp=arr[parent(i)];
				arr[parent(i)]=arr[i];
				arr[i]=temp;
				i=parent(i);
			}
		}
		void insert(int m){
			if(occupied==size){
				cout<<"FULL"<<endl;
				return;
			}
			if(occupied==0){
				arr[0]=m;
				occupied++;
			}
			else{
				arr[occupied]=m;
				heapify(occupied);
				occupied++;
			}
		}
		void deleteto(int m){
			if(m==size-1){
				occupied--;
			}
			else{
				arr[m]=arr[occupied-1];
				occupied--;
				heapify(occupied-1);
			}
		}
		void display(){
			cout<<"HEAP AFTER OPERATIONS :=     ";
			for(int i=0;i<occupied;i++){
				cout<<arr[i]<<"  ";
			}
			cout<<endl;
		}
};

int main(){
	heap h1(5);
	h1.insert(7);
	h1.insert(4);
	h1.insert(3);
	h1.insert(6);
	h1.insert(10);
	h1.insert(5);
	h1.deleteto(1);
	h1.display();

}
