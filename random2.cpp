#include <bits/stdc++.h>
using namespace std;

typedef int long long;

struct demon {
    int Sc, Tr, Sr, Na;
    vector<int> fragments;
};

const int N = 5e5+3;
struct demon demons[N];
double psum[N];

double w1, w2, w3, w4;

bool cmpdems(int &i, int &j) {
    double num1 = w1*demons[i].Sr + w2*demons[i].Sc + w3*demons[i].Tr + w4*psum[i];
    double num2 = w1*demons[j].Sr + w2*demons[j].Sc + w3*demons[j].Tr + w4*psum[j];
    return num1 > num2;
}

int main() {
    int S, Smax, T, D;
    cin >> S >> Smax >> T >> D;
    // vector<demon> demons(D);
    for(int i = 0; i < D; i++) {
        psum[i] = 0;
        cin >> demons[i].Sc >> demons[i].Tr >> demons[i].Sr >> demons[i].Na;
        for(int j = 0; j < demons[i].Na; j++) {
            int f;
            cin >> f;
            demons[i].fragments.push_back(f);
            psum[i] += f;
        }
    }

    vector<int> perm(D);
    for(int i = 0; i < D; i++) {
        perm[i] = i;
    }

    random_device rd;
    mt19937 gen(rd());
    normal_distribution<double> d1(2, 4);
    normal_distribution<double> d2(-2, 4);
    normal_distribution<double> d3(-1, 4);
    normal_distribution<double> d4(0.01, 0.03);

    int best = 0;
    while(true) {
        w1 = d1(gen); w2 = d2(gen); w3 = d3(gen); w4 = d4(gen);
        // cout << w1 << " " << w2 << " " << w3 << " " << w4 << '\n';
        sort(perm.begin(), perm.end(), cmpdems);
        int score = 0;
        vector<int> start(D, -1);
        vector<int> staminas(T, 0);
        int curr_stamina = S;
        int curr = 0;
        for(int i = 0; i < T; i++) {
            if(curr >= D) {
                break;
            }
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
        // cout << score << "\n";
        if(score > best) {
            best = score;
            ofstream myfile;
            myfile.open ("output5.txt", ios::out | ios::trunc);
            for(int i = 0; i < D; i++) {
                myfile << perm[i] << '\n';
            }
            cout << "Score: " << best << '\n';
            cout << w1 << " " << w2 << " " << w3 << " " << w4 << '\n';
        }
    }
}