#include <iostream>

using namespace std;

struct Floor
{
    int key;
    int ocupado;
    int vagas;
};

Floor** head = NULL;

int binary_insert(int key, int floor, int l){
    int left = 0, right = l-1;
    while(left < right){
        int middle = (left + right)/2;
        if(head[floor][middle].key <= key)
            left = middle + 1;
        else
            right = middle;  
    }
    if(left < head[floor]->vagas && head[floor][left].key < key)
        left++;
    return left;
}

int binary_search(int key, int floor, int l){
    int left = 0;
    int right = l-1;
    int middle = (left + right)/2;
    int find = 0;
    while(left <= right && find == 0){
        if(head[floor][middle].key == key){
            find = 1;
        }
        else if(head[floor][middle].key > key){
            right = middle - 1;
            middle = (left + right)/2;      
        }
        else{
            left = middle + 1;
            middle = (left + right)/2;
        }
    }
    if(find == 0){
        return -1;
    }
    else{
        return middle;
    }
}

int hashing(int key, int m, int cont){
    int floor =  ((key % m) + cont) % m;
        return floor;
}

int add(int key, int m, int l, Floor** head, int cont, int realocing) {
    int aux;
    int local;
    int floor = hashing(key, m, cont);
    if (head[floor]->vagas == l) {
        cont++;
        if (cont != m)
            return add(key, m, l, head, cont, realocing);
        else {
            return 0;
        }
    } 
    else{
            local = binary_insert(key, floor, head[floor]->vagas);
            if(head[floor]->vagas != 0){
                for(int i = head[floor]->vagas; i > local; i--){
                    head[floor][i] = head[floor][i-1];
                }
            }
                head[floor][local].key = key;
                head[floor][local].ocupado = 1;
                head[floor]->vagas = head[floor]->vagas + 1;
                if(realocing != 1)
                    cout << floor << "." << local << endl;
            
        
        return 1;
    }
}


void rem(int key, Floor** head, int m, int l, int cont){
    int find = 0;
    int floor = hashing(key, m, cont);
    int result = binary_search(key, floor, head[floor]->vagas);
    if(result != -1 && head[floor][result].ocupado != -1){
        head[floor][result].ocupado = -1;
        cout << floor << "." << result << endl;
        find = 1;
    } 
    else if( result != -1 && head[floor][result].ocupado == -1){
        cout << "?.?" << endl;
        find = 1;
    }
    if (find == 0) {
        cont++;
        if (cont != m)
            return rem(key, head, m, l, cont);
        else {
            cout << "?.?" << endl;
        }
    }
    
    
}

void qry(int key, Floor** head, int m, int l, int cont){
 int find = 0;
 int floor = hashing(key, m,cont);
 int result = binary_search(key, floor, head[floor]->vagas);
    if( result != -1 && head[floor][result].ocupado != -1){
        cout << floor << "." << result << endl;
        find = 1;
    } 
    else if( result != -1 && head[floor][result].ocupado == -1){
        cout << "?.?" << endl;
        find = 1;
    }
    if (find == 0) {
        cont++;
        if (cont != m)
            return qry(key, head, m, l, cont);
        else {
            cout << "?.?" << endl;
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
            newBuilding[i]->vagas = 0;
        }
    }

    head = newBuilding;
    
    while(input != "END"){
        cin >> input;
        if(input != "END"){
        
            cin >> key;
            if(input == "ADD"){
                if(add(key, m, l, head, 0, 0) == 1);
                else{
                    m = 2*m + 1;
                    Floor** temp = head;
                
                    Floor** newBuilding = new Floor*[m];
                    for (int i = 0; i < m; i++){
                        newBuilding[i] = new Floor[l];
                        for(int j = 0; j < l; j++){
                            newBuilding[i][j].ocupado = 0;
                            newBuilding[i][j].key = 100000;
                            newBuilding[i]->vagas = 0;
                        }
                    }

                    head = newBuilding;
                                    
                    for(int i = 0; i < ((m-1)/2); i++){
                        for(int j = 0; j < l; j++){
                            if(temp[i][j].ocupado == 1){
                                add(temp[i][j].key, m, l, head, 0, 1);
                           }
                        }
                    }       
                    for (int i = 0; i < ((m-1)/2); i++){
                        delete[] temp[i];
                    } 
                    delete[] temp;

                    add(key, m, l, head, 0, 0);
                }
            }
            else if(input == "REM"){
                rem(key, head, m, l, 0);
            }
            else if(input == "QRY"){
                qry(key, head, m, l, 0);
            }
        }
    }
    for (int i = 0; i < m; i++){
        delete[] head[i];
    }
    delete[] head; 
      
    return 0;
}