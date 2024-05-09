#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <map>

using namespace std;

const int INF = numeric_limits<int>::max(); // Infinity value for distances

class Graph {
public:
    int vertices;
    vector<vector<pair<int, int>>> adjList;
    map<string, int> cityToId; // Map to store city names and their corresponding IDs

public:
    Graph(int V) : vertices(V), adjList(V) {}

    // Add an edge to the graph
    void addEdge(int source, int destination, int weight) {
        adjList[source].push_back({destination, weight});
        adjList[destination].push_back({source, weight}); // For undirected graph
    }

    // Add a city to the map and return its ID
    int addCity(string city) {
        if (!cityToId.count(city)) {
            int id = cityToId.size();
            cityToId[city] = id;
        }
        return cityToId[city];
    }

    // Get the ID of a city given its name
    int getCityId(string city) {
        if (cityToId.count(city)) {
            return cityToId[city];
        } else {
            cerr << "City not found!\n";
            return -1; // Return -1 if city not found
        }
    }

    // Dijkstra's algorithm for Single Source Shortest Path
    vector<int> dijkstra(int source) {
        vector<int> distances(vertices, INF);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min-heap

        distances[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (auto& neighbor : adjList[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distances[u] != INF && distances[u] + weight < distances[v]) {
                    distances[v] = distances[u] + weight;
                    pq.push({distances[v], v});
                }
            }
        }

        return distances;
    }
};

int main() {
   int V;
    cout<<"Enter the number of Cities :"<<endl;
    cin>>V;
    Graph graph(V);

    // Adding cities and edges with weights to the graph
    cout<<"Enter the Names of city :"<<endl;
    for(int i=0;i<V;i++){
        string name;
        cin>>name;
        graph.addCity(name);
    }
    
    bool add=true;
    while(add){
        string src;
        string dest;
        int distance;
        cout<<"Enter Source :"<<endl;
        cin>>src;
        cout<<"Enter Destination :"<<endl;
        cin>>dest;
        cout<<"Enter Distance :"<<endl;
        cin>>distance;
        graph.addEdge(graph.getCityId(src), graph.getCityId(dest), distance);
        
        cout<<"Do You want to add new Route :(y/n)";
        string flag;
        cin>>flag;
        if(flag=="y" || flag=="Y"){
            add=true;
        }
        else{
            add=false;
        }
    }
    
    string city;
    cout<<"Enter the source city for shortest path calculation :"<<endl;
    cin>>city;

    vector<int> shortestDistances = graph.dijkstra(graph.getCityId(city));

    cout << "Shortest distances from source city " << city << " to all other cities:\n";
    for (const auto& city : graph.cityToId) {
        cout << "City " << city.first << ": ";
        if (shortestDistances[city.second] == INF) {
            cout << "INF";
        } else {
            cout << shortestDistances[city.second];
        }
        cout << endl;
    }

    return 0;
}

/*
 A-B-4
 A-C-1
 B-C-2
 B-D-5
 C-D-2
 C-E-1
 D-E-3
 E-F-2
 
*/
