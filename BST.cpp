// C++ program to demonstrate insertion
// in a BST recursively.
#include <iostream>
#include<cstdlib>
#include<ctime> //#include<chrono> 
#include<string>
#include<fstream>
#include<vector>
#include<chrono> 
#include<string>
using namespace std;

template<class T> 
class BST {
private:
    T data;
    BST<T> *left, *right;
public:
    // Default constructor.
    BST() : data(), left(NULL), right(NULL){}// Default Constructor definition.
	// Parameterized Constructor definition.
	BST(T value){
	    data = value;
	    left = right = NULL;
	}
    // Insert function.
    BST* Insert(BST<T>*, T);
   // BST* deleteNode(BST<T>* , int );
    BST* minValueNode(BST<T>*);
    // Inorder traversal.
    void Inorder(BST* ,vector<T>&a);
};
 
// Insert function definition.
template<class T> 
BST<T>* BST<T>::Insert(BST* root, T value)
{
    if (!root) {
        // Insert the first node, if root is NULL.
        return new BST(value);
    }
 
    // Insert data.
    if (value > root->data) {
        // Insert right node data, if the 'value'
        // to be inserted is greater than 'root' node data.
 
        // Process right nodes.
        root->right = Insert(root->right, value);
    }
    else if (value < root->data){
        // Insert left node data, if the 'value'
        // to be inserted is smaller than 'root' node data.
 
        // Process left nodes.
        root->left = Insert(root->left, value);
    }
    // Return 'root' node, after insertion.
    return root;
}


// Inorder traversal function.
// This gives data in sorted order.
template<class T> 
void BST<T>  ::Inorder(BST* root, vector<T>&vec)
{
    if (!root) {
        return;
    }
    Inorder(root->left,vec);
	vec.push_back(root->data);
  //  cout << root->data << '\t';
    Inorder(root->right,vec);
}
 // binary search tree + inorder traversal for sorting
// Driver code
int main()
{	
	ofstream file;
	file.open("BST.txt",ios::out); //開啟檔案
	srand(time(NULL)) ;
//	int data[5]={100000000,200000000,300000000,400000000,500000000};
 	clock_t start ,end,midstart,midend;
    double alltime,time;
    cout<<"start"<<endl;
     
    BST<double> d, *droot = NULL;
    vector<double>dr;
    BST<float> f, *froot = NULL;
    vector<float>fr;
    BST<int> i, *iroot = NULL;
    vector<int>ir;
    BST<string> s, *sroot = NULL;
    vector<string>sr;
    
    int num1;
    cin>>num1;
    int num=num1-1;
    
//  double
    double min=0.0,max=100000.0000000000;
    double ddd= (double)(max-min)*rand()/(RAND_MAX+1.0);
    start=clock();
    droot = d.Insert(droot, ddd);
    for(int j=0;j<num;j++){
		double ran=(double)(max-min)*rand()/(RAND_MAX+1.0);
		d.Insert(droot, ran);
	}
    d.Inorder(droot,dr);
	end=clock();
	alltime=double(end-start)/CLOCKS_PER_SEC;
	midstart=clock();
	for(int j=0;j<num;j++){
		double ran=(double)(max-min)*rand()/(RAND_MAX+1.0);
	}
	midend=clock();
	time=double(midend-midstart)/CLOCKS_PER_SEC; 
	file<<num1<<"筆double資料inorder traversal的時間為: "<<alltime-time<<endl; 
	cout<<endl;
		
//	float
	float fmin=0.0f, fmax=100000.0f;
	float fff=(float)(fmax-fmin)*rand()/(RAND_MAX+1.0);
	start=clock();
    froot = f.Insert(froot, fff);
    for(int j=0;j<num;j++){
		float ran=((float)(fmax-fmin)*rand()/(RAND_MAX+1.0));
		f.Insert(froot, ran);
	}
    f.Inorder(froot,fr);
	end=clock();
	alltime=double(end-start)/CLOCKS_PER_SEC;
	midstart=clock();
	for(int j=0;j<num;j++){
		float ran=((float)(fmax-fmin)*rand()/(RAND_MAX+1.0));
	}
	midend=clock();
	time=double(midend-midstart)/CLOCKS_PER_SEC; 
	file<<num1<<"筆 float資料inorder traversal的時間為: "<<alltime-time<<endl; 
	cout<<endl;
	
//	int
	int iii=rand();
	start=clock();
    iroot = i.Insert(iroot,iii);
    for(int j=0;j<num;j++){
		double ran=rand();
		i.Insert(iroot, ran);
	}
    i.Inorder(iroot,ir);
	end=clock();
	alltime=double(end-start)/CLOCKS_PER_SEC;
	midstart=clock();
	for(int j=0;j<num;j++){
		double ran=rand();
	}
	midend=clock();
	time=double(midend-midstart)/CLOCKS_PER_SEC; 
	file<<num1<<"筆   int資料inorder traversal的時間為: "<<alltime-time<<endl; 
	cout<<endl;

//string
	string str="aaaaaa";
	for(int k=0;k<6;k++){
		str[k]+=rand()%26;
	}
	start=clock();
	sroot = s.Insert(sroot, str);	
	for(int i=0;i<num;i++){	
		string str="aaaaaa";
		for(int k=0;k<6;k++){
			str[k]+=rand()%26;
		}
		s.Insert(sroot, str);
		
	}
    s.Inorder(sroot,sr);
	end=clock();
	alltime=double(end-start)/CLOCKS_PER_SEC;
	midstart=clock();
	for(int i=0;i<num;i++){	
		string str="aaaaaa";
		for(int k=0;k<6;k++){
			str[k]+=rand()%26;
		}
	}
	midend=clock();
	time=double(midend-midstart)/CLOCKS_PER_SEC; 
	file<<num1<<"筆string資料inorder traversal的時間為: "<<alltime-time<<endl; 
	cout<<endl;
	sr.clear();
    return 0;
}
