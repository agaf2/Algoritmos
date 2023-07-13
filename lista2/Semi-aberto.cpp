#include <iostream>

using namespace std;



struct Floor
{
    int key;
    int ocupado;
};

Floor** head = NULL;

int hashing(int key, int m, int l, Floor** head, int cont){
    int floor =  ((key % m) + cont) % m;
    int find = 0;
    int ok = 0;
    for(int i = 0; i < l && find == 0 ; i++){
        if(head[floor][i].ocupado == 0){
            find = 1;
        }
    }
    if(find == 1){
        return floor;
    }
    else{
        return -1;
    }
}

int add(int key, int m, int l, Floor** head, int cont, int repeat, int realocing) {
    int ok = 0;
    int floor;
    if (floor =hashing(key, m, l, head, cont) == -1) {
        cont++;
        repeat++;
        if (repeat != m)
            return add(key, m, l, head, cont, repeat, realocing);
        else {
            return 0;
        }
    } else(hashing(key, m, l, head, cont) != -1){
        for(int i = 0; i < l && ok != 1; i++){
            if(head[floor][i].key > key){
                for(int j = l-1; j > i; j--){
                    head[floor][j].key = head[floor][j-1].key;
                    head[floor][j].ocupado = head[floor][j-1].ocupado;
                }
                head[floor][i].key = key;
                head[floor][i].ocupado = 1;
                ok = 1;
                if(realocing != 1)
                    cout << floor << "." << i << endl;
            }
        }
        return 1;
    }
    
}


void rem(int key, Floor** head, int m, int l, int cont, int repeat){
    int find = 0;
    if (int floor = hashing(key, m, l, head, cont) == -1) {
        cont++;
        repeat++;
        if (repeat != m)
            return rem(key, head, m, l, cont, repeat);
        else {
            cout << "?.?" << endl;
        }
    }
    else{
        for(int i = 0; i < l && find == 0; i++){
            if(head[floor][i].key == key){
                head[floor][i].ocupado = -1;
                find = 1;
                cout << floor << "." << i << endl;
            } 
        }
    }
    
}

void qyr(int key, Floor** head, int m, int l, int cont, int repeat){
 int find = 0;
    if (int floor = hashing(key, m, l, head, cont) == -1) {
        cont++;
        repeat++;
        if (repeat != m)
            return rem(key, head, m, l, cont, repeat);
        else {
            cout << "?.?" << endl;
        }
    }
    else{
        for(int i = 0; i < l && find == 0; i++){
            if(head[floor][i].key == key){
                head[floor][i].ocupado = -1;
                find = 1;
                cout << floor << "." << i << endl;
            } 
        }
    }
}

int main(){

int m, l, key;
string input;

cin >> m >> l;

    Floor** newBuilding = new Floor*[m];
    for (int i = 0; i < m; i++){
        newBuilding[i] = new Floor[l];
        for(int j = 0; j < l; j++){
            newBuilding[i][j].ocupado = 0;
            newBuilding[i][j].key = 100000;
        }
    }

    head = newBuilding;
    
    while(input != "END"){
        cin >> input;
        if(input != "END"){
        
            cin >> key;
            if(input == "ADD"){
                if(add(key, m, l, head, 0, 0, 0) == 1);
                else{
                    m = 2*m + 1;
                    Floor** temp = head;
                
                    Floor** newBuilding = new Floor*[m];
                    for (int i = 0; i < m; i++){
                        newBuilding[i] = new Floor[l];
                        for(int j = 0; j < l; j++){
                            newBuilding[i][j].ocupado = 0;
                            newBuilding[i][j].key = 100000;
                        }
                    }

                    head = newBuilding;
                
                    for(int i = 0; i < ((m-1)/2); i++){
                        for(int j = 0; j < l; j++){
                            if(temp[i][j].ocupado == 1){
                                add(temp[i][j].key, m, l, head, 0, 0, 1);
                           }
                        }
                    }       
                    for (int i = 0; i < ((m-1)/2); i++){
                        delete[] temp[i];
                    } 
                    add(key, m, l, head, 0, 0, 0);
                }
            }
            else if(input == "REM"){
                rem(key, head, m, l);
            }
            else if(input == "QRY"){
                qry(key, head, m, l);
            }
        }
    }
    for (int i = 0; i < m; i++){
        delete[] head[i];
    }
    delete[] head; 
      
    return 0;
}