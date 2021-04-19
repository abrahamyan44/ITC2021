#include "testing.hpp"

int main(int argc, char* argv[])
{
	int size = std::stoi(argv[1]);
	int test_count = std::stoi(argv[2]);
	int* array = nullptr;
    assert(size > 0);
    array = new int64_t[size];
    srand(time(0));
    for(int i = 0; i < size; ++i) {
        array[i] = rand() % 3425;
    }
	test::TestingQuick(array, size, test_count);
	test::TestingHeap(array, size, test_count);
	test::TestingMerge(array, size, test_count);
	test::TestingBubble(array, size, test_count);
	test::TestingShell(array, size, test_count);
	return 0;
}
