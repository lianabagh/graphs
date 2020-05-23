
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
//			all_edges[i].push_back(make_pair(i+1,-1));	
		}
		if((i+row)<V)
		{
			addEdge(i,i+row,-1);	
//			all_edges[i].push_back(make_pair(i+row,-1));

		}


	}    
    set_edges();
   // printGraph();

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
	//return all_edges;
		return edges;
} 
void Graph::addEdge(int v, int w,int weight) 
{ 
    adj[v].push_back(make_pair(w, weight)); 
    adj[w].push_back(make_pair(v, weight));

   // vec[v]+=1;
   // vec[w]+=1;
	 // Add w to v’s list. 
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
    // Initialize min value  
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
//		par = parent[i];  
//auto it = find_if( adj[i].begin(), adj[i].end(),[&par](const pair<int, int>& element){ return element.first == par;} );
//        	cout<<parent[i]<<" - "<<i<<" \t"<<it->second<<" \n";  
	}
}  



int* Graph::primMST()  
{  
    // Array to store constructed MST  
    int *parent = new int[V];  
      
    // Key values used to pick minimum weight edge in cut  
    int key[V];  
      
    // To represent set of vertices not yet included in MST  
    bool mstSet[V];  
  
    // Initialize all keys as INFINITE  
    for (int i = 0; i < V; i++)  
        key[i] = INT_MAX, mstSet[i] = false;  
  
    // Always include first 1st vertex in MST.  
    // Make key 0 so that this vertex is picked as first vertex.  
    key[0] = 0;  
    parent[0] = -1; // First node is always root of MST  
  
    // The MST will have V vertices  
    for (int count = 0; count < V - 1; count++) 
    {  
        // Pick the minimum key vertex from the  
        // set of vertices not yet included in MST  
        int u = minKey(key, mstSet);  
  
        // Add the picked vertex to the MST Set  
        mstSet[u] = true;  
  
        // Update key value and parent index of  
        // the adjacent vertices of the picked vertex.  
        // Consider only those vertices which are not  
        // yet included in MST  
        for(auto v = adj[u].begin(); v != adj[u].end(); ++v)  
  
            // graph[u][v] is non zero only for adjacent vertices of m  
            // mstSet[v] is false for vertices not yet included in MST  
            // Update the key only if graph[u][v] is smaller than key[v]  
            if (mstSet[v->first] == false && v->second < key[v->first])  
               {
			 parent[v->first] = u, key[v->first] = v->second; 
			 edges[v->first]=v->second;
		} 
    }  
    // print the constructed MST  
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
	//			for(auto j = all_edges[v].begin(); j != all_edges[v].end(); ++j)
	//				if (i->first == j->first)
//
//						j->second = max(a,b);
                        }
                }
	//print_vert();
  //      std::cout<<"vse"<<std::endl; 
	set_edges_minus();

}  
