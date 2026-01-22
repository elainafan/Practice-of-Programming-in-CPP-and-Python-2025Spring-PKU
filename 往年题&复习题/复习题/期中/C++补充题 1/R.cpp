#include <iostream>
#include <list>
#include <map>
#include <string>

using namespace std;
void Print(list<int> x) {
    for (auto i = x.begin(); i != x.end(); i++) {
        cout << *i << ' ';
    }
    cout << endl;
}
template <class T>
void QueryResult(T x, T y) {
    for (T i = x; i != y; i++) {
        cout << i->first << ": ";
        Print(i->second);
    }
}
// 在此处补充你的代码
int main(int argc, char* argv[]) {
    map<int, list<int> > Attendance;
    map<int, list<int> >::iterator it;
    string cmd;
    int date, id, date_lower, date_upper;
    while (cin >> cmd) {
        if (cmd == "add") {
            cin >> date >> id;
            it = Attendance.find(date);
            if (it != Attendance.end()) {
                it->second.push_back(id);
            } else {
                list<int> lst_id;
                lst_id.push_back(id);
                Attendance.insert(make_pair(date, lst_id));
            }
        } else if (cmd == "query") {
            cin >> date_lower >> date_upper;
            QueryResult(Attendance.lower_bound(date_lower), Attendance.upper_bound(date_upper));
        } else if (cmd == "exit") {
            system("pause");
            return 0;
        }
    }
    system("pause");
    return 0;
}