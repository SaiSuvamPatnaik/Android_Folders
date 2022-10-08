
#include <iostream>
#include <vector>

using namespace std;

int FindHighestElement(int A[], int N)
{
    int H = A[0];
    
    for(int i=1;i<N;i++)
    {
        if(H<A[i])
        {
            H=A[i];
        }
        
        
    }
    
    return H;
}

int SecondHighestElement(int A[],int N)
{
    int H=A[0];
    int SH= -99999;
    
    for(int i=1;i<N;i++)
    {
        if (H == A[i])
        {
            continue;
        }
        if(H<A[i])
        {
            SH = H;
            H=A[i];
        }
        else if(SH<A[i])
        {
            SH=A[i];
        }
    }
        return SH;

}

int ThirdHighestElement(int A[], int N)
{
    int H = A[0];
    int SH = -99999;
    int th = A[0];
    
    for (int i=1;i<N;i++)
    {
        if (H == A[i])
        {
            continue;
        }
        if (H<A[i])
        {
            th = SH;
            SH = H;
            H=A[i];
        }
        else if (SH<A[i])
        {
            th=SH;
            SH=A[i];
        }
        else if(th<A[i])
        {
            th=A[i];
        }
        
    }
    return th;
} 

int FindZthHighestElement(int A[], int N, int zTh)
{
    std::vector<int> pq;
    
    for(int i = 0; i < zTh; i++)
        pq.insert(pq.begin()+i, -99999);
    
    for (int i=0;i<N;i++)
    {
        for (int y = 0; y < zTh; y++) {
            if (pq[y] < A[i]) {
                pq.insert(pq.begin() + y, A[i]);
                break;
            }
        }
    }
    
    return pq[zTh-1];
}


int main()
{
    
    int N;
    cout<<"Size of array";
    cin>>N;
    int A[N];
    cout<<"Enter elements in array";
    for(int i=0;i<N;i++)
    {
        cin>>A[i];
    }
    int ans1 = FindHighestElement(A,N);
    int ans2 = SecondHighestElement(A,N);
    int ans3 = ThirdHighestElement(A,N);
    cout<<"Highest Element is "<<ans1<<endl;
    cout<<"Second Highest Element is "<<ans2<<endl;
    cout<<"Third Highest Element is "<<ans3<<endl;
    
    cout << "1:" <<FindZthHighestElement(A, N, 1) << endl;
    cout << "2:" <<FindZthHighestElement(A, N, 2) << endl;
    cout << "3:" <<FindZthHighestElement(A, N, 3) << endl;
    cout << "4:" <<FindZthHighestElement(A, N, 4) << endl;

    return 0;

}