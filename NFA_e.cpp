#include <bits/stdc++.h>
#define author armag-pro
using namespace std;

const int N=100;
int n, m;
vector<int> nt[N][N], nt1[N][N];
set<int> closure[N];

void non_eps() {
	 cout << "\nNFA khong co dich chuyen epsilon:\n";
	 cout << "==================================\n";
	 cout << "Q\t\tNhan chuyen\n";

		for(int i=0; i<n; i++) {
			cout << "Q" << i << "\t";
			for(int j=1; j<=m; j++) {
				cout << "{";
				for(int ii: nt1[i][j]) 
					cout << ii << " ";
				cout << "}\t";
			}
			cout << endl;
		}
		cout << endl;
}

int main() {

    cout << "So trang thai: ";
    cin >> n;
    cout << "So nhan chuyen: ";
    cin >> m;
    cout << "Nhap bang trang thai:\n\n";

    // Bang trang thai
    for(int i=0; i<n; i++) {
        cout << "Trang thai " << i << endl;
    	for(int j=0; j<=m; j++) {

    		cout << "\tSo trang thai chuyen tren nhan ";
    		if(j == 0) cout << "epsilon";
    		else cout << char(j + 'a' - 1);
    		cout << ": ";
    		int temp; cin >> temp;
    		nt[i][j].resize(temp);
            if(temp == 0) {
                
            } else if(temp == 1) {
                cout << "\tNhap trang thai: ";
            } else {
                cout << "\tNhap " << temp << " trang thai: ";
            }
    		for(int k=0; k<nt[i][j].size(); k++) {
    			cin >> nt[i][j][k];
    		}
    	}
        cout << endl;
    }
    cout<<"===========\n";
    for(int i=0; i<n; i++)
    	for(int j=0; j<=m; j++)
    		for(int k=0; k<nt[i][j].size(); k++) {
    			cout << nt[i][j][k];
  	  		}

    // Tim epsilon closure cho tung trang thai
    for(int i=0; i<n; i++) {
    	queue<int> q;
    	vector<bool> vis(n, false);
    	q.push(i); vis[i] = 1;
    	while(!q.empty()) {
    		int top = q.front(); q.pop();
    		for(int k=0; k<nt[top][0].size(); k++) {
    			int cur = nt[top][0][k];
    			if(vis[cur] == 0) {
    				vis[cur] = 1;
    				q.push(cur);
    			}
    		}
    	}
    	for(int j=0; j<n; j++) {
    		if(vis[j] == 1) closure[i].insert(j);
    	}
    }

    // Tim epsilon* --> Nhan chuyen --> epsilon* cho tung trang thai và nhan chuyen
    for(int i=0; i<n; i++) {
    	for(int ii: closure[i]) {
    		for(int j=1; j<=m; j++) {
    			for(int k=0; k<nt[ii][j].size(); k++) {
    				int cur = nt[ii][j][k];
    				for(int iii: closure[cur]) {
    					nt1[i][j].push_back(iii);
    				}
    			}
    		}
    	}
    }
    
	// tra ve NFA non_epsilon 
    non_eps();

    return 0; 
} 


