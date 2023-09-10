#include <iostream>

using namespace std;

class Node {
public:
    int verticie;
    int peso;
    Node* next;
};

class Grafo {
private:
    int numVertices;
    Node** listadj;

    class MinHeap {
    private:
        int* heap;
        int* key;
        int size;

        void swap(int& a, int& b) {
            int temp = a;
            a = b;
            b = temp;
        }

        void bubble_down(int i) {
            int l = 2 * i + 1;
            int r = 2 * i + 2;
            int m = i;

            if (l < size && key[heap[l]] < key[heap[m]])
                m = l;

            if (r < size && key[heap[r]] < key[heap[m]])
                m = r;

            if (m != i) {
                swap(heap[i], heap[m]);
                bubble_down(m);
            }
        }

        void decreaseKey(int v, int k) {
            key[v] = k;
            int i = 0;
            while (i < size && heap[i] != v) {
                i++;
            }
            while (i > 0 && key[heap[(i - 1) / 2]] > key[heap[i]]) {
                swap(heap[i], heap[(i - 1) / 2]);
                i = (i - 1) / 2;
            }
        }

    public:
        MinHeap(int n) {
            size = 0;
            heap = new int[n];
            key = new int[n];
        }

        void insert(int v, int k, bool input) {
            heap[size] = v;
            key[v] = k;
        
            if(input){
                decreaseKey(v, k);
            }
            else{
                size++;

                int i = size - 1;
                while (i > 0 && key[heap[(i - 1) / 2]] > key[heap[i]]) {
                    swap(heap[i], heap[(i - 1) / 2]);
                    i = (i - 1) / 2;
                }
            }
        }

        int extract() {
            int minverticie = heap[0];
            int index = heap[size - 1];
            size--;

            heap[0] = index;

            bubble_down(0);

            return minverticie;
        }


        ~MinHeap() {
            delete[] heap;
            delete[] key;
        }
    };

public:
    Grafo(int vertices) {
        numVertices = vertices;
        listadj = new Node*[vertices];
        for (int i = 0; i < vertices; i++) {
            listadj[i] = nullptr;
        }
    }

    void addaresta(int origem, int destino, int peso) {
        Node* newNode = new Node;
        newNode->verticie = destino;
        newNode->peso = peso;
        newNode->next = listadj[origem];
        listadj[origem] = newNode;
    }

    void dijkstra(int src, int destino) {
        int* dist = new int[numVertices];
        int* prev = new int[numVertices];
        MinHeap minHeap(numVertices);

        for (int i = 0; i < numVertices; i++) {
            dist[i] = 999999; 
            prev[i] = -1;
            minHeap.insert(i, dist[i],0);
        }

        dist[src] = 0;
        minHeap.insert(src, 0,1);

        for(int i = 0; i < numVertices; i++) {
            int u = minHeap.extract();

            Node* e = listadj[u];
            while (e != nullptr) {
                int v = e->verticie;
                int w = e->peso;
                if (dist[u] != 999999 && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    prev[v] = u;
                    minHeap.insert(v, dist[v],1);
                }
                e = e->next;
            }
        }

        print(dist, destino);
        delete[] dist;
        delete[] prev;
    }

    void print(int* dist, int destino) {
        if (dist[destino] != 999999) {
            cout << dist[destino] << endl;
        }
        else {
            cout << "-1" << endl;
        }
    }

    ~Grafo() {
        for (int i = 0; i < numVertices; i++) {
            Node* current = listadj[i];
            while (current != nullptr) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }
        delete[] listadj;
    }
};

int main() {
    int q, r, n;

    cin >> q >> r >> n;

    Grafo Cidade(q);

    for (int i = 0; i < r; i++) {
        int a, b, m;
        cin >> a >> b >> m;
        Cidade.addaresta(a, b, m);
    }

    for (int i = 0; i < n; i++) {
        int a, b, m;
        cin >> m;
        if (m == 1) {
            cin >> a >> b >> m;
            Cidade.addaresta(a, b, m);
        }
        else {
            cin >> a >> b;
            Cidade.dijkstra(a, b);
        }
    }

    return 0;
}
