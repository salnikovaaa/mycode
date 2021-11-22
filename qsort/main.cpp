#include <iostream>
#include <vector>

using namespace std;



void read_array(vector<int> &arr, int n)
{
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}


void write_array(vector<int> &arr, int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
}


void mergesort(int left, int right, vector<int> &arr)
{
	if (right - left <= 1)
		return;

	int mid = left + (right - left)/2;

	mergesort(left, mid, arr);
	mergesort(mid, right, arr);

	vector<int> tmp(right - left);
	int l = left, r = mid, i = 0;

	while (l < mid || r < right)
	{
		while (l < mid && (r == right || arr[l] <= arr[r]))
		{
			tmp[i] = arr[l];
			l++;
			i++;
		}
		while (r < right && (l == mid || arr[r] <= arr[l]))
		{
			tmp[i] = arr[r];
			r++;
			i++;
		}
	}

	for (int i = 0; i < (right - left); i++)
		arr[left + i] = tmp[i];
}



int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);

	read_array(arr, n);
	mergesort(0, n, arr);
	write_array(arr, n);

	return OK;
}
