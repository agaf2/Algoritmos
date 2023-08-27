#include <iostream>

using namespace std;

class UnionFind{
    private:
    
    int val;
    UnionFind *parent;
    int height;

    public:
    UnionFind *find(UnionFind U,UnionFind *x){
        if((*x).parent == x){
            return x;
        }
        x->parent = find(U, x->parent);
        return x->parent;
    }

    UnionFind * Union(UnionFind U, UnionFind *a, UnionFind *b){
        a = find(U, a);
        b = find(U, b);
        if(a->height == b->height){
            b->parent = a;
            a->height++;
        }
        else{
            if(a->height > b->height){
            b->parent = a;
            }
            else{
            a->parent = b;
            }
        }
    }
        
    }

};


int main(){
    

    


    return 0;
}