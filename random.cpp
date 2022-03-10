#include <bits/stdc++.h>
using namespace std;

typedef int long long;

struct demon {
    int Sc, Tr, Sr, Na;
    vector<int> fragments;
};

const int N = 5e5+3;
struct demon demons[N];

bool cmpdems(int &i, int &j) {
    return demons[i].Sr - demons[i].Sc - demons[i].Tr > demons[j].Sr - demons[j].Sc - demons[j].Tr;
}

int main() {
    int S, Smax, T, D;
    cin >> S >> Smax >> T >> D;
    // vector<demon> demons(D);
    for(int i = 0; i < D; i++) {
        cin >> demons[i].Sc >> demons[i].Tr >> demons[i].Sr >> demons[i].Na;
        for(int j = 0; j < demons[i].Na; j++) {
            int f;
            cin >> f;
            demons[i].fragments.push_back(f);
        }
    }

    vector<int> perm(D);
    for(int i = 0; i < D; i++) {
        perm[i] = i;
    }

    sort(perm.begin(), perm.end(), cmpdems);
    ofstream myfile;
    myfile.open ("output4.txt", ios::out | ios::trunc);
    for(int i = 0; i < D; i++) {
        myfile << perm[i] << '\n';
    }
    cout << "First Printing done!\n"; 

    auto rng = std::default_random_engine {};
    int best = 0;
    do {
        // shuffle(begin(perm), end(perm), rng);
        int score = 0;
        vector<int> start(D, -1);
        vector<int> staminas(T, 0);
        int curr_stamina = S;
        int curr = 0;
        for(int i = 0; i < T; i++) {
            curr_stamina += staminas[i];
            curr_stamina = min(curr_stamina, Smax);
            if(curr_stamina >= demons[perm[curr]].Sc) {
                start[perm[curr]] = i;
                curr_stamina -= demons[perm[curr]].Sc;
                if(i + demons[perm[curr]].Tr < T) {
                    staminas[i + demons[perm[curr]].Tr] += demons[perm[curr]].Sr;
                    staminas[i + demons[perm[curr]].Tr] = min(staminas[i + demons[perm[curr]].Tr], Smax);
                }
                curr++;
            }
        }
        for(int i = 0; i < D; i++) {
            if(start[i] != -1) {
                for(int j = 0; j < min(demons[i].Na, T - start[i]); j++) {
                    score += demons[i].fragments[j];
                }
            }
        }
        if(score > best) {
            best = score;
            ofstream myfile;
            myfile.open ("output3.txt", ios::out | ios::trunc);
            for(int i = 0; i < D; i++) {
                myfile << perm[i] << '\n';
            }
            cout << "Score: " << best << '\n';
        }
    } while(next_permutation(begin(perm), end(perm)));
}