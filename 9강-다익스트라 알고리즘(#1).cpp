#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

#define INFINITE    100000

struct Node{
    int ver;
    int cost;
    Node* link;
};

Node* AllocNode(int ver, int cost){
    Node* p = new Node;
    p->ver = ver;
    p->cost = cost;
    p->link = NULL;
    return p;
};

void AddNode(Node*& head, int ver, int cost){
    if(head == NULL)
        head = AllocNode(ver, cost);
    else{
        Node* tail;
        for(tail = head; tail->link != NULL; tail = tail->link)
            ;
        tail->link = AllocNode(ver, cost);
    }
};

void PrintNode(Node* head){
    for(Node* p = head; p != NULL; p = p->link)
        printf("%d\n", p->ver);
}

void DestroyNode(Node* haed){
    for (Node*p = haed; p != NULL; p = p->link){
        Node* np = p->link;
        delete p;
        p = np;
    }
}

struct Graph{
    Node** head;
    int verSize;
};

void AddEdge(Graph* pg, int sv, int ev, int cost){
    AddNode(pg->head[sv], ev, cost);
}

void PrintGraph(Graph* pg){
    printf("V: ");
    for (int i=0; i<pg->verSize; ++i)
        printf("%d ", i);
    printf("\n");
    for (int i=0; i<9; ++i){
        pg->head[i];
        printf("E: ");
        for (Node* p=pg->head[i]; p != NULL; p=p->link){
            printf("(%d,%d-%d)", i, p->ver, p->cost);
        }
        printf("\n");
    }
}

void InitGraph(Graph*pg, int verSize){
    pg->verSize = verSize;
    pg->head = new Node*[verSize];
    for(int i=0; i<verSize; ++i)
        pg->head[i] = NULL;
}

void UninitGraph(Graph*pg){
    for (int i=0; i<pg->verSize; ++i)
        DestroyNode(pg->head[i]);
    delete[] pg->head;
}

struct Edge{
    int ver;
    int cost;
    Edge(int v, int c) : ver(v), cost(c) {}
    // 내림차순
    bool operator<(const Edge& arg) const{
        return cost < arg.cost;
    }
    // 오름차순
    //bool operator<(const Edge& arg) const{
    //    return arg.cost < cost;
    //}
};

void Dijkstra(Graph* p, int sv){
    int* distance = new int[p ->verSize];
    int* startingPoint = new int[p->verSize];
    for (int i=0; i<p->verSize; ++i)
        distance[i] = INFINITE;
    priority_queue<Edge> pq;
    distance[sv] = 0;
    startingPoint[sv] = sv;
    for(Node* n = p->head[sv]; n!=NULL; n->link){
        distance[n->ver] = n->cost;
        startingPoint[n->ver] = sv;
        pq.push(Edge(n->ver, n->cost));
    }
    while(!pq.empty()){
        Edge min = pq.top();
        pq.pop();
        for (Node* n=p->head[min.ver]; n!=NULL; n=n->link){
            if(distance[min.ver] + n->cost < distance[n->ver]){
                distance[n->ver] = distance[min.ver] + n->cost;
                startingPoint[n->ver] = min.ver;
                pq.push(Edge(n->ver, distance[n->ver]));
            }
        }
    }
    for (int i=0; i<p->verSize; ++i)
        printf("distance[%d->%d] : %d\n", startingPoint[i], i, distance[i]);
    delete[] distance;
    delete[] startingPoint;
}

int main(){
    Graph g;
    InitGraph(&g, 9);
    AddEdge(&g, 0, 1, 8);
    AddEdge(&g, 0, 2, 15);
    AddEdge(&g, 0, 3, 20);

    AddEdge(&g, 1, 4, 5);

    AddEdge(&g, 2, 3, 3);
    AddEdge(&g, 2, 5, 20);
    AddEdge(&g, 2, 6, 15);
    AddEdge(&g, 2, 8, 37);

    AddEdge(&g, 3, 8, 30);

    AddEdge(&g, 4, 5, 14);
    AddEdge(&g, 4, 7, 10);

    AddEdge(&g, 5, 8, 20);

    PrintGraph(&g);

    Dijkstra(&g, 0);

    UninitGraph(&g);
    return 0;
}