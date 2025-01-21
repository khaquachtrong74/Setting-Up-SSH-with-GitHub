#include<iostream>
using namespace std;
struct node{
	node* left;
	node* right;
	int data;
	node(int d = 0,node* l = nullptr, node* r = nullptr){
		left = l;
		right = r;
		data = d;
	}
};
struct binaryTree{
	node *root;
	binaryTree(){
		root = nullptr;
	}
	//Tạo Node
	void createNode(node* new_node){
		if(root == nullptr){
			root = new_node;
			return;
			
		}
		else{
			node* tmp = root;
			node* parent = nullptr;//Node Cha
			while(tmp != nullptr){
				parent = tmp;
				//left < root
				//right > root
				if(new_node->data < tmp->data){
					tmp = tmp->left;
				}
				else if(new_node->data > tmp->data){ 
					tmp = tmp->right;
				}
				else{
					return;
				}
			}
			if(new_node->data < parent->data){
				parent->left = new_node;
			}
			else{
				parent->right = new_node;
			}
		}
	}
	// tìm node
	void findNode(node* x){
		if(root == nullptr){
			return;
		}
		else{
			node *tmp = root;
			node *parent = nullptr;
			while(tmp != nullptr){
				parent = tmp;
				if(tmp->data < x->data){
					tmp = tmp->right;
				}
				else if(tmp->data > x->data){
					tmp = tmp->left;
				}
				else{
					cout<<"Da tim thay!"<<endl;
					return;
				}

			}

			cout<<"Khong tim thay! "<<x->data<<endl;
			//Nếu chưa tìm thấy thì sẽ thêm vào root;
			if(parent->data < x->data){
				parent->right = x;
			}
			else
				parent->left = x;
		}
	}
	
	void NLR(node* current){
		if(current != nullptr){
		cout<<current->data<<" ";//Visit
			//5
		NLR(current->left);//chir chayj moi cai nay
			//left:4
			//	left
			//		3
			//		right:nullptr
			//	right: 7
			//het left
		NLR(current->right);
			//right: 6;
		}
	}
	void LNR(node* current){
		if(current != nullptr){
			LNR(current->left);
			cout<<current->data<<" ";
			LNR(current->right);
		}
	}
	void RLN(node *current){
		if(current != nullptr){
			RLN(current->right);
			RLN(current->left);
			cout<<current->data<<" ";
		}
	}
	//Xoá 
	void deleteNode(node *del){
		//3 Trường hợp
		//Xoá nút lá
		//Xoá nút cha có 1 nút con
		//Xoá nút cha có 2 nút con
		//nhỏ nhất bên phải, lớn nhất bên trái
		//	Cách 1:  và thế	 vào node cần xoá, sau đó nó sẽ rơi vào trường
		//	hợp xoá nút cha có 1 nút con
		//	Cách 2: chọn node lá phù hợp và đưa về trường hợp
		//	xoá nút lá, 	
	}
	node* Delete(node*root,int data){
		if(root == nullptr){
			return nullptr;
		}
		else if(data > root->data){
			root->right = Delete(root->right, data);
		}
		else if(data < root->data){
			root->left = Delete(root->left, data);
		}
		else{
			//case 1: no child
			if(root->left == nullptr && root->right == nullptr){
				delete root;
				return nullptr;
			}
			//case 2: one child
			if(root->left == nullptr){
				node *tmp = root;
				root = root->right;
				delete tmp;
			}
			else if(root->right == nullptr){
				node *tmp = root;
				root = root->left;
				delete tmp;
			}
			//case 3: two child
			else{
				node*tmp = root->right;
				while(tmp->left != nullptr){
					tmp = tmp->left;
				}
				root->data = tmp->data;
				root->right = Delete(root->right, tmp->data);//go to case 2: one child
			}
		}
		return root;
	}
	node* deleNode(node*r ,int data){
		if(r == nullptr){
			return r;
		}
		else if(r->data < data){
			r->right = deleNode(r->right, data);
		}
		else if(r->data > data){
			r->left = deleNode(r->left, data);
		}
		else{
			if(r->left == nullptr && r->right == nullptr){
				delete r;
				return nullptr;
			}
			if(r->left == nullptr){
				node*tmp = r;
				r = r->right;
				delete tmp;
			}
			else if(r->right == nullptr){
				node*tmp = r;
				r = r->left;
				delete tmp;
			}
			else{
				node*tmp = r->right;
				while(tmp->left != nullptr){
					tmp = tmp->left;
				}
				r->data = tmp->data;
				r->right = deleNode(r->right, tmp->data);
			}
		}
		return r;
	}
};
struct stack{
	node* s;
	int capacity;
	int top;
	stack(int cap = 100){
		s = new node[cap];
		capacity = cap;
       		top = -1;
	}
	bool isFull(){
		return top == capacity-1;
	}
	bool isEmty(){
		return top == -1;
	}
	void push(node data){
		if(isFull()){
			return;
		}
		else{
			s[++top] = data;
		}
	}	
};
void swarp(int &a, int &b){
	int tmp = a;
	a = b;
	b = tmp;
}
void selectionSort(int arr[], int size){
	int viTri;
	for(int i = 0; i < size-1;i++){
		viTri = i;
		for(int j = i+1; j < size; j++){
			if(arr[viTri] < arr[j]){
				viTri = j;
			}
		}
		if(viTri != i){
			swarp(arr[viTri],arr[i]);
		}
	}
}
void interChangeSort(int arr[], int size){
	for(int i = 0; i < size-1; i++){
		for(int j = i+1; j <size; j++){
			if(arr[i] < arr[j]){
				swarp(arr[i],arr[j]);
			}
		}
	}
}
void bubbleSort(int arr[], int size){
	for(int i = 0; i < size-1; i++){
		for(int j = 0; j < size -1 -i;j++){
			if(arr[j] < arr[j+1]){
				swarp(arr[j], arr[j+1]);
			}
		}
	}
}
void insertSort(int arr[], int size){
	
	for(int i = 1; i < size; i++){
		int key = arr[i];
		int j = i-1;
		while(j >= 0 && arr[j] > key){
			arr[j+1] = arr[j];
			j-=1;
		}
		arr[j+1] = key;

	}
}
void xuat(int arr[], int size){
	for(int i = 0; i < size; i++){
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
int main(){
	binaryTree r;
	r.createNode(new node(5));
	r.createNode(new node(7));
	r.createNode(new node(6));
	r.createNode(new node(3));
	r.createNode(new node(4));
	r.Delete(r.root, 5);
	//r.deleNode(r.root, 4);
	r.NLR(r.root);
	cout<<"mang"<<endl;
	int arr[] = {5,6,1,2,4,8,3};
	xuat(arr, 7);
	cout<<"selectionSort"<<endl;
	selectionSort(arr, 7);
	xuat(arr, 7);
	cout<<"interChangeSort"<<endl;
	interChangeSort(arr, 7);
	xuat(arr, 7);
	cout<<"bubbleSort"<<endl;
	bubbleSort(arr, 7);
	xuat(arr, 7);
	cout<<"insertSort"<<endl;
	insertSort(arr, 7);
	xuat(arr, 7);
//	r.NLR(r.root);
	//cout<<"FOR"<<endl;
	//r.NLR_For();
//	cout<<endl;
//	r.LNR(r.root);
//	cout<<endl;
//	r.RLN(r.root);
//	stack test(20);
//	test.push(r.root);
//	cout<<endl;
//	r.RLN(test.s[test.top]);
	return 0;
}
