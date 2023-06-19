#include <iostream>

using namespace std; 

struct Node
{
    int val;
    int index;
    Node *nextup;
    Node *nextside;
};

Node *top = NULL;

void push(int val,int index){

}

void pop(int index){

}

int converte(string indexa)
{
    
    int num = 0;
    int n = indexa.length();
 
    for (int i = 0; i < n; i++)
 
        num = num * 10 + (int(indexa[i]) - 48);
 
    
    return num;
}


int main(){

    int pilhas;
    string indexa;
    int val;
    int printer = 0;
    
    cin >> pilhas;

        while (indexa[0] != 'E')
        {
            cin >> indexa;
            if(indexa[0] != 'E' && indexa[0] != ' '){
                cin >> val; 
              //  if( top->val != (*val)){
                    push(val, converte(indexa));
               // }
                //else{
                    pop(converte(indexa));                   
                //}    
            }
        }


    return 0;
}