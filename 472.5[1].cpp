#include <bits/stdc++.h>
#include <fstream>
using namespace std;

ofstream outfile;

struct node {
    int weight;
    char ch;
    node* lc;
    node* rc;
};

struct my_greater : binary_function < node*, node*, bool> {
  bool operator() (const node* x, const node* y) const {return x->weight > y->weight;}
};

vector<bool> st;

void dfs(node* a)
{
    if (a->lc != NULL && a->rc != NULL) {
        st.push_back(0);
        dfs(a->lc);
        st.push_back(1);
        dfs(a->rc);
    }
    else {
        outfile << a->ch << " ";
        for (int i = 0;i < st.size();i++)
            outfile << st[i];
        outfile << "\n";
    }
    st.pop_back();
}

int main()
{
    priority_queue <node*, vector<node*>, my_greater> min_heap;
    ifstream infile;
    infile.open("freq.txt");
    char c;
    int n;
    for (; infile >> c >> n;) {
        node *a = new(node);
        a->weight = n;
        a->ch = c;
        a->lc = NULL;
        a->rc = NULL;
        min_heap.push(a);
    }
    while (min_heap.size() > 1) {
        node* a = min_heap.top();
        min_heap.pop();
        node* b = min_heap.top();
        min_heap.pop();
        node* parent = new(node);
        parent->weight = a->weight + b->weight;
        parent->lc = a;
        parent->rc = b;
        min_heap.push(parent);
    }
    // std::cout << min_heap.top()->weight;
    outfile.open("code.txt");
    dfs(min_heap.top());
    outfile.close();
}
