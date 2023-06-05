#include <iostream>
#include <stdio.h>

using namespace std;
//double minMax(int n, int * arr) {
//	double min, arrMax, indexMax, indexMin;
//	min = arr[0];
//	indexMin = 0;
//	arrMax = arr[0];
//	indexMax = 0;
//	for (int i = 0; i < n; i++) {
//		if(arr[i] < min){
//			min = arr[i];
//			indexMin = i;
//		}else if (arr[i] > arrMax) {
//			arrMax = arr[i];
//			indexMax = i;
//		}
//	}
//	double sum;
//	sum = 0;
//	if (indexMin < indexMax) {
//		for (int k = indexMin + 1; k < indexMax; k++){
//			sum += arr[k];
//		}
//	}
//	else {
//		for (int m = indexMax + 1; m < indexMin; m++) {
//			sum += arr[m];
//		}
//	}
//	int* arrNew;
//	arrNew = new int[n];
//	for (long v = indexMin; v < n; v++){
//		arr[v] = arr[v + 1];
//	}
//	n--;
//	for (long c = indexMax; c < n; c++) {
//		arr[c] = arr[c + 1];
//	}
//	n--;
//	int ogr = n;
//	for(int l = 0; l <= n; l++){
//		arrNew[l] = arr[ogr];
//		ogr--;
//	}
//	for (int j = 0; j <= n; j++){
//		cout << "-" << arrNew[j] << "-" << "\n";
//	}
//	return sum;
//}
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//	int n, sumThree, * arr;
//	double num;
//	sumThree = 1;
//
//	cout << "Введите размерность массива "; cin >> n;
//	arr = new int[n];
//	for (int i = 0 ; i < n; i++) {
//		cin >> num;
//		arr[i] = num;
//		if (arr[i] % 3 == 0) {
//			sumThree *= arr[i];
//		}
//	}
//	cout <<"Произведение кратных трем = "<< sumThree << "\n";
//	cout << "Сумма элементов между минимальным и макисмальным = " << minMax(n, arr);	
//}



//задача 2

//int convert(int a, int p) {
//    int resA = 0;
//    int cnt = 0;
//    while (a > 0) {
//        resA += a % 10 * pow(p, cnt++);
//        a /= 10;
//    }
//    return resA;
//}
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//	int n, temp;
//	int * arr, * arr2;
//	double num;
//	cout << "Введите размерность массива "; cin >> n;
//	arr = new int[n];
//	arr2 = new int[n];
//	for (int k = 0 ; k < n; k++) {
//		cin >> num;
//		arr[k] = num;
//		arr2[k] = convert(num, 5);
//	}
//
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = 0; j < n - i - 1; j++) {
//			if (arr2[j] > arr2[j + 1]) {
//				temp = arr2[j];
//				arr2[j] = arr2[j + 1];
//				arr2[j + 1] = temp;
//			}
//		}
//	}
//	int sumMin = arr2[0] + arr2[1] + arr2[2];
//	int sumMax = arr2[n-1] + arr2[n-2] + arr2[n-3] + arr2[n-4];
//	cout << "Сумма 4 максимальных = " << sumMax << "\n";
//	cout << "Сумма 3 минимальных = " << sumMin;
//}


//Задача 3

bool is_prime(int value) {
	if (value < 2) return false;
	if (value == 2 || value == 3) return true;
	for (int i = 2; i < int(sqrt(value) + 1); i++) {
		if (value % i == 0) return false;
	}
	return true;
}

bool havent_even_digits(int value) {
	while (value != 0) {
		if ((value % 10) % 2 == 0) return false;
		value /= 10;
	}
	return true;
}

int main() {
	setlocale(LC_ALL, "ru");
	int _size;
	cout << "Введите размерность массива: "; cin >> _size;
	int* arr = new int[_size];
	int* len1 = new int[_size + 2] {-1, 0};  
	int* len2 = new int[_size + 2] {-1, 0};
	int* tmp_arr = new int[_size + 2] {-1, 0};
	cout << "Введите массив: ";
	for (int i = 0, j = 0; i < _size; i++) {
		int tmp;
		cin >> tmp;
		arr[i] = tmp;
		if (is_prime(tmp) && havent_even_digits(tmp)) {
			if (tmp_arr[0] == -1) {
				tmp_arr[0] = i;
				tmp_arr[1] = 1;
				tmp_arr[2] = tmp;
				j = 3;
			}
			else {
				tmp_arr[1]++;
				tmp_arr[j] = tmp;
				j++;
			}
		}
		else {
			if (tmp_arr[1] > len1[1]) for (int k = 0; k < tmp_arr[1] + 2; k++) len1[k] = tmp_arr[k];
			tmp_arr[0] = -1;
			tmp_arr[1] = 0;
		}
	}
	tmp_arr[0] = -1;
	tmp_arr[1] = 0;
	for (int i = 0, j = 0; i < _size; i++) {
		int tmp = arr[i];
		if (is_prime(tmp) && havent_even_digits(tmp)) {
			if (i < len1[0] || i > len1[0] + len1[1]) {
				if (tmp_arr[0] == -1) {
					tmp_arr[0] = i;
					tmp_arr[1] = 1;
					tmp_arr[2] = tmp;
					j = 3;
				}
				else {
					tmp_arr[1]++;
					tmp_arr[j] = tmp;
					j++;
				}
			}
		}
		else {
			if (tmp_arr[1] > len2[1]) for (int k = 0; k < tmp_arr[1] + 2; k++) len2[k] = tmp_arr[k];
			tmp_arr[0] = -1;
			tmp_arr[1] = 0;
		}
	}
	cout << "\n" << "Последовательность 1: ";
	for (int i = 2; i < len1[1] + 2; i++) cout << len1[i] << " ";
	cout << "\n" << "Последовательность 2: ";
	for (int i = 2; i < len2[1] + 2; i++) cout << len2[i] << " ";
	cout << "\n";
	int* resulting_arr = new int[_size - len1[1] - len2[1]] {};
	for (int i = 0, j = 0; i < _size; i++) {
		if ((i < len1[0] || i > len1[0] + len1[1] - 1) && (i < len2[0] || i > len2[0] + len2[1] - 1)) {
			resulting_arr[j] = arr[i];
			j++;
		}
	}
	cout << "Ответ: ";
	for (int i = 0; i < _size - len1[1] - len2[1]; i++) cout << resulting_arr[i] << " ";
	cout << "\n";
}








//Задача 2 часть 1
//int main() {
//	int num;
//	const int n = 4;
//
//	int arr[n][n], transarr[n][n];
//	for (int i = 0; i < n; i++){
//		for (int k = 0; k < n; k++) {
//			cin >> num;
//			arr[i][k] = num;
//		}
//	}
//	int sum = 0;
//	double maxChet = arr[0][0], maxSost = 0;
//	for (int i = 0; i < n; i++) {
//		for (int k = 0; k < n; k++) {
//			sum += arr[i][k];
//			if (arr[i][k] % 2 != 0) {
//				if (arr[i][k] > maxChet) {
//					maxChet = arr[i][k];
//				}
//			}
//			if (!((k <= i) && (k <= n - i - 1)) || ((k >= i) && (k >= n - i - 1))){
//				for (int j = 2; j < arr[i][k]-1; j++){
//					if (arr[i][k] % j == 0) {
//						if (arr[i][k] > maxSost) {
//							maxSost = arr[i][k];
//						}
//					}
//				}
//			}
//			transarr[i][k] = arr[k][i];
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		for (int k = 0; k < n; k++) {
//			arr[i][k] += transarr[i][k];
//			cout << arr[i][k] << " ";
//		}
//		cout << "\n";
//	}
//
//
//	double srGeom = pow(sum, float(1 / pow(n, 2)));
//
//	cout << srGeom << "\n";
//	cout << maxChet << "\n";
//	cout << maxSost << "\n";
//}


//задача 2 часть 2
//int main() {
//	const int k = 2, m = 3;
//	float num, sum, srarf;
//	int c, schet, z;
//	int arr[k][m], vectorg[k];
//	float vectord[k];
//	c = 0; sum = 0; z = 0; schet = 0;
//	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> num;
//			arr[i][j] = num;
//			if (arr[i][j] > 0) {
//				sum += arr[i][j];
//				c++;
//			}
//		}
//		srarf = float(sum / c);
//		vectord[i] = srarf;
//		c = 0;
//		sum = 0;
//		srarf = 0;
//	}
//	for (int i = 0; i < k; i++){
//		for (int j = 0; j < m; j++) {
//			
//			if (arr[i][j] > 0 and arr[i][j+1] < 0) {
//				schet += 1;
//			}
//			else if (arr[i][j] < 0 and arr[i][j + 1] > 0) {
//				schet += 1;
//			}
//		}
//		if (schet == m - 1 or schet == m) {
//			vectorg[i] = i;
//		}
//		else {
//			vectorg[i] = 404;
//		}
//		schet = 0;
//	}
//	cout << "VectorD[";
//	for (int i = 0; i < k; i++){
//		cout << " " << vectord[i] << ",";
//	}
//	cout << "]";
//
//	cout << "VectorG[";
//	for (int i = 0; i < k; i++) {
//		cout << " " << vectorg[i] << ",";
//	}
//	cout << "]";
//}