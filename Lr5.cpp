#include<iostream>
#include"omp.h"
#include<chrono>
using namespace std;

const int arr_size = 20000;

int arr[arr_size][5];

void init_arr();
long long part_sum(int, int, int);
int part_min_row(int, int, int);
int sizeThread = 4;

int main() {
	setlocale(LC_ALL, "rus");
	init_arr();
	omp_set_nested(1);
	double t1 = omp_get_wtime();

#pragma omp parallel sections
	{
#pragma omp section
		{
			cout << "Рядок з мнiмальною сумою (к-ть потокiв = " << 1 << "): " << part_min_row(0, arr_size, 4) << endl;
			cout << "Рядок з мнiмальною сумою (к-ть потокiв = " << 4 << "): " << part_min_row(0, arr_size, 4) << endl;
			cout << "Рядок з мнiмальною сумою (к-ть потокiв = " << 8 << "): " << part_min_row(0, arr_size, 8) << endl;
			cout << "Рядок з мнiмальною сумою (к-ть потокiв = " << 16 << "): " << part_min_row(0, arr_size, 16) << endl;
			cout << "Рядок з мнiмальною сумою (к-ть потокiв = " << 32 << "): " << part_min_row(0, arr_size, 32) << endl;
		}

#pragma omp section
		{
			cout << "Сума всього (к-ть потокiв = " << 1 << "): " << part_sum(0, arr_size, 4) << endl;
			cout << "Сума всього (к-ть потокiв = " << 4 << "): " << part_sum(0, arr_size, 4) << endl;
			cout << "Сума всього (к-ть потокiв = " << 8 << "): " << part_sum(0, arr_size, 8) << endl;
			cout << "Сума всього (к-ть потокiв = " << 16 << "): " << part_sum(0, arr_size, 16) << endl;
			cout << "Сума всього (к-ть потокiв = " << 32 << "): " << part_sum(0, arr_size, 32) << endl;
		}
	}
	double t2 = omp_get_wtime();
	cout << "Час всього: " << t2 - t1 << " секунд" << endl;
	return 0;
}

void init_arr() {
	for (int i = 0; i < arr_size; i++) {
		for (int j = 0; j < arr_size; j++) {
			arr[i][j] = (arr_size - i - 1) * arr_size + j;
		}
	}
}


long long part_sum(int start_index, int finish_index, int num_threads) {
	long long sum = 0;
	double t1 = omp_get_wtime();
#pragma omp parallel for reduction(+:sum) num_threads(num_threads)
	for (int i = start_index; i < finish_index; i++) {
		for (int j = 0; j < arr_size; j++) {
			sum += arr[i][j];
		}
	}
	double t2 = omp_get_wtime();
	cout << "Час для суми(к-ть потокiв " << num_threads << " ):" << t2 - t1 << " секунд" << endl;
	return sum;
}

int part_min_row(int start_index, int finish_index, int num_threads) {
	int min_row = -1;
	long long minsum = INT32_MAX;
	double t1 = omp_get_wtime();
#pragma omp parallel for num_threads(num_threads)
	for (int i = start_index; i < finish_index; i++) {
		long long sum = 0;
		for (int j = 0; j < arr_size; j++) {
			sum += arr[i][j];
		}
		if(minsum>sum){
			#pragma omp critical
			if (minsum > sum) {
				min_row = i;
				minsum = sum;
			}
		}
	}
	double t2 = omp_get_wtime();
	cout << "Час для знаходження рядка з мiнiмальною сумою(к-ть потокiв = " << num_threads << " : " << t2 - t1 << " секунд" << endl;
	return min_row;
}
