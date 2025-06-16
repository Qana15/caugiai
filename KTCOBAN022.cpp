#include<iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    if(t>0&&t<1000){
      while(t--){
       int x, y, m;
       cin >> x >> y >> m;
       if(x>0&&x<100000000&&y>0&&y<100000000&&m>0&&m<100000000){
       int hop=m/x;
       int doi=hop/y;
       int du=hop%y;
       int conlai=doi+du;
       hop=hop+doi;
       while(conlai>=y){
        doi=conlai/y;
        du=conlai%y;
        conlai=doi+du;
        hop=hop+doi;
       }
       cout << hop << endl;
    }
    }
    }
}
