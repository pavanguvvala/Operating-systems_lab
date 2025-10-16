// To simulate file allocation strategies: (a) Sequential, (b) Indexed, (c) Linked

// program (a)
#include <iostream>
#include <vector>
using namespace std; 
int main() { 
	int n, f, start, length; 
	cout << "Enter total number of disk blocks: "; 
	cin >> n;
vector<int> block(n, 0); // 0 = free, 1 = allocated
cout << "Enter number of files: ";
cin >> f; 
for (int i = 0; i < f; i++) {
cout << "\nEnter starting block of file " << i+1 << ": ";
cin >> start;
cout << "Enter length of file " << i+1 << ": ";
		cin >> length; 
	bool allocated = true; 
		for (int j = start; j < start + length; j++) { 
			if (j >= n || block[j] == 1) { 
					allocated = false; 
				break; 
			} 
		} 
		if (allocated) { 
		for (int j = start; j < start + length; j++) 
				block[j] = 1; 
			cout << "File " << i+1 << " allocated blocks: "; 
			for (int j = start; j < start + length; j++) 
					cout << j << " "; 
			cout << endl; 
		} else { 
			cout << "File " << i+1 << " cannot be allocated." << endl; 
		} 
}

// program (b)

#include <iostream>
#include <vector>
using namespace std; 
int main() { 
	int n, f, indexBlock, length; 
	cout << "Enter total number of disk blocks: "; 
	cin >> n; 
	vector<int> block(n, 0);
cout << "Enter number of files: ";
cin >> f; 
for (int i = 0; i < f; i++) {
cout << "\nEnter index block for file " << i+1 << ": ";
cin >> indexBlock; 
if (block[indexBlock] == 1) { 
	cout << "Index block already allocated. File cannot be stored.\n";
continue;
} 
block[indexBlock] = 1;
cout << "Enter number of blocks needed for file " << i+1 << ": ";
cin >> length; 
vector<int> allocated; 
cout << "Enter block numbers: "; 
for (int j = 0; j < length; j++) { 
	int b; 
	cin >> b; 
	if (b < n && block[b] == 0) { 
		block[b] = 1; 
			allocated.push_back(b); 
	} else { 
			cout << "Block " << b << " already allocated or invalid.\n";
} 
		} 
		cout << "File " << i+1 << " stored using index block " 
				<< indexBlock << " -> "; 
		for (int b : allocated) cout << b << " "; 
		cout << endl; 
	} 
	return 0; 
} 

// program (c)

#include <iostream>
#include <vector>
using namespace std; 
struct Node { 
	int block; 
	Node* next; 
}; 
int main() { 
	int n, f, length; 
	cout << "Enter total number of disk blocks: "; 
	cin >> n; 
	vector<int> block(n, 0);
cout << "Enter number of files: ";
cin >> f; 
for (int i = 0; i < f; i++) {
cout << "\nEnter number of blocks required for file " << i+1 << ": ";
cin >> length; 
Node* head = nullptr; 
Node* temp = nullptr; 
cout << "Enter block numbers: "; 
for (int j = 0; j < length; j++) { 
	int b; 
	cin >> b; 
	if (b < n && block[b] == 0) { 		block[b] = 1;
Node* newNode = new Node{b, nullptr}; 
			if (!head) head = newNode; 
			else temp->next = newNode; 
			temp = newNode; 
	} else { 
			cout << "Block " << b << " already allocated or invalid.\n"; 
	} 
} 
cout << "File " << i+1 << " allocated blocks (linked): "; 
temp = head; 
while (temp) { 
	cout << temp->block << " -> ";
			temp = temp->next; 		} 
		cout << "NULL" << endl; 	} 
	return 0; }
