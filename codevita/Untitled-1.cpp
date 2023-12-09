#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

map<string, int> calculateBalance(const vector<string>& expenses, const vector<string>& transactions) {
    map<string, int> balance;

    for (const string& expense : expenses) {
        char paidBy;
        int amount;
        vector<string> participants;
        stringstream ss(expense);
        ss >> paidBy >> amount;

        string participant;
        while (ss >> participant) {
            participants.push_back(participant);
        }

        int splitAmount = amount / participants.size();

        for (const string& person : participants) {
            balance[person] += splitAmount;
        }
    }

    for (const string& transaction : transactions) {
        char transactionType, payer;
        int amount;
        stringstream ss(transaction);
        ss >> transactionType >> payer >> amount;

        if (transactionType == 'L') {
            balance[to_string(payer)] -= amount;
        } else {
            string payee;
            ss >> payee;
            balance[to_string(payer)] -= amount;
            balance[to_string(payer)] += amount;
        }
    }

    return balance;
}

vector<tuple<string, string, int>> reconcile(const map<string, int>& balance) {
    vector<tuple<string, string, int>> reconciliation;

    for (const auto& entry : balance) {
        const string& person = entry.first;
        int amount = entry.second;

        if (amount > 0) {
            for (const auto& otherEntry : balance) {
                const string& otherPerson = otherEntry.first;
                int otherAmount = otherEntry.second;

                if (otherAmount < 0) {
                    int settleAmount = min(abs(amount), abs(otherAmount));
                    reconciliation.push_back(make_tuple(person, otherPerson, settleAmount));
                    amount += settleAmount;
                    otherAmount += settleAmount;
                }
            }
        }
    }

    return reconciliation;
}

int main() {
    int N;
    cin >> N;

    vector<string> expenses;
    vector<string> transactions;

    cin.ignore();  // Consume the newline character after N
    for (int i = 0; i < N; ++i) {
        string entry;
        getline(cin, entry);

        if (entry[1] == 'L') {
            transactions.push_back(entry);
        } else {
            expenses.push_back(entry);
        }
    }
map<string, int> balance = calculateBalance(expenses, transactions);
    vector<tuple<string, string, int>> reconciliation = reconcile(balance);

    if (reconciliation.empty()) {
        cout << "NO DUES." << endl;
    } else {
        for (const auto& entry : reconciliation) {
            cout << get<0>(entry) << '/' << get<1>(entry) << '/' << get<2>(entry) << endl;
        }
    }

    return 0;
}
