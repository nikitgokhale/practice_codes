// C++ implementation of Least Frequently Used (LRU) page fault algorithm
#include <bits/stdc++.h>

using namespace std;

// Function to find page faults using indexes
int pageFaults(int pages[], int n, int capacity)
{
	unordered_set<int> s;

	unordered_map<int, int> indexes;
	int page_faults = 0;
	for (int i=0; i<n; i++){
		// Check if the set can hold more pages
		if (s.size() < capacity){
			if (s.find[pages[i]] == s.end()){
				s.insert(pages[i]);
				page_faults++;
			}
			indexes[pages[i]] = i;
		}

		else{
			if (s.find(pages[i]) == s.end()){
				int lru = INT_MAX, val;
				for (auto it=s.begin(); it!=s.end(); it++){
					if (indexes[*it] < lru){
						lru = indexes[*it];
						val = *it;
					}
				}
				s.erase(val);
				s.insert(pages[i]);
				page_faults++;
			}
			indexes[pages[i]] = i;
		}		
	}
	return page_faults;
}

int main()
{
	int pages[] = {};
	int n = sizeof(pages)/sizeof(pages[0]);
	int capacity = 4;
	cout << pageFaults(pages, n, capacity);
	return 0;
}