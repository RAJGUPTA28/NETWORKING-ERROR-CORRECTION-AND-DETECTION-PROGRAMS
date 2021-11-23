#include <iostream>
#include <string.h>
#define MAX 100


using namespace std;

int main() {
		int i,j,seg,flag=0;
        char VRC;
		char arr[MAX];
        char sended[MAX+1];
		 cout<<" ----------VRC ----------\n";
		cout<<"Enter the bit value:";
		cin>>arr;
			
        int countones=0;
        for (int i = 0; i < strlen(arr); i++)
        {
        if(arr[i]=='1') { countones++;}
        }

        if((countones)%2==0)
        {
            VRC = '0';
        }
        else{
            VRC ='1';
        }


        for (int i = 0; i < strlen(arr); i++)
        {
            cout<<" "<<arr[i];
        }
        
        cout<<"  |  "<<VRC;

        cout<<endl;


//adding last elementA as vrc
         sended[strlen(arr)]=VRC;

        for (int i = 0; i < strlen(arr); i++)
        {
           sended[i]= arr[i];
           
        }
     
        cout<<"\nDATA TO BE SENDED IS : "<<endl;
          for (int i = 0; i < strlen(sended); i++)
        {
            cout<<" "<<sended[i];
        }	
		
	}
