// Autor: Matylda Dębska
// Nr indeksu: 325684
// Zadanie: Mapa nieba


/*
*
*  Weighted quick union implementation of union-find algotithm
*  with path compression
*
*  A reference implementation
*
*
*  Author: Jacek Marciniak
*  Date: 2015-11-07
*
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;


// data
int cc;            // number of components
int N;            // number of elements
vector<int> id; // id[i] = parent of i
vector<int> sz; // sz[i] = number of elements in subtree rooted at i

// initializes data structures
void init(int size)
{
    cc = size;
    N = size;

    id.resize(size);
    sz.resize(size);

    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
}

// gets component's identifier of the element
int find(int p)
{
    int r = p;

    while (r != id[r]) // find
    {
        r = id[r];
    }

    while (p != r) // path compression
    {
        int n = id[p];
        id[p] = r;
        p = n;
    }

    return r;
}

// check if 2 elements belongs to the same component
bool connected(int p, int q)
{
    return find(p) == find(q);
}

// connect components
void make_union(int p, int q)
{
    int pid = find(p);
    int qid = find(q);

    if (pid == qid) return;

    // make smaller root point to larger one
    if (sz[qid] < sz[pid])
    {
        id[qid] = pid;
        sz[pid] += sz[qid];
    }
    else
    {
        id[pid] = qid;
        sz[qid] += sz[pid];
    }
    cc--;
}

// print an array
void print_id()
{
    cout << "[";
    for (int i = 0; i < N; i++)
    {
        cout << (i > 0 ? "," : "") << id[i];
    }
    cout << "]" << endl;
}

int main() {
    
	int n;
	cin >> n;

    
    // inicjalizacja tablicy dwuwymiarowej
    int** mapa = new int* [n];
    for (int i = 0; i < n; i++) {
        mapa[i] = new int[n];
    }

    // wczytanie mapy
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mapa[i][j];
        }
    }
    
    // scalanie jedynek 
	int max = 0;
	init(n * n);
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (mapa[row][col] == 1) {
                
				// jedynka na dole
				if (row > 0 && mapa[row - 1][col] == 1) {
					make_union(row * n + col, (row - 1) * n + col);
				}
                 
				// jedynka na lewo
				if (col > 0 && mapa[row][col - 1] == 1) {
					make_union(row * n + col, row * n + col - 1);
				}

                // jedynka na górze 
				if (row < n - 1 && mapa[row + 1][col] == 1) {
					make_union(row * n + col, (row + 1) * n + col);
				}
                
				// jedynka na prawo
				if (col < n - 1 && mapa[row][col + 1] == 1) {
					make_union(row * n + col, row * n + col + 1);
				}
			}
		}
	}
    
	// szukanie najdłuższego ciągu    
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (mapa[row][col] == 1) {
				if (sz[find(row * n + col)] > max) {
					max = sz[find(row * n + col)];
				}
			}
		}
	}
   
    // zlicanie zer w tablicy
	int zeros = 0;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			if (mapa[row][col] == 0) {
				zeros++;
			}
		}
	}
    
	int constellations = cc - zeros;
    
	cout << constellations << " " << max << endl;
    
	for (int i = 0; i < n; i++) {
		delete[] mapa[i];
	}
    delete[] mapa;
    
	return 0;
}