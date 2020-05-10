#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;


struct Edge{
    int ver;
    int cost;
    Edge(int v, int c) : ver(v), cost(c) {}
    // 내림차순
    // bool operator<(const Edge& arg) const{
    //     return cost < arg.cost;
    // }
    // 오름차순
    bool operator<(const Edge& arg) const{
        return arg.cost < cost;
    }
};

int main(){
    priority_queue<Edge> pq;
    pq.push(Edge(1, 20));
    pq.push(Edge(2, 15));
    pq.push(Edge(3, 8));
    
    printf("%d\n", pq.top().cost);
    pq.pop();
    
    printf("%d\n", pq.top().cost);
    pq.pop();
    
    printf("%d\n", pq.top().cost);
    pq.pop();

    system("pause");
}