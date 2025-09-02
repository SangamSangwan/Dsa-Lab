#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

void printSparse(Term a[], int terms) {
    cout<<"Row Col Val\n";
    for(int i=0;i<terms;i++)
        cout<<a[i].row<<"   "<<a[i].col<<"   "<<a[i].val<<"\n";
}

void transpose(Term a[], Term b[], int terms, int rows, int cols) {
    int k=0;
    for(int c=0;c<cols;c++) {
        for(int i=0;i<terms;i++) {
            if(a[i].col==c) {
                b[k].row=a[i].col;
                b[k].col=a[i].row;
                b[k].val=a[i].val;
                k++;
            }
        }
    }
}

int add(Term a[], int t1, Term b[], int t2, Term c[]) {
    int i=0,j=0,k=0;
    while(i<t1 && j<t2) {
        if(a[i].row<b[j].row || (a[i].row==b[j].row && a[i].col<b[j].col)) 
            c[k++]=a[i++];
        else if(b[j].row<a[i].row || (b[j].row==a[i].row && b[j].col<a[i].col)) 
            c[k++]=b[j++];
        else {
            c[k]=a[i];
            c[k].val=a[i].val+b[j].val;
            k++; i++; j++;
        }
    }
    while(i<t1) c[k++]=a[i++];
    while(j<t2) c[k++]=b[j++];
    return k;
}

int multiply(Term a[], int t1, Term b[], int t2, Term c[], int rowsA, int colsA, int colsB) {
    int k=0;
    for(int i=0;i<rowsA;i++) {
        for(int j=0;j<colsB;j++) {
            int sum=0;
            for(int p=0;p<t1;p++) {
                if(a[p].row==i) {
                    for(int q=0;q<t2;q++) {
                        if(b[q].row==a[p].col && b[q].col==j) 
                            sum+=a[p].val*b[q].val;
                    }
                }
            }
            if(sum!=0) {
                c[k].row=i; c[k].col=j; c[k].val=sum; k++;
            }
        }
    }
    return k;
}

int main() {
    Term A[5]={{0,0,1},{0,3,2},{1,1,3},{2,0,4},{3,2,5}};
    int t1=5;
    int rowsA=4, colsA=4;

    cout<<"Matrix A (triplet):\n";
    printSparse(A,t1);

    Term B[4]={{0,1,7},{1,1,6},{2,3,8},{3,0,9}};
    int t2=4;
    int rowsB=4, colsB=4;

    cout<<"\nMatrix B (triplet):\n";
    printSparse(B,t2);

    Term T[10];
    transpose(A,T,t1,rowsA,colsA);
    cout<<"\nTranspose of A:\n";
    printSparse(T,t1);

    Term C[20];
    int t3=add(A,t1,B,t2,C);
    cout<<"\nA + B:\n";
    printSparse(C,t3);

    Term M[20];
    int t4=multiply(A,t1,B,t2,M,rowsA,colsA,colsB);
    cout<<"\nA * B:\n";
    printSparse(M,t4);

    return 0;
}
