#include <iostream>

using namespace std;

class UnionFind {

public:

    UnionFind(int n) {
        parent = new int[n];
        height = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            height[i] = 0;
        }
    }

    int find(int x) {
        if(parent[x] == x)
            return x;
        else
            parent[x] = find(parent[x]);
            return parent[x];
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if(height[rootY] == height[rootX]){
            parent[rootY] = rootX;
            height[rootX]++;
        }
        else{
            if(height[rootX] > height[rootY])
                parent[rootY] = rootX;
            else
                parent[rootX] = rootY;
        }
        
    }

    bool sameClass(int x, int y) {
        return find(x) == find(y);
    }

    ~UnionFind() {
        delete[] parent;
        delete[] height;
    }	

private:
    int *parent;
    int *height;
};

int main(){
    int cases;

    cin >> cases;
    for(int i = 0; i < cases; i++){
        int n, m, q;
        cin >> n >> m >> q;
                
        UnionFind U(n*n);

       for(int j = 0, input; j < m; j++){
            cin >> input;        
            if( input %(2* n - 1) < n - 1){
                   int local = n*(input / (2*n - 1)) + input%(2*n - 1);
                   U.Union(local, local + 1 ); // horizontal
            }
            else{
                    int local = n*( input /(2*n - 1)) + input % (2*n - 1) - (n - 1);
                    U.Union(local, local + n); // vertical
            } 
        }

        for(int j = 0, a ,b ; j < q; j++){
            cin >> a >> b;   // pega os pares de entrada
            U.sameClass(a,b) ? cout << i << "." << j << " " << "1" <<endl : cout << i << "." << j << " " << "0" <<endl; 
        }
   

        
        printf("\n");
    }


    return 0;
}