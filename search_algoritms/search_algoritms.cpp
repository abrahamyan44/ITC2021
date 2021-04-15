#include "search_algoritms.hpp"

int BinarySearch(int arr[], int left, int right, int x)
{
    if (right >= left) {
        int mid = left + (right - left) / 2;
  
        if (arr[mid] == x)
            return mid;
  
        if (arr[mid] > x)
            return BinarySearch(arr, left, mid - 1, x);
  
        return BinarySearch(arr, mid + 1, right, x);
    }

    return -1;
}

int InterpolationSearch(int arr[], int n, int x)
{
    int low = 0, high = (n - 1);

    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == x) return low;
            return -1;
        }

        int pos = low + (((double)(high - low) /
            (arr[high] - arr[low])) * (x - arr[low]));

        if (arr[pos] == x)
            return pos;
 
        if (arr[pos] < x)
            low = pos + 1;

        else
            high = pos - 1;
    }
    return -1;
}

int JumpSearch(int arr[], int x, int n)
{
    int step = sqrt(n);
    int prev = 0;

    while (arr[std::min(step, n)-1] < x)
    {
        prev = step;
        step += sqrt(n);

        if (prev >= n)
            return -1;
    }

    while (arr[prev] < x)
    {
        prev++;

        if (prev == std::min(step, n))
            return -1;
    }

    if (arr[prev] == x)
        return prev;
 
    return -1;
}

int ExponentialSearch(int arr[], int n, int x)
{
    if (arr[0] == x)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= x)
        i = i*2;
 
    return BinarySearch(arr, i/2,
                           std:: min(i, n-1), x);
}

int TernarySearch(int left, int right, int key, int arr[])
{
    if (right >= left) {
 
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;
 
        if (arr[mid1] == key) {
            return mid1;
        }
        if (arr[mid2] == key) {
            return mid2;
        }
 
        if (key < arr[mid1]) {

            return TernarySearch(left, mid1 - 1, key, arr);
        }
        else if (key > arr[mid2]) {

            return TernarySearch(mid2 + 1, right, key, arr);
        }
        else{

            return TernarySearch(mid1 + 1, mid2 - 1, key, arr);
        }
    }
 
    return -1;
}


int main(){

		int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

		int left, right, key;
		std::cin >> left >> right >> key;
		int elem = 0;
		elem = TernarySearch(left, right, key, arr);

		std::cout << "Index of " << key << " is " << elem << std::endl;
		
		int x = 5;
		int n = sizeof(arr) / sizeof(arr[0]);
		int binary_result = BinarySearch(arr, 0, n - 1, x);
		
		if (binary_result == -1){
				std:: cout << "Element is not present in array" << std::endl;
		}
		else{
			std::cout << "Element is present at index " << binary_result << std::endl;
		}


		int interpol_index = InterpolationSearch(arr, n, x);
 
		if (interpol_index != -1)
				std::cout << "Element found at index " << interpol_index << std::endl;
		else
				std::cout << "Element not found." << std::endl;
		
		
return 0;
}
