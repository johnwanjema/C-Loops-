/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

void getIntegers(int listInts[],int listSize ){
    for (int i = 0; i < listSize; i++) {
        cout << "Input value for array at position : " << i + 1 << endl;
        cin >> listInts[i];
    } 
}


void findMostReccuring(int listInts[],int listSize , int &count, int &position){
   int max_count = 0;

    for (int i=0;i<listSize;i++)
    {
       int count=1;
       for (int j=i+1;j<listSize;j++)
           if (listInts[i]==listInts[j])
               count++;
       if (count>max_count)
          max_count = count;
    }
    
    
    
    for (int i=0;i<listSize;i++)
    {
      int count=1;
      for (int j=i+1;j<listSize;j++)
          if (listInts[i]==listInts[j])
              count++;
      if (count==max_count)
            position = i;
    }
    
    count = max_count;
    
}

void outputElements(int listInts[],int listSize ){
    cout << "Array elements:" << endl;
     for(int i= 0; i < listSize; ++i){
        cout << "Array [0] = "<< listInts[i] << endl;
    }
}


int main()
{
    int listInts[10];
    int count = 0 , position;
    
    
    getIntegers(listInts, 10);
    
    findMostReccuring(listInts, 10 , count, position);
   
  
    cout << "Most occurred number: " << listInts[position] << endl;
    cout << "Number of occurrences: " << count << endl;
  
    outputElements(listInts , 10);

    return 0;
}

