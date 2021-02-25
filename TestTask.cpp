#include <iostream>
#include <vector>
#include <algorithm>

const size_t MAX_ARRAY_SIZE = 10000;

std::vector<std::vector<int>> genArr(size_t n){
	srand(time(NULL));
	size_t i, j, sizeOfVec;
	std::vector<std::vector<int>> vecOfVecs(n);
	bool collision;
	for(i = 0; i < n; i++){
		collision = 1;
		while (collision){
			sizeOfVec = rand() % MAX_ARRAY_SIZE;
			collision = 0;
			for (j = 0; j < i; j++){
				if (vecOfVecs[j].size() == sizeOfVec){
					collision = 1;
					break;
				}
			}
		}
		for (j = 0; j < sizeOfVec; j++){
			vecOfVecs[i].push_back(rand());
		}
		if (i % 2){
			std::sort(vecOfVecs[i].begin(), vecOfVecs[i].end(), std::greater<int>());
		}
		else{
			std::sort(vecOfVecs[i].begin(), vecOfVecs[i].end());
		}
	}
	return vecOfVecs;
}

int main(){
	size_t n, i, j;
	std::cin>>n;
	std::vector<std::vector<int>> v = genArr(n);
	for (i = 0; i < n; i++){
		for (j = 0; j < v[i].size(); j++){
			std::cout<<v[i][j] / 100000<<" ";
		}
		std::cout<<std::endl;
	}
    return 0;
}
