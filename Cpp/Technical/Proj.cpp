#include<iostream>
#include<unistd.h>
using namespace std;

struct TE{
    int hour, min, sec;
    void runTime();
};

void TE::runTime(){
	//function count seconds
	
	
		sec++;
		if(this->sec > 59){
			min++;
			sec=0;
		}
		if(min>59){
			hour++;
			min = 0;	
			sec = 0;
		}
		
}
void* del(int **arr, int size){
    for(int i = 0; i < size; i++){
        delete[] arr[i];
    }
    delete [] arr;
    return nullptr;
}
void declared(int **arr, int size){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < 10; j++){
            arr[i][j] = 0;
       }
    }
}
void view(int **arr, int size){
    for(int i = 0; i < size;i++){
        for(int j = 0; j < 10; j++){
            cout<<arr[i][j]<<"  ";
        }
        cout<<endl;
    }
}
//matrix alone
void mtxA(int **arr, int size){
    for(int i = 0; i < size; i++){
        arr[i][i] = 1;
    }
}
void mtxB(int **arr, int size){
    for(int i = 0; i < size; i++){
        arr[i][9-i] = 1;
    }
}
bool TF(int **arr, int size){
    static int index = 0;
    if(index == 9){
        return true;
    }
    if(arr[index][size-index] == 0){
        index++;
        return TF(arr, size);
    }
    else{
        index++;
        return !TF(arr, size);
    }
}
// even-odd
void sortMtx(int **arr, int size){
    TE tichTac;
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(arr[i][j] != 1){
                arr[i][j] = 1;
                
            }
            else{
                arr[i][j] = 0;
                
            }
            view(arr, size);
            tichTac.runTime();
            
            system("clear");
        }
    }
    cout<<tichTac.hour<<" | "<<tichTac.min<<" | "<<tichTac.sec<<endl;
}

int main(){
    int **arrInt = new int*[10];
    for(int i = 0; i < 10; i++){
        arrInt[i] = new int[10];
    }
    declared(arrInt, 10);
    mtxA(arrInt, 10);
    mtxB(arrInt, 10);
    view(arrInt, 10);
    // cout<<TF(arrInt, 10);
    sortMtx(arrInt, 10);
    void* a = del(arrInt, 10);

    if(a == nullptr){
        cout<<"Giai phong thanh cong!"<<endl;
    }
    else{
        cout<<"Giai phong khong thanh cong";
    }

    return 0;
}