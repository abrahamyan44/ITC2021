# BENCHMARKING SORTING ALGORITHMS
This program tests a sorting algorithms on arrays of various sizes.

# AVAILABLE ALGORITHMS
- Quick Sort
- Shell Sort
- Merge Sort
- Heap Sort
- Bubble Sort
- Insertion Sort
- Selection Sort

## COMMAND OF USAGE IN BASH
```
$make                				 # creates the executable file for the programm
$./benchmark input_size tests_count  		 # runs the executable file
$make clean         				 # deletes all the generated files

```
> Where:
> input_size is length of the array which should be sorted
> tests_size is tests count which should be run on the same data(limited to 3)

> Output:
> Returns contain detailed report for min, max, average results (for 1 test cycle displayed only test duration)


## License
[MIT](https://choosealicense.com/licenses/mit/)
