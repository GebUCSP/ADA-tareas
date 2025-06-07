#include <iostream>
#include <map>
#include <list>
#include <utility>
#include <vector>

using namespace std;

struct Graph {
map<int, list<pair<int, int>>> main;

void add(int a, int b, int w) {
main[a].push_back(make_pair(b, w));
main[b].push_back(make_pair(a, w));
}

void print()
{
for (auto i : main) {
cout << i.first << " -> ";
for (auto j : i.second) {
cout << j.first << " (" << j.second << ") ";
}
cout << endl;
}
}
};

void impl(Graph g) {
vector<int>order;
for ( auto p : g.main) {
pair<int, int> min;
for (auto q : p.second) {
if (q.second < min.second ) {
min = q;
}
}

}
}

int main(int argc, char* argv[]) {

Graph g;
g.add(6, 7, 12);
g.add(6, 5, 6);
g.add(5, 7, 5);
g.add(5, 3, 14);
g.add(5, 8, 8);
g.add(3, 8, 3);
g.add(7, 0, 7);
g.add(7, 9, 9);
g.add(15, 0, 15);
g.add(8, 0, 10);

g.print();

impl(g);
return 0;
}
