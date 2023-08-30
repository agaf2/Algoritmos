#include <iostream>

using namespace std;

class UnionFind{
    private:
    
    int val;
    UnionFind *parent;
    int height;

    public:
    
    UnionFind* carrega(UnionFind *U,int n){
        for(int i = 0; i < n*n; i++){
            U[i].val = i;
            U[i].parent = nullptr;
            U[i].height = 0;
        }   
    }

    UnionFind *find(UnionFind *U,UnionFind *x){
        if(x->parent == x){
            return x;
        }

        x->parent = find(U,x->parent);
        return x->parent;
    }

    int Union(UnionFind *U, UnionFind* a, UnionFind* b){
        UnionFind * ra = find(U,a);
        UnionFind * rb = find(U,b);
        if(ra->height == rb->height){
            rb->parent = rb;
            ra->height++;
        }
        else{
            if(ra->height > rb->height)
                rb->parent = ra;
            else
                ra->parent = rb;
            
        }

    }

};

struct Pares
    {
        int a;
        int b;
        int j;
    };

int main(){
    
    int cases;

    cin >> cases;
    for(int i = 0; i < cases; i++){
        int n, m, q, flag =1, input;
        cin >> n >> m >> q;

        UnionFind *U = new UnionFind[n*n];    

        int rem[2*(n*n-n)-1];
        for (int j = 0; j < m; j++){
            if(flag){
                cin >> input;
                flag = 0;
            }
            if(input == i){
                rem[j] = 1;
                flag = 1;
            }
            else{
                rem[j] = 0;
            }
        }
        Pares pares[q];

        for(int j = 0; j < q; j++){
            cin >> pares[j].a >> pares[j].b;
        }

        U = U->carrega(U,n*n);

        for(int i = 0; i < q; i++){
            UnionFind * pa, *pb;
            for(int k = 0; k < n*n; k++){
                if(pares[i].a == k)
                    pa = &U[k];
                if(pares[i].b == k)
                    pb = &U[k];
            }

            if(U[i].Union(U,  pa, pb)){
                cout << cases << "." << i << " " << "1" <<endl;
            }
            else{
                cout << cases << "." << i << " " << "0" <<endl;
            }
        }

    }


    return 0;
}