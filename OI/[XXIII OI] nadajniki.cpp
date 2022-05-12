#include<iostream>
#include<queue>
#include<list>

using namespace std;
const int M = 200005;

struct vertex{
    vector<vertex*>sons;
    vertex *father;
    bool isVar;
    int trCount, sigCount, sigReq;

    vertex(){
        father = nullptr;
        isVar = true;
        trCount = sigCount = 0;
        sigReq = 1;
    }

    int variableSons(){
        int res = 0;
        for(auto v : sons){
            if(v->trCount > 0 && v->isVar){
                res++;
            }
        }
        return res;
    }

    int sonsInNeed(){
        int res = 0;
        for(auto v : sons){
            if(v->trCount == 0 && v->sigReq > v->sigCount){
                res++;
            }
        }
        return res;
    }

    bool EverySonHasTwoSignals(){
        for(auto v : sons){
            if(v->sigCount < 2){
                return false;
            }
        }
        return true;
    }

    void SetSingleTransmitter(bool state){
        isVar = state;
        trCount = 1;
        father->sigCount++;
    }

    void ReduceToDoubleTransmitter(){
        for(auto &v : sons){
            if(v->trCount > 0 && v->isVar){
                v->trCount = 0;
            }
        }
        trCount = 2;
        isVar = false;
        father->sigCount += 2;
    }
}Graph[M];

bool vis[M];
queue<int>Q;
vector<int>inputGraph[M];
list<vertex*>S;

void createRootedTree(){
    Graph[1].father = &Graph[0];
    Q.push(1);
    S.push_front(&Graph[1]);
    vis[1] = true;

    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int u : inputGraph[v]){
            if(!vis[u] && inputGraph[u].size() > 1){
                vis[u] = true;
                Q.push(u);
                vertex *t = &Graph[u];
                t->father = &Graph[v];
                Graph[v].sons.push_back(t);
                S.push_front(t);
            }else{
                if(inputGraph[u].size() == 1){
                    Graph[v].sigReq = 2;
                }
            }
        }
    }
}

void setTheTransmitters(){
    for(auto& current : S){
        int variableSons = current->variableSons();
        int sonsInNeed = current->sonsInNeed();

        if(current->sigReq == 2 && current->sigCount == 0){
            current->SetSingleTransmitter(sonsInNeed > 0 ? false : true);
        }else{
            if(current->sigReq == 2){
                if(variableSons > 1 || (variableSons == 1 && sonsInNeed > 0)){
                    current->ReduceToDoubleTransmitter();
                }else{
                    if(sonsInNeed>0){
                        current->SetSingleTransmitter(false);
                    }
                }
            }else{
                if(current->sigReq == 1 && current->sigCount == 0){
                    if(current->EverySonHasTwoSignals()){
                        current->father->sigReq = 2;
                        current->sigCount = 1;
                    }else{
                        if(sonsInNeed > 0){
                            current->SetSingleTransmitter(false);
                        }
                    }
                }else{
                    if(variableSons > 1 || (variableSons == 1 && sonsInNeed > 0)){
                        current->ReduceToDoubleTransmitter();
                    }else{
                        if(sonsInNeed > 0){
                            current->SetSingleTransmitter(false);
                        }
                    }
                }
            }
        }
    }
    if(Graph[1].trCount == 0 && Graph[1].sigReq > Graph[1].sigCount){
        Graph[1].SetSingleTransmitter(false);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    int n, a, b, res = 0;

    cin>>n;

    if(n == 1){
        cout << 0;
        return 0;
    }

    for(int i = 1;i < n;i++){
        cin >> a >> b;
        inputGraph[a].push_back(b);
        inputGraph[b].push_back(a);
    }

    createRootedTree();
    setTheTransmitters();

    for(int i =1;i <= n;i++){
        res += Graph[i].trCount;
    }

    cout << res;
    return 0;
}

