
// C++ program to print DFS traversal for a given given graph 
#include<iostream>
#include"max_spanning.h" 
using namespace std; 

Graph::Graph(int row,int column):vec(row*column,0),edges(row*column,0)

{ 
    this->row = row;
    this->column = column;
    this->V = row * column;
    adj = new list<pair<int,int> >[V];
    all_edges = new list<pair<int,int>>[V];
    for(int i =0; i< V;i++)
	{ 
                int row_number = i/row;
                int col_num = i%row;
		if (row_number >( column-1)/2)
		
                        {
                                row_number =column-row_number-1;
                        }
                if (col_num>(row-1)/2)
                        {
                                col_num = row - col_num-1;
                        }
                vec[i] = min(row_number,col_num);
		if (((i+1) % row) != 0 && (i != V-1))
		{
			addEdge(i,i+1,-1);
		}
		if((i+row)<V)
		{
			addEdge(i,i+row,-1);	

		}

	}    
    set_edges();

}
 
void Graph::printGraph()

{

   for (int u = 0; u < V; u++)
    {
        cout << "Node " << u << " makes an edge with \n";
        for (auto it = adj[u].begin(); it!=adj[u].end(); it++)
        {
           int  v = it->first;
           int  w = it->second;
            cout << "\tNode " << v << " with edge weight ="
                 << w << "\n";
        }
        cout << "\n";
    }
}

vector<int> Graph::get_edges()

{
		return edges;
} 

void Graph::addEdge(int v, int w,int weight) 

{ 
    adj[v].push_back(make_pair(w, weight)); 
    adj[w].push_back(make_pair(v, weight));
}


void Graph::print_vert()

{
	vector<int>::iterator i;
	int j =0;
	for(i = vec.begin(); i != vec.end(); ++i)
      		{  
			std::cout<<j<<" "<<*i<<std::endl;
			j++;
     		}
}


int Graph::minKey(int key[], bool mstSet[])  

{  
    int min = INT_MAX, min_index;  
  
    for (int v = 0; v < V; v++)  
        if (mstSet[v] == false && key[v] < min)  
            min = key[v], min_index = v;  
  
    return min_index;  
}  



void Graph::printMST(int parent[])  

{  
    int par = 0;
    int i;
    for (i = 1; i < V; i++)
	{
		par = parent[i];  
		auto it = find_if( adj[i].begin(), adj[i].end(),[&par](const pair<int, int>& element){ return element.first == par													;} );
        	cout<<parent[i]<<" - "<<i<<" \t"<<it->second<<" \n";  
	}
}  



int* Graph::primMST()  

{  
    int *parent = new int[V];        
    int key[V];  
    bool mstSet[V];  
    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    key[0] = 0;  
    parent[0] = -1;  
  
    for (int count = 0; count < V - 1; count++) 
    {  
        int u = minKey(key, mstSet);  
        mstSet[u] = true;  
        for(auto v = adj[u].begin(); v != adj[u].end(); ++v)  
            if (mstSet[v->first] == false && v->second < key[v->first])  
               {
			 parent[v->first] = u, key[v->first] = v->second; 
			 edges[v->first]=v->second;
		} 

    }  
//    printMST(parent); 
    return parent; 
}

void Graph::set_edges_minus()

{
	for(int v=0; v<V; v++)
		for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
			i->second -= 2 * i->second;
}



void Graph::set_edges()

{
	for (int v = 0; v < V; v++)
                {
                        for(auto i = adj[v].begin(); i != adj[v].end(); ++i)
                        {
                                int a = vec[i->first];
                                int b = vec[v];
                                i->second = max(a,b);
                        }
                }
	set_edges_minus();

}  
