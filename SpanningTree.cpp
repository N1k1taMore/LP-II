/*
You have a business with several offices; you want to lease
phone lines to connect them up with each other; and the
phone company charges different amounts of money to
connect different pairs of cities. You want a set of
lines that connects all your offices with a minimum
total cost. Solve the problem by suggesting appropriate
data structures.
*/

#include <iostream>
using namespace std;

class MST{
    int n,e;
    int **adj;
    int **b;
    int **c;
    string *landmark;

public:
    MST(){
        n=0;
        e=0;
        adj=NULL;
        b=NULL;
        c=NULL;
        landmark=NULL;
    }

    MST(int ni,int ei){
        n=ni;
        e=ei;
        adj=new int*[n];
        b=new int*[n];
        c=new int*[n];
        landmark=new string[n];
        for(int i=0;i<n;i++){
            adj[i]=new int[n];
            b[i]=new int[n];
            c[i]=new int[n];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                adj[i][j]=0;
                b[i][j]=0;
                c[i][j]=0;
            }
        }
    }
    void add_edge(int src,int dest,int w){
        adj[src][dest]=w;
        adj[dest][src]=w;
    }
    
    int getid(string src){
        for (int i = 0; i < n; i++){
			if (src == landmark[i]){
				return i;
			}
		}
        return -1;
    }
    void display(){
        cout << "  ";
		for (int i = 0; i < n; i++) {
			cout << i << " ";
		}
		cout << endl;
		for (int i = 0; i < n; i++) {
			cout << i << " ";
			for (int j = 0; j < n; j++) {
				cout << adj[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
    }
    void create(){
        int u, v, cost; // start,end,weight
        string src, dest;
        cout << "Enter Name of Landmarks: ";
        for (int i = 0; i < n; i++)
        {
            cin >> landmark[i];
        }
        for (int i = 0; i < e; i++)
        {
            cout << "Enter enter source, destination and it's weight: ";
            cin >> src >> dest >> cost;
            u=getid(src);
            v=getid(dest);
            add_edge(u, v, cost);
        }
    }
   
    void prims(){
        int inf = 9999999;
        int cost = 0;
        bool selected[n];
        for (int i = 0; i < n; i++)
        {
            selected[i] = false;
        }
        int no_edge = 0;
        int x, y;
        selected[0] = true;
        while (no_edge < (n - 1))
        {
            int min = inf;
            x = 0;
            y = 0;
            for (int i = 0; i < n; i++)
            {
                if (selected[i] == true)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (selected[j] == false && adj[i][j] != 0 && min > adj[i][j])
                        {
                            min = adj[i][j];
                                x = i;
                                y = j;		
                        }
                    }
                }
            }
            cout << landmark[x] << " - " << landmark[y] << " : " << adj[x][y];
            b[x][y] = adj[x][y];
            b[y][x] = adj[x][y];
            cost = cost + adj[x][y];
            cout << endl
            << endl;
            selected[y] = true;
            no_edge++;
        }
        cout << "MINIMUM SPANNING TREE:- " << endl;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++)
            {
                cout << b[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "Minimum cost by Prims Algorithm: " << cost << endl;
    }

    void kruskals(){
        int inf = 99999;
        int selected[n];    //used to store the root of nodes
        int cost = 0;
        for (int i = 0; i < n; i++)
        {
            selected[i] = -1;
        }
        int no_edges = 0;
        int x,y; 
        int root_temp1, root_temp2, temp1, temp2;
        while (no_edges < n - 1)
        {
            int min =inf;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (adj[i][j] != 0 &&  min > adj[i][j])
                    {
                        min = adj[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
            temp1 = x;
            temp2 = y;
            adj[x][y] = adj[y][x] = 0;
            while (x >= 0)
            {
                root_temp1 = x;  //stores current node
                x = selected[x];    // x stores the root of current node
            }
            while (y >= 0)
            {
                root_temp2 = y;
                y = selected[y];
            }
            if (root_temp1 != root_temp2)   //checks if both nodes have same root or not
            {
                c[temp1][temp2] = c[temp2][temp1] = min;
                cost = cost + c[temp1][temp2];
                selected[root_temp2] = root_temp1;   //changes the rootnode of newly added node
                no_edges++;
            }
        }
        cout << "MINIMUM SPANNING TREE:- " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << c[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "Minimum cost by Kruskals Algorithm: " << cost << endl;
    }
};
int main(){
    int v, e;
	cout << "Enter no. of vertices: " << endl;
	cin >> v;
	cout << "Enter no. of edges: " << endl;
	cin >> e;
    MST p(v,e);
	int ch;
	do{
		cout << "\n----------Menu----------" << endl;
		cout << "1.Create the Graph" << endl;
		cout << "2.Display the graph" << endl;
		cout << "3.Minimum Cost using Prims Algorithm" << endl;
		cout << "4.Minimum Cost using Kruskals Algorithm" << endl;
		cout << "5.Exit " << endl;
		cout << "Enter your choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			p.create();
			break;
		case 2:
			p.display();
			break;
		case 3:
			p.prims();
			break;
		case 4:
			p.kruskals();
			break;
		case 5:
			cout << "Code Exited" << endl;
			exit('0');
		default:
			cout << "\nEnter correct choice!!" << endl;
			break;
		}
	}
    while(ch<5);
	return 0;
}