#include <iostream>
using namespace std;

void diagonal(int n) {
    int arr[]={5,8,9,12};
    int A[n];
    for(int i=0;i<n;i++) A[i]=0;
    A[0]=5; A[1]=8; A[2]=9; A[3]=12;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(i==j) cout<<A[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

void tridiagonal(int n) {
    int A[3*n-2];
    for(int i=0;i<3*n-2;i++) A[i]=0;
    A[n-1+1]=10;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i-j==1) cout<<A[i-2]<<" ";
            else if(i-j==0) cout<<A[n-1+i-1]<<" ";
            else if(i-j==-1) cout<<A[2*n-1+i-1]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

void lowertriangular(int n) {
    int size=n*(n+1)/2;
    int A[size];
    for(int i=0;i<size;i++) A[i]=0;
    A[3*2/2+0]=7;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i>=j) cout<<A[i*(i-1)/2+(j-1)]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

void uppertriangular(int n) {
    int size=n*(n+1)/2;
    int A[size];
    for(int i=0;i<size;i++) A[i]=0;
    A[3*2/2+0]=15;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i<=j) cout<<A[j*(j-1)/2+(i-1)]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

void symmetric(int n) {
    int size=n*(n+1)/2;
    int A[size];
    for(int i=0;i<size;i++) A[i]=0;
    A[3*2/2+0]=20;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i>=j) cout<<A[i*(i-1)/2+(j-1)]<<" ";
            else cout<<A[j*(j-1)/2+(i-1)]<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int n=4;
    cout<<"Diagonal Matrix\n";
    diagonal(n);
    cout<<"\nTri-diagonal Matrix\n";
    tridiagonal(n);
    cout<<"\nLower Triangular Matrix\n";
    lowertriangular(n);
    cout<<"\nUpper Triangular Matrix\n";
    uppertriangular(n);
    cout<<"\nSymmetric Matrix\n";
    symmetric(n);
}
