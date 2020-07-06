#include <iostream>
#include <vector>
#include<numeric>
#include <algorithm>

//Shown here is how to use a nested for loop structure and sum values in a specific shape, in this case an hourglass is used, then outputted to the console is the highest summed value of all the hourglass


/*
Create a local array to keep count of the max values for each hourglass. 
Use a nested for loop to iterate on each section of the 2D array. 
Within the nested for loop sum the hourglass structure, note the 2D array march,
'i' references the height of the array and 'j' references the width.
The max_element function is used to figure out the largest sum, it is a forward iterator
meaning it marches down the array linearly. It is a pointer so that the return of an 
int works.
*/
#if 1 
int hourglassSum(std::vector<std::vector<int>> arr)
{
    std::vector<int> hourglassValues;
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            hourglassValues.push_back(arr[i][j] + arr[i][j + 1] + arr[i][j + 2] +
                arr[i + 1][j + 1] +
                arr[i + 2][j] + arr[i + 2][j + 1] + arr[i + 2][j + 2]);
        }
    }
        
    return *std::max_element(hourglassValues.begin(), hourglassValues.end());
}
#endif

int main() {
	
    //Sample input 1 1 1 0 0 0 0 1 0 0 0 0 1 1 1 0 0 0 0 0 2 4 4 0 0 0 0 2 0 0 0 0 1 2 4 0
    std::vector<std::vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            std::cin >> arr[i][j];
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int result = hourglassSum(arr);

    std::cout << result << std::endl;
	
	return 0;
}