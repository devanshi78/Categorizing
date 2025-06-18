#include<iostream>
#include<vector>

using namespace std;

void selection_sort(vector<int>& arr, int n)
{
    int min,temp;
    for(int i = 0; i < n-1; i++)
    {
        min = i;
        for(int j = i+1; j < n; j++)
        {
            if(arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void merge(vector<int>& arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid+1;

    while(i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
            temp.push_back(arr[i++]);
        else
            temp.push_back(arr[j++]);
    }

    for (int k = 0; k < temp.size(); k++) {
        arr[start + k] = temp[k];
    }
}

void merge_sort(vector<int>& arr, int start, int end)
{
    if(start >= end) return;

    int mid = start + (end-start) / 2;

    merge_sort(arr,start,mid); //left
    merge_sort(arr,mid+1,end); //right
    merge(arr,start,mid,end);
}

int linear_search(vector<int>& arr, int target)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr.at(i) == target)
        {
            return i;
        }
    }
    return -1;
}

int binary_search(vector<int>& arr, int key)
{
    int start = 0;
    int end = arr.size() -1;

    while(start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
           start = mid + 1;
        }
        else
        {
            end = mid -1;
        }
    }
    return -1;
}

void printarray(vector<int>& arr, int n){
    cout<<endl;
    cout<<"Array is : ";
    for(int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr;
    int choice, value, n;

    do
    {
        cout << "\n-------- MENU --------\n";
        cout << "1. Enter Array"<<endl;
        cout << "2. Selection Sort"<<endl;
        cout << "3. Merge Sort"<<endl;
        cout << "4. Linear Search"<<endl;
        cout << "5. Binary Search"<<endl;
        cout << "6. Print Array"<<endl;
        cout << "0. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1 :
                cout << "Enter size of array: ";
                cin >> n;
                for(int i = 0; i < n; i++)
                {
                    int value;
                    cout << "Enter value a[" << i << "]: ";
                    cin >> value;
                    arr.push_back(value);
                }
                break;
            case 2 :
                selection_sort(arr,arr.size());
                cout<<"Array sorting using selection sort"<<endl;
                printarray(arr,n);
                break;
            case 3 :
                merge_sort(arr,0,arr.size() -1);
                cout<<"Array sorting using merge sort";
                break;
            case 4 :
                int element,result;
                cout<<"Enter target element : ";
                cin>>element;
                result = linear_search(arr,element);
                // return -1 it means it is returning error.
                if(result != -1)
                {
                    cout<<"element at : "<<result<<endl;
                }
                else
                {
                    cout<<"not found!"<<endl;
                }
                break;
            case 5 :
                cout << "Enter value to search (Binary): \n (do not enter unsorted array)";
                cin >> element;
                result = binary_search(arr,element);
                if (result != -1) 
                {
                    cout << "Element at : "<<result<<endl;
                } 
                else 
                {
                    cout << "Element not found!" << endl;
                }
                break;
            case 6 :
                printarray(arr,n);
                break;
            case 0 :
                cout<<"Exiting....."<<endl;
                break;
            default :
                cout<<"Invalid choice!"<<endl;
        }
    }while (choice != 0);
    

    return 0;
}