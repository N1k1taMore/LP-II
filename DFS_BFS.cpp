#include<bits/stdc++.h>

using namespace std;

class Traversal
{
public:
    int numEdges;
    unordered_map<string, vector<string> > graph;

    void createGraphFromUserInput(){
        cout << "Enter the number of edges: ";
        cin >> numEdges;

        cout << "Enter the edges in format 'source destination' (e.g., 'A B'):" << endl;
        for (int i = 0; i < numEdges; ++i)
        {
            string source, destination;
            cin >> source >> destination;
            graph[source].push_back(destination);
            graph[destination].push_back(source);
        }
    }

    void printGraph(){
        cout << "Graph:" << endl;
        for (auto entry : graph)
        {
            cout << entry.first << ": ";
            for (string neighbor : entry.second)
            {
                cout << neighbor << " ";
            }
            cout << endl;
        }
    }
    
    bool dfs(const string &currentNode, unordered_set<string> &visited,string target)
    {
        if (currentNode == target){
            cout << currentNode << " Found " << endl;
            return true;
        }
        visited.insert(currentNode);
        cout << currentNode << endl;
        for (const string &neighbor : graph.at(currentNode))
        {
            if (visited.find(neighbor) == visited.end())
            {
                if (dfs(neighbor, visited, target))
                    return true;
            }
        }
        return false;
    }

    bool bfsRecursive(unordered_set<string>& visited, queue<pair<string, int>>& q,string target){
        if (q.empty()) {
            return false;
        }   
        string currentNode = q.front().first;
        int level = q.front().second;
        q.pop();
        cout << currentNode << " at level " << level << endl;
    
        if (currentNode == target) {
            cout << currentNode << " Found at level " << level << "!" << endl;
            return true;
        }
    
        for (const string& neighbor : graph.at(currentNode)) {
            if (visited.find(neighbor) == visited.end()) {
                visited.insert(neighbor);
                q.push({neighbor, level + 1});
            }
        }
    
        return bfsRecursive(visited, q,target);
    }
    
    bool bfs() {
        string startNode;
        string target;
        cout<<"Enter starting City :"<<endl;
        cin>>startNode;
        cout<<"Enter Target City :"<<endl;
        cin>>target;
        unordered_set<string> visited;
        queue<pair<string, int>> q;
        q.push({startNode, 0});
        visited.insert(startNode);
        return bfsRecursive(visited, q,target);
    }
};
int main()
{
    Traversal t;
    string startNode;
    string targetnode;
    
    int c=0;
    do{
        cout<<"------MENU---------"<<endl;
        cout<<"1.Create Graph"<<endl;
        cout<<"2.Display"<<endl;
        cout<<"3.DFS"<<endl;
        cout<<"4.BFS"<<endl;
        cout<<"5.EXIT"<<endl;
        cout<<"\n Enter choice :"<<endl;
        cin>>c;
        if(c==1){
             // Create graph from user input
            t.createGraphFromUserInput();
        }
        else if(c==2){
            t.printGraph();
        }
        else if(c==3){
            cout << "DFS:" << endl;
            cout<<"Enter starting City :"<<endl;
            cin>>startNode;
            cout<<"Enter Target City :"<<endl;
            cin>>targetnode;
            unordered_set<string> visitedDfs;
            t.dfs(startNode, visitedDfs,targetnode);
        }
        else if(c==4){
            cout << "BFS:" << endl;
            t.bfs();
        }
        else {
            cout<<"EXIT"<<endl;
        }
    }
    while(c<5);
    return 0;
}