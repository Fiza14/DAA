#include<iostream>
#include <iomanip>
#include <string>
#include<bits/stdc++.h>

using namespace std;

#define MAX 10
#define V 4

class TSP {

    public:

        int cityMatrix[V][V], traversed_path[V+1];
        int Cities, min_path, Minimum_Cost;
        vector<int> vertex; // store all vertices except start start vertex
        map<int, string> path_cost_map; // Hashmap for cost and path
        string path_str="";

        TSP() {
            cout<<"\nEnter the number of Cities : ";
            cin >> Cities; cout<<"\n";
            for (int i=0;i<Cities;i++) {
                for (int j=0;j<Cities;j++) {
                        if (i==j){
                            cityMatrix[i][j] = 0;
                            continue;
                        }
                    cout<<"Path from "<<i+1<<" to "<<j+1<<"  -----> ";
                    cin>>cityMatrix[i][j];
                }
            }
            cout<<"\n___________________________________________________________________________";
            printCityMatrix();
        }

        void printCityMatrix() {
            cout<<"\n\nCity Matrix ----> \n\n"<<"       ";
            for (int i=0;i<Cities;i++)
                cout<<i+1<<right<<setw(5);
            cout<<endl;
            for (int i=0;i<Cities;i++) {
                cout<<"\n   "<<i+1<<"   ";
                for (int j=0;j<Cities;j++) {
                    cout<< left<< setw(5)<< cityMatrix[i][j];
                }
            }
            cout<<endl<<endl;
        }


        int SolveTSP (int graph[][V], int s) {

            min_path = INT_MAX;

            for (int i = 0; i < V; i++)
                if (i != s)
                    vertex.push_back(i);

            do {
                stringstream ss;
                path_str="";
                cout<<"___________________________________________________________________________\n";
                cout<<"\n  Traversing for Cities ====>  "<<s+1;
                traversed_path[0] = s;
                ss << s+1;
                path_str += "--->"+ss.str();

                for (int i=0; i<vertex.size(); i++){
                    traversed_path[i+1] = vertex[i];
                    ss << traversed_path[i+1]+1;
                    path_str += ss.str();
                    cout<<" ---> "<<traversed_path[i+1]+1;
                    if (i==vertex.size()-1) {
                        traversed_path[i+2] = vertex[i+1];
                        ss << traversed_path[i+2]+1;
                        path_str = ss.str();
                        cout<<" ---> "<<traversed_path[i+2]+1;
                    }
                }

                // store current Path weight(cost)
                int current_pathweight = 0;
                // compute current path weight
                int k = s;

                for (int i = 0; i < vertex.size(); i++) {

                    current_pathweight += graph[k][vertex[i]];
                    cout<<"\n  Cost ("<<k+1<<" ---> "<<vertex[i]+1<<")  =  " <<graph[k][vertex[i]];
                    k = vertex[i];

                    if (i==vertex.size()-1) {
                        current_pathweight += graph[k][s];
                        cout<<"\n  Cost ("<<k+1<<" ---> "<<s+1<<")  =  " <<graph[k][s]<<endl;
                    }
                }
                cout<<"  Total Cost for the path = "<<current_pathweight<<endl;
                // update minimum cost
                min_path = min(min_path, current_pathweight);

                path_cost_map.insert(pair<int, string>(current_pathweight, path_str));

            } while (
                next_permutation(vertex.begin(), vertex.end()));
                // keep on traversing for the permutations of the cities

            return min_path;
    }

};
int main() {

    TSP T1;
    int start_vertex = 0;

    T1.Minimum_Cost = T1.SolveTSP(T1.cityMatrix, start_vertex);
    cout<<"\n___________________________________________________________________________";
    cout<<"\n\n  Minimum cost Path ====> "<<T1.path_cost_map[T1.min_path][0];
    for(int i=1; i<T1.vertex.size()+2; i++)
        cout<<" ---> "<<T1.path_cost_map[T1.min_path][i];

    cout << "\n\n  The Minimum_Cost for travelling all Cities  ------>  " <<T1.Minimum_Cost << endl<<endl;
    return 0;
}
