#include <vector>
#include <cmath>


class MaxHeap
{
	std::vector<int> array;

	void Swap(int i, int j)
	{
		int temp = array[i];
		array[i] = array[j];
		array[j] = i;
	}

	void SiftUp(int index)
	{
		int i = index;
		while (i > 0 && array[std::floor(i / 2)] < array[i])
		{
			Swap(i, std::floor(i / 2));
			i = std::floor(i / 2);
		}
	}

	void SiftDown(int index)
	{
		int maxIndex = index;
		int leftIndex = 2 * maxIndex;
		if (leftIndex < array.size() && array[leftIndex] > array[maxIndex])
		{
			maxIndex = leftIndex;
		}
		int rightIndex = 2 * maxIndex + 1;
		if (rightIndex < array.size() && array[rightIndex] > array[maxIndex])
		{
			maxIndex = rightIndex;
		}
		if (index != maxIndex)
		{
			Swap(index, maxIndex);
			SiftDown(maxIndex);
		}
	}

public:
	int ExtractMax()
	{
		if (array.size() == 0)
			return 0;
		Swap(0, array.size() - 1);
		int max = array[array.size() - 1];
		array.pop_back();
		SiftDown(0);

		return max;		
	}

	void Insert(int value)
	{
		array.push_back(value);
		SiftUp(array.size() - 1);
	}

};