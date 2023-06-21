#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    delete newNode;
}

int converte(string input)
{
    
    int num = 0;
    int n = input.length();
 
    for (int i = 0; i < n; i++)
 
        num = num * 10 + (int(input[i]) - 48);
 
    
    return num;
}

void pop() {
    
    Node* temp = top;
    top = top->next;
    int poppedValue = temp->data;
    delete temp;
   
}

int main() {
    string input;
    int pilhas;
    int cont = 0;
    int printer = 0;
    cin >> pilhas;

    while (printer < pilhas){
        
        while (input[0] != 'E')
        {
            cin >> input;
            if(input[0] != 'E' && input[0] != ' '){
        
                if((cont == 0) || top->data != converte(input)){
                    push(converte(input));
                    cont++;
                }
                else{
                    pop();                    
                    cont--;
                    }    
            }
        }
        if(top != NULL)
        cout << "caso " << printer << ':' << " " << cont << " " << top->data << '\n';
        else
        cout << "caso " << printer << ':' << " " << cont << " " << -1 << '\n';
        printer++;
        while (cont != 0)
        {
            pop();
            cont--;
        }
        
        input = 'a';
    }   
    
    delete(top);

    return 0;
}