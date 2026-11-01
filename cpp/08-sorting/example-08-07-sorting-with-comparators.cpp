// Fall in Love With DSA, Example 8.7: Sorting with comparators

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
    string name;
    int marks;
};

int main() {
    vector<int> v = {5, 2, 8, 1, 3};
    sort(v.begin(), v.end(), greater<int>());
    for (int x : v) cout << x << " ";
    cout << endl;

    vector<Student> s = {{"Ravi", 85}, {"Anil", 92},
                         {"Sita", 85}, {"Kiran", 70}};
    // higher marks first; equal marks by name
    sort(s.begin(), s.end(),
         [](const Student& a, const Student& b) {
             if (a.marks != b.marks)
                 return a.marks > b.marks;
             return a.name < b.name;
         });
    for (auto& st : s) {
        cout << st.name << " " << st.marks << endl;
    }
    return 0;
}
