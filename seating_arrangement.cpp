#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <cmath>
using namespace std;

int pax_per_group;
int n, e, u, v, rating,total_rating, permutation= 0;
double weight;
double adjmat[200][200];

int group[200];	//groups from 1 to n/pax_per_group
int ideal[200]; //Ideal group thus far
double score, max_score=0;

vector<pair<int,int>> friends;
int main(){
	ifstream in("input.in");
	in >> n >> pax_per_group;
	for (int i=0;i<n;i++){
		friends.clear();
		total_rating = 0;
		in >> u >> e;
		
		for (int j=0;j<e;j++){
			in >> v >> rating;
			friends.push_back(make_pair(v,rating));
			total_rating += rating;
		}
		
		weight = 1.0/double(total_rating);
		for (auto f: friends){
			adjmat[u][f.first] = weight*f.second;
		}
		
	}
	
	for (int i=0; i< n;i++)group[i] = i/pax_per_group + 1; //initialise the group array
	copy(group, group+n, ideal);
	
	do{
		permutation++;
		score = 0;
		for (int i=0;i<n;i++){
			for (int j=0;j<n;j++){
				if (i == j)continue;
				if(group[j] == group[i])score += adjmat[i][j];
			}
		}
		
		if (score > max_score){
			max_score = score;
			copy(group, group+n, ideal);
		}
	}while(next_permutation(group, group+n));
	
	ofstream out("output.out");
	cout <<endl <<  "**Completed Calculations**" << endl;
	cout << "Total Permutations: " <<permutation<<endl;
	cout << "Total score: " << max_score << endl;
	cout << "Ideal Permutation" << endl << "  Person: ";
	for (int i=0;i<n;i++)cout << i << " ";
	cout <<endl << "  Group : ";  
	for (int i=0;i<n;i++)cout << ideal[i] << " ";
	cout << endl <<endl;
	
	for (int i=1; i<=ceil(double(n)/double(pax_per_group)); i++){
		out << "-" << i << endl;
		for (int j=0;j<n;j++)if (ideal[j] == i)out << j << endl;
	}
	
		
	
}


/*Input Format

n
u e {v rating}*e //n lines

e.g.
6
0 0
1 0
2 1 1 1
3 1 0 1
4 2 1 2 2 1
5 1 1 1
*/
	
	
	
	
	
	
	
