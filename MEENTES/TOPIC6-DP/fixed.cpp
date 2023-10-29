//http://vanb.org/ser2012/unhappy.cpp
#include <bits/stdc++.h>
#define K 1600
#define DBG 0
using namespace std;

vector<long long int> DP[10][20];

int sumDigitsSq(long long int num) {
  int sum = 0;
  while(num > 0) {
    sum += (num%10)*(num%10);
    num /= 10;
  }
  return sum;
}

bool setHappy(vector<bool>& happy, vector<bool>& seen, int num) {
  if (!seen[num]) {
    seen[num] = true;
    happy[num] = setHappy(happy, seen, sumDigitsSq(num));
  }
  return happy[num];
}

int numDigits(long long int num) {
  int count = 1;
  while (num >= 10) {
    num /= 10;
    count++;
  }
  return count;
}

void print(vector<long long int>& ar) {
  if (DBG) cout << "[";
  for (int i = 0; i < 100; i++) {
    if (DBG) cout << ar[i] << ",";
  }
  if (DBG) cout << "]";
}

void findNumSums(long long int num, vector<long long int>& answer) {
  answer.assign(K, 0);
  int numD = numDigits(num);
  long long int acc = 1;
  for (int i = 0; i < numD - 1; i++) {
    acc *= 10;
  }

  int MSB = (int)(num / acc);
  for (int i = 0; i < MSB; i++) {
    for (int n = 0; n < K; n++) {
      answer[n] += DP[i][numD][n];
    }
  }

  if (DBG) cout << "A" << num << ": ";
  print(answer);
  if (DBG) cout << endl;

  vector<long long int> recur;
  if (num < 10) {
    for (int n = 0; n < K; n++) {
      answer[n] += DP[MSB][1][n];
    }
  } else {
    findNumSums(num%(acc*MSB), recur);
    if (DBG) cout << "B" << num << ": ";
    print(recur);
    if (DBG) cout << endl;
    for (int n = 0; n < K; n++) {
      answer[n + (MSB*MSB)] += recur[n];
    }
  }

}

int main() {
  vector<bool> happy(K, false);
  vector<bool> seen(K, false);
  happy[0] = false; seen[0] = true;
  happy[1] = true; seen[1] = true;
  for (int i = 2; i < K; i++) {
    setHappy(happy, seen, i);
  }

  for (int i = 0; i < 10; i++) {
    DP[i][1].assign(K, 0);
    DP[i][1][i*i] = 1;
  }

  for (int j = 2; j < 20; j++) {
    for (int i = 0; i < 10; i++) {
      DP[i][j].assign(K, 0);
      for (int k = 0; k < 10; k++) {
        for (int n = 0; n < K; n++) {
            //assert(n+i*i<DP[i][j].size());
            /*if(n+i*i>=DP[i][j].size()){
                cout<<"ESTE ES n+i*i: "<<n+i*i<<" "<<DP[i][j].size()<<"\n";
            }*/
            //cout<<"intentare entrar a:"<<n+i*i<<"\n";
            if(n+i*i<DP[i][j].size()){
                DP[i][j][n + (i*i)] += DP[k][j-1][n];
            }

        }
      }
    }
  }



  long long int L, H;
    cin>>L>>H;

    vector<long long int> Lv, Hv;
    findNumSums(L-1, Lv);
    findNumSums(H, Hv);
    long long int cont = 0;
    for (int n = 0; n < K; n++) {
      cont += (happy[n] ? 0 : Hv[n] - Lv[n]);
    }
    cout << H-L+1-cont << endl;

}
