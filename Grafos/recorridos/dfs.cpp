#include <bits/stdc++.h> 
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
using namespace std; 

int dfs(int nodoActual) {
    if(!visitados[nodoActual]) {
        for(int i=0;i<grafo[nodoActual].size();i++) {
            int nodoAVisitar = grafo[nodoActual][i];  // grafo[0][1] = 1 grafo[3][2] =4 
            if(!visitados[nodoAVisitar]) {
                visitados[nodoAVisitar] = true;
                dfs(nodoAVisitar);
            }
        }
    }
}




int main() 
{ 
    input; 
    int nodos,aristas; 
    cin>>nodos>>aristas;
    vector<int> grafo[nodos+1];
    // List<integer> grafo = new List<Integer>[nodos];

    for(int i=0;i<aristas;i++) {
        int a,b;
        cin>>a>>b;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
   
   //Mostrar el grafo
    
    for(int i=1;i<=nodos;i++) {
        cout<<"{"<<(i)<<"}=>";
        for(int j=0;j<grafo[i].size();j++) {
            cout<<"["<<grafo[i][j]<<"]";
        }
        cout<<endl;
    }

    //Recorrido por DFS

    vector<bool> visitados(nodos);
    stack<int> pilita;
    visitados[1] = true; // empezando desde ricardo 1 pero el vector empieza en 0 por lo cual vamos a restar 1 
    pilita.push(1); // agregamos el primer nodo y restamos 1 por que empieza en 0 
    while(!pilita.empty()){
        int nodoActual = pilita.top();
        pilita.pop(); 
        for(int i=0;i<grafo[nodoActual].size();i++) {
            int nodoAVisitar = grafo[nodoActual][i];  // grafo[0][1] = 1 grafo[3][2] =4 
            if(!visitados[nodoAVisitar]) {
                pilita.push(nodoAVisitar);
                visitados[nodoAVisitar] = true;
            }
        }
    }

    for(int i = 0 ; i<= nodos; i++  ) {
        cout<<"[" << visitados[i] <<"]" ;
    }

    if(visitados[7]){
        cout<<"el amor existe"<<endl;
    } 
    else{
        cout<<"no la conocio :( "<<endl;
    }



    return 0; 
} 