#include<iostream>
using namespace std;
// school
#define M 101
int a[M][M] = { { 0, 2, 0, 6, 0 },
                { 2, 0, 3, 8, 5 },
                { 0, 3, 0, 0, 7 },
                { 6, 8, 0, 0, 9 },
                { 0, 5, 7, 9, 0 } };
int n;
// Define set E
int E1[M];
int E2[M];
int wE[M];
int nE = 0;

// Define set T
int T1[M];
int T2[M];
int wT[M];
int nT = 0;

/*
6
0 8 1 4 1 3
8 0 0 3 5 0
1 0 0 2 0 6
4 3 2 0 1 0
1 5 0 1 0 0
3 0 6 0 0 0
*/

void input(int n){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> a[i][j];
        }
    }
}

int TonTai(int d,int D[],int nD){
    // đỉnh đang xét (index của đỉnh đó) 
    // D tập các đỉnh đã xét 
    // nD độ dài hiện tại của tập đã xét
    for(int i = 0;i<nD;i++){
        if(D[i] == d){ // nếu có tồn tại trong trong tập (tồn tại chu trình)
            return 1; // trả về true
        }
    }
    return 0; // không thì trả về false
}

void XoaViTriE(int i){
    for(int j = i;j < nE;j++){ // dời các điểm phía sau cạnh đang xét lên phía trước
        E1[j] = E1[j+1];
        E2[j] = E2[j+1];
        wE[j] = wE[j+1];
    }
    nE--;
}

void XoaCanhE(int u,int v){
    for(int i = 0;i<nE;i++){
        if(E1[i] == u && E2[i] == v){ // tìm đỉnh của cạnh đang xét và xóa khỏi mảng E
            XoaViTriE(i);
            break;
        }
    }
}

void prim(int s){
    int u = s,min,i,d1,d2;
    while(nT < n-1){ // số cạnh của cây bao trùm tối tiểu phải = số đỉnh - 1
        for(int v = 0;v < n;v++){ // đưa các cạnh kề và độ dài của cạnh đang xét vào tập E
            if(a[u][v] != 0){
                if(TonTai(v,T2,nT) == 0){ // kiểm tra xem có tồn tại chu trình hay không
                    E1[nE] = u;E2[nE] = v;
                    wE[nE] = a[u][v];nE++;
                }
            }
        }
        for(i = 0;i<nE;i++){ // set up cho d1 , d2 , min
            if(TonTai(E2[i],T2,nT) == 0){
                min = wE[i];d1 = E1[i];
                d2 = E2[i];break;
            }
        }
        for(;i<nE;i++){ // tìm cạnh nhỏ nhất trong tập E1 đang xét
            if(TonTai(E2[i],T2,nT) == 0){
                if(min > wE[i]){
                    // tìm cạnh có độ dài nhỏ nhất và lưu hai đỉnh của cạnh đó
                    min = wE[i];d1 = E1[i];
                    d2 = E2[i];
                }
            }
        }
        T1[nT] = d1;T2[nT] = d2; // đưa 2 đỉnh và độ dài có cạnh nhỏ nhất vào trong tập đáp án
        wT[nT] = a[d1][d2];
        a[d1][d2] = 0;a[d2][d1] = 0; // đưa độ dài các đỉnh đã xét về 0
        nT++;
        XoaCanhE(d1,d2); // xóa các giá trị trong mảng E
        u = d2; // tiếp tục xét từ đình cho cạnh nhỏ nhất
    }
}

void output(){
    int Tong = 0;
    for(int i = 0;i<nT;i++){
        cout << endl << "( " << T1[i] << " , " << T2[i] << " ) = " << wT[i];
        Tong+=wT[i];
    }
    cout << "\n Tong = " << Tong << endl;
}

int main(){
    cin >> n;
    input(n);
    prim(0);
    output();
    return 0;
}
