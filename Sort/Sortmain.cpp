#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime> //#include<chrono> 
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;
void C(vector<double>&,int );
void C(vector<float>&,int );
void C(vector<int>&,int );
void C(vector<string>&,int );
template<class T> 
void sp(T &a,T &b){ //swap
	T temp=a;
	a=b;
	b=temp;
}
template<class T> 
void printA(T&a ,int n){
	for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
template<class T>
int partition(T &A,const int p ,const int r){
	using elType = typename	T::value_type;
	elType x=A[r];
	int i=p-1;
	for(int j=p;j<=r-1;j++){
		if(A[j]<=x){
			i=i+1;
		//	elType *a=new elType[i];
			auto temp=A[i];
			A[i]=A[j];
			A[j]=temp;
			}
	}
	
	auto temp=A[i+1];
	A[i+1]=A[r];
	A[r]=temp;
	i++;
	return i;
}
template<class T>
void QuickSort(T &A,const int p ,const int r){
	if(p<r){
		int q=partition(A,p,r);
		QuickSort(A,p,q-1);
		QuickSort(A,q+1,r);
		 
	}
}


// Merge two subarrays L and M into arr
template<class T> 
void merge(vector<T> &a, int p, int q, int r) {
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;
  T * L=new T [n1]; 
  T * M=new T [n2];
  for (int i = 0; i < n1; i++)
    L[i] = a[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = a[q + 1 + j];
  // Maintain current index of sub-arrays and main array
  int i=0, j=0, k=p;
  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      a[k] = L[i];
      i++;
    } else {
      a[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    a[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    a[k] = M[j];
    j++;
    k++;
  }
  delete[]L;
  delete[]M;
}

// Divide the array into two subarrays, sort them and merge them
template<class T> 
void merge_sort(vector<T>  &a, int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    // Merge the sorted subarrays
    merge(a, l, m, r);
  }
}
template<class T>
void Adjust(T &a,int root,int n){
	auto e=a[root];
	int j;
	for(j=2*root;j<=n;j*=2){
		if(j<n&&a[j]<a[j+1])
			j++;
		if(e>=a[j])
			break;
		a[j/2]=a[j];
	}
	a[j/2]=e;
}

void HeapSort(vector<string>  &a,const int n){
	a.insert(a.begin(), "0"); 
	for(int i=n/2;i>=1;i--)
		Adjust(a,i,n);
	for(int i=n-1;i>=1;i--){//排序 
		swap(a[1],a[i+1]);
		Adjust(a,1,i);
	}
	a.erase(a.begin());  
}
template<class T>
void HeapSort(T &a,const int n){
	a.insert(a.begin(), 0); 
	for(int i=n/2;i>=1;i--)
		Adjust(a,i,n);
	for(int i=n-1;i>=1;i--){//排序 
		swap(a[1],a[i+1]);
		Adjust(a,1,i);
	}
	a.erase(a.begin());  
}

int main(void){
	ofstream file;
	file.open("times.txt",ios::out); //開啟檔案
	
	srand(time(NULL)) ;
	vector<int>ir;
    ir.reserve(300000000);
    vector<float>fr;
    fr.reserve(300000000);
    vector<double>dr;
    dr.reserve(300000000);
    vector<string>sr;
    sr.reserve(300000000);
    int data[5]={50000000,100000000,150000000,200000000,250000000};
    clock_t start,end;
    double time;
  
//merge_sort	
	for(int i=0;i<5;i++){ 
		cout<<data[i]<<endl;

		//double merge_sort
		C(dr,data[i]);
		start=clock(); //cout<<start<<endl;
		merge_sort(dr,0,(data[i]-1));
		end=clock();  //	cout<<end<<endl;
 		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<data[i]<<"筆double資料merge_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		dr.clear();
		
		//float merge_sort
		C(fr,data[i]);
		start=clock();	//cout<<start<<endl;
		merge_sort(fr,0,data[i]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<data[i]<<"筆float 資料merge_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		fr.clear();
		
		//int merge_sort
		C(ir,data[i]);
		start=clock();	//cout<<start<<endl;
		merge_sort(ir,0,data[i]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<data[i]<<"筆int   資料merge_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		ir.clear();

		//string merge_sort
		C(sr,data[i]);
		start=clock();	//cout<<start<<endl;
		merge_sort(sr,0,data[i]-1);
		end=clock();   //cout<<end<<endl;
		time=double(end-start)/CLOCKS_PER_SEC;	//cout<<"花費時間"<<time;
		file<<data[i]<<"筆string資料merge_sort的時間: "<<time<<endl;	//cout<<"花費時間"<<time<<endl;
		sr.clear();

	}	   
//QuickSort 
    for(int i=0;i<5;i++){ 
    	cout<<data[i]<<endl;
    	
    	//double QuickSort	
    	C(dr,data[i]);
    	start=clock();
  		QuickSort(dr,0,data[i]-1);
  		end=clock(); //	for(int j=0;j<10000000;j++){cout<<ir[j]<<"\t ";} 
		dr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆double資料QuickSort的時間為: "<<time<<endl; 
		
    	//float QuickSort
    	C(fr,data[i]);
    	start=clock();
  		QuickSort(fr,0,data[i]-1);
  		end=clock(); //	for(int j=0;j<10000000;j++){cout<<ir[j]<<"\t ";} 
		fr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆 float資料QuickSort的時間為: "<<time<<endl; 
		
    	//int QuickSort
    	C(ir,data[i]);
    	start=clock();
  		QuickSort(ir,0,data[i]-1);
  		end=clock(); //	for(int j=0;j<10000000;j++){cout<<ir[j]<<"\t ";} 
		ir.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆   int資料QuickSort的時間為: "<<time<<endl; 
	
		//string QuickSort
		C(sr,data[i]);
    	start=clock();
  		QuickSort(sr,0,data[i]-1);
  		end=clock();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆string資料QuickSort的時間為: "<<time<<endl; 
		sr.clear(); 
	}	
	
//STL::algorithm:: sort()
	for(int i=5;i<5;i++){
		cout<<data[i]<<endl;
	
		//double algorithm:: sort()
		C(dr,data[i]);
		//for(int j=0;j<100;j++){cout<<dr[j]<<"   ";} cout<<endl;
		start=clock();
		sort(dr.begin(),dr.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
		dr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆double資料algorithm::sort()的時間為: "<<time<<endl; 
		
		//float algorithm:: sort()
		C(fr,data[i]);
		//for(int j=0;j<100;j++){cout<<dr[j]<<"   ";} cout<<endl;
		start=clock();
		sort(fr.begin(),fr.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
		fr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆 float資料algorithm::sort()的時間為: "<<time<<endl; 
		
		//int algorithm:: sort()
		C(ir,data[i]);
		//for(int j=0;j<100;j++){cout<<dr[j]<<"   ";} cout<<endl;
		start=clock();
		sort(ir.begin(),ir.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
		ir.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆   int資料algorithm::sort()的時間為: "<<time<<endl; 
		
		//string algorithm:: sort()
		C(sr,data[i]);
		//for(int j=0;j<100;j++){cout<<dr[j]<<"   ";} cout<<endl;
		start=clock();
		sort(sr.begin(),sr.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆string資料algorithm::sort()的時間為: "<<time<<endl; 	
		sr.clear();
	}

//STL::algorithm:: stable_sort()

	for(int i=0;i<5;i++){
		cout<<data[i]<<endl;
		
		//double algorithm::stable_sort()
		C(dr,data[i]);
		start=clock();
		stable_sort(dr.begin(),dr.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
		dr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆double資料algorithm::stable_sort()的時間為: "<<time<<endl; 
		
		//float algorithm::stable_sort()
		C(fr,data[i]);
		start=clock();
		stable_sort(fr.begin(),fr.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
		fr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆 float資料algorithm::stable_sort()的時間為: "<<time<<endl; 
		
		//int algorithm::stable_sort()
		C(ir,data[i]);
		start=clock();
		stable_sort(ir.begin(),ir.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
		ir.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆   int資料algorithm::stable_sort()的時間為: "<<time<<endl; 
		
		//string algorithm::stable_sort()
		C(sr,data[i]);
		start=clock();
		stable_sort(sr.begin(),sr.begin()+data[i]);   //	for(int j=0;j<100;j++){cout<<dr[j]<<"  ";} 
		end=clock();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆string資料algorithm::stable_sort()的時間為: "<<time<<endl; 
		//sr.clear();	
	}
	
// HeapSort
  	for(int i=0;i<5;i++){//隨機產生1億，2億，3億，4億，5億筆資料 
		cout<<data[i]<<endl;
  	  
	    //double HeapSort
		C(dr,data[i]);   //	printA(dr,data[i]);
		start=clock();
		HeapSort(dr,data[i]);//printA(dr,data[i]);
		end=clock(); 
		dr.clear();	
	    time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆double資料HeapSort的時間為: "<<time<<endl; 
		
   		 //float HeapSort
    	C(fr,data[i]);//	printA(fr,data[i]);
    	start=clock();
  		HeapSort(fr,data[i]);
  		end=clock(); //printA(fr,data[i]);
		fr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆 float資料HeapSort的時間為: "<<time<<endl; 
		
    	//int HeapSort
    	C(ir,data[i]);//	printA(ir,data[i]);
    	start=clock();
  		HeapSort(ir,data[i]);
  		end=clock(); //printA(ir,data[i]);
		ir.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆   int資料HeapSort的時間為: "<<time<<endl; 

		//string HeapSort
		C(sr,data[i]);//	printA(sr,data[i]);
    	start=clock();
  		HeapSort(sr,data[i]);	
		end=clock(); //printA(sr,data[i]);
		sr.clear();
    	time=double(end-start)/CLOCKS_PER_SEC; 
		file<<data[i]<<"筆string資料HeapSort的時間為: "<<time<<endl; 
			
	}
	file<<"全部已跑完"<<endl;	
	system("pause");
	return 0; 
}
