/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

class data{
private:
    int x;
    static int assignment_count;
    static int n;
public:

    friend ostream& operator<<(ostream &os, const data& a);
    friend istream& operator>>(istream &os, data& a)    ;
    static void set_n(int n){
        if (data::n == 0) data::n = n;
        else cout << "WRONG";
    }
    data& operator=(const data& a){
        assignment_count++;
        if (assignment_count > 3* data::n){
            cout << "WRONG";
        }
        this->x = a.x;
        return *this;
    }

    bool operator<(const data& a){
        return this->x < a.x;
    }
};
int data::assignment_count = 0;
int data::n = 0;

ostream& operator<<(ostream &os, const data& a){
    return os << a.x;
}
istream& operator>>(istream &os, data& a){
    return os >> a.x;
}



//###INSERT CODE HERE -
void select_sort(data *&s, int n) {
//BTW, This is shellSort
  data temp;
  int j = 0;
  for (int gap = n/2; gap > 0; gap /= 2) {
    for (int i = gap; i < n; i++) {
      temp = s[i];
      for (j = i; j >= gap && temp < s[j - gap]; j -= gap) {
        s[j] = s[j - gap];
      }
      s[j] = temp;
    }
  }
}


int main(){
    int n;
    cin >> n;
    data::set_n(n);

    data *A = new data[n];
    for (int i = 0; i < n; i++){
        cin >> A[i];
    }


    for(int i = 0; i < n; i++){
        cout << A[i] << " " ;
    }
}
