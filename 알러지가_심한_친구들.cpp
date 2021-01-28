#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

vector<string> eater;
bool check[50] ={false,};
int canEater[50][50];

const int INF = 987654321;
int N, M;
bool checkCheck(){
    for(int i = 0 ; i < N ; i++){
        if(check[i] == false) return false;
    }
    return true;
}
bool canEverybodyEat(vector<int>& menu){
    for(int i = 0 ; i < menu.size(); i++){
        int tempNum = menu[i];
        for(int j = 0 ; j < N ; j++){
            if(canEater[j][tempNum] == 1) check[j] = true;
        }
    }
    bool result = checkCheck();
    memset(check, false, 50);
    return result;
    
    
}
int selectMenu(vector<int>& menu, int food){
    if(food == M){
        if(canEverybodyEat(menu)) return menu.size();
        return INF;
    }

    int ret = selectMenu(menu, food + 1);
    menu.push_back(food);
    ret = min(ret, selectMenu(menu, food + 1));
    menu.pop_back();
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    int testcase;
    cin >> testcase;

    string eaterTemp;
    int tempNum;
    string canEaterTemp;
    vector<int> menu;

    for(int i = 0 ; i < testcase ; i++){
        cin >> N >> M;
        for(int j = 0 ; j < N ; j++){
            cin >> eaterTemp;
            eater.push_back(eaterTemp);
        }
        for(int j = 0 ; j < M ; j++){
            cin >> tempNum;
            for(int k = 0 ; k < tempNum ; k++){
                cin >> canEaterTemp;
                for(int f = 0 ; f < N ; f++){
                    if(eater[f] == canEaterTemp){
                        canEater[f][j] = 1;
                    }
                }
            }
        }
        cout << selectMenu(menu, 0) << "\n";
    }

    
}