#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxContenedores(vector<int>& arr, int peso){
	sort(arr.begin(),arr.end());
	int maxCounter = 0; 
	for(vector<int>::iterator it = arr.begin(); it != arr.end();it++ ){
		int temp = peso - (*it); 
		if(temp < 0){
			return maxCounter;
		}else{
			maxCounter++;
			peso = temp;
		}
	}
	return maxCounter;
}

bool f(int a,int b){return a > b;}
	
int maxTon(vector<int>& arr, int peso){
	sort(arr.begin(),arr.end(), f);
	int maxCounter = 0; 
	for(vector<int>::iterator it = arr.begin(); it != arr.end();it++ ){
		int temp = peso - (*it); 
		if(temp >= 0){
			maxCounter+= *it;
			peso = temp;
		}
	}
	return maxCounter;
}


	
int main(int argc, char *argv[]) {
	int k;
	cin >> k;
	vector<int> pesos = {1,2,3,4,5,6};
	cout << "La cantidad maxima de contenedores es: "<< maxContenedores(pesos, k) << endl;
	cout << "La cantidad maxima de toneladas es: "<< maxTon(pesos, k) << endl;
	return 0;
}

