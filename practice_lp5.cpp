//bfs-cpp-original
/*
#include<iostream>
#include<stdlib.h>
#include<omp.h>
#include<queue>
using namespace std;
class node
{
public:
    node *left, *right;
    int data;
};
class Breadthfs
{
public:
    node *insert(node *, int);
    void bfs(node *);
};
node *insert(node *root, int data)
// inserts a node in tree
{
    if(!root)
    {
        root=new node;
        root->left=NULL;
        root->right=NULL;
        root->data=data;
        return root;
    }
    queue<node *> q;
    q.push(root);
    while(!q.empty())
    {
        node *temp=q.front();
        q.pop();
        if(temp->left==NULL)
        {
            temp->left=new node;
            temp->left->left=NULL;
            temp->left->right=NULL;
            temp->left->data=data;
            return root;
        }
        else
        {
            q.push(temp->left);
        }
        if(temp->right==NULL)
        {
            temp->right=new node;
            temp->right->left=NULL;
            temp->right->right=NULL;
            temp->right->data=data;
            return root;
        }
        else
        {
            q.push(temp->right);
        }
    }
}
void bfs(node *head)
{
    queue<node*> q;
    q.push(head);
    int qSize;
    while (!q.empty())
    {
        qSize = q.size();
        #pragma omp parallel for
//creates parallel threads
        for (int i = 0; i < qSize; i++)
        {
            node* currNode;
            #pragma omp critical
            {
                currNode = q.front();
                q.pop();
                cout<<"\t"<<currNode->data;
            }// prints parent node
            #pragma omp critical
            {
                if(currNode->left)// push parent's left node in queue
                    q.push(currNode->left);
                if(currNode->right)
                    q.push(currNode->right);
            }// push parent's right node in queue
        }
    }
}
int main()
{
    node *root=NULL;
    int data;
    char ans;
    do
    {
        cout<<"\n enter data=>";
        cin>>data;
        root=insert(root,data);
        cout<<"do you want insert one more node?";
        cin>>ans;
    }
    while(ans=='y'||ans=='Y');
    bfs(root);
    return 0;
}
*/

//bfs_python
/*
graph={
    'A':['B','C'],
    'B':['A','D','E'],
    'C':['A','F','G'],
    'D':['B'],
    'E':['B'],
    'F':['C'],
    'G':['C']
}

def bfs(graph, initial):
    visited=[]
    queue=[initial]
    while(queue):
        node=queue.pop(0)
        if node not in visited:
            visited.append(node)
            neighbours=graph[node]
            for neighbour in neighbours:
                queue.append(neighbour)
    return visited

print(bfs(graph,'A'))
/*

//dfs
/*
#include<iostream>
#include<vector>
#include<stack>
#include<omp.h>

using namespace std;
const int MAX=100000;
vector<int> graph[MAX];
bool visited[MAX];

void dfs(int node)
{
    stack<int> s;
    s.push(node);
    while(!s.empty())
    {
        int curr_node=s.top();
        if(!visited[curr_node]){
            visited[curr_node]=true;
            s.pop();
            cout<<curr_node<<" ";
            #pragma omp parallel for
            for(int i=0;i<graph[curr_node].size();i++){
                int adj_node=graph[curr_node][i];
                if(!visited[adj_node]){
                    s.push(adj_node);
                }
            }
        }
    }
}
int main()
{
    int n, m, start_node;
    cout<<"Enter the no. of nodes, no. of Edges & start node:\n";
    cin>>n>>m>>start_node;

    //n:node m:edge

    cout<<"Enter the pair of node and edge:\n";
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=0;i<n;i++){
        visited[i]=false;
    }
    dfs(start_node);
    return 0;

}
*/

//bubble sort
/*
#include<iostream>
#include<vector>
#include<omp.h>
using namespace std;

void bubb(vector<int> &arr)
{
    bool isSorted=false;
    while(!isSorted)
    {
        isSorted=true;
        for(int i=0;i<arr.size()-1;i+=2){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                isSorted=false;
            }
        }
        for(int i=1;i<arr.size()-1;i+=2){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
                isSorted=false;
            }
        }
    }
}
int main()
{
    vector<int> arr={5,3,7,8,2,9,4};
    double start, end;
    bubb(arr);
    cout<<"Sorted array is:\n";
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"Time is :"<<end-start;
    return 0;
}
*/
//Mergesort
/*
#include <bits/stdc++.h>

using namespace std;

void mergeofarrays(int a[], int low, int mid, int high) {
  int i = low, j = mid + 1, index = low, temp[100], k;

  while ((i <= mid) && (j <= high)) {
    if (a[i] < a[j]) {
      temp[index] = a[i];
      i++;
    } else {
      temp[index] = a[j];
      j++;
    }
    index++;
  }

  //copy the remaining elements of right array
  if (i > mid) {
    while (j <= high) {
      temp[index] = a[j];
      j++;
      index++;
    }
  } else //remaining elements of left array
  {
    while (i <= mid) {
      temp[index] = a[i];
      i++;
      index++;
    }
  }

  for (k = low; k < index; k++) //copying into original array
  {
    a[k] = temp[k];
  }

}

void mergesort(int a[], int low, int high) {
  if (low < high) {
    int middle = (low + high) / 2; //calculating middle index of array to divide it in two halves

    mergesort(a, low, middle); //sorting first half
    mergesort(a, middle + 1, high); //sorting second half

    mergeofarrays(a, low, middle, high); //merging 2 sorted halves
  }
}

int main() {
  int n = 7;
  int a[100] = {54,34,23,10,98,2,3};
  mergesort(a, 0, 6);

  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
}
*/

//min, max, average, sum
/*
#include <iostream>
#include<limits.h>
#include <vector>
#include <omp.h>
using namespace std;
void min_reduction(vector<int>& arr)
{
    int min_value = INT_MAX;
    #pragma omp parallel for reduction(min: min_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < min_value)
        {
            min_value = arr[i];
        }
    }
    cout << "Minimum value: " << min_value << endl;
}
void max_reduction(vector<int>& arr)
{
    int max_value = INT_MIN;
    #pragma omp parallel for reduction(max: max_value)
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max_value)
        {
            max_value = arr[i];
        }
    }
    cout << "Maximum value: " << max_value << endl;
}
void sum_reduction(vector<int>& arr)
{
    int sum = 0;
    #pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    cout << "Sum: " << sum << endl;
}
void average_reduction(vector<int>& arr)
{
    int sum = 0;
    #pragma omp parallel for reduction(+: sum)
    for (int i = 0; i < arr.size(); i++)
    {
        sum+= arr[i];
    }
    cout << "Average: " << (double)sum / arr.size() << endl;
}
int main()
{
    vector<int> arr = {5, 2, 9, 1, 7, 6, 8, 3, 4};
    min_reduction(arr);
    max_reduction(arr);
    sum_reduction(arr);
    average_reduction(arr);
}
*/
