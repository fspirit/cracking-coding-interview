

void BubbleSort(std::vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 0; j < v.size() - i - 1; j++)
		{
			if (v[j] > v[j+1])
			{
				int tmp = v[j];
				v[j] = v[j+1];
				v[j+1] = tmp;
			}
		}
	}
}

void SelectionSort(std::vector<int>& v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		int minIndex = i + 1;		
		for (int j = i + 1; j < v.size(); j++)
		{
			if (v[j] < v[minIndex])
				minIndex = j;
		}
		if (v[i] < v[minIndex])
		{
			int tmp = v[i];
			v[i] = v[minIndex];
			v[minIndex] = tmp;	
		}
	}
}

void InsertionSort(std::vector<int>& v)
{
	for (int i = 1; i < v.size(); i++)
	{
		int j = i;
		while (j >= 0 && v[j-1] > v[j])
		{
			swap(v[j], v[j-1]);
			j--;
		}
	}
}


std::vector<int> MergeSort(std::vector<int>& v, int i, int j)
{
	if (j - i == 0)
		return { v[i] };

	int middle = i + (j - i) / 2;
	auto left = MergeSort(v, i, middle);
	auto right = MergeSort(v, middle + 1, j);

	std::vector<int> t;
	int n = 0;
	int m = 0;
	while (n < left.size() && m < right.size())
	{
		if (n == left.size())
		{
			t.push_back(right[m++]);
		}
		else if (m == right.size())
		{
			t.push_back(right[n++]);	
		}
		if (left[n] < right[m])
		{
			t.push_back(left[n++])
		}
		else
		{
			t.push_back(right[m++])	
		}
	}

	return t;

}

void QuickSort(std::vector<int>& v, int i, int j)
{
	if (i == j)
		return;

	int pivot = v[i];
	int swapIndex = i;
	for (int k = i + 1; k < j; k++)
	{
		if (v[k] < pivot)
		{
			swapIndex++;
			swap(v[k], v[swapIndex])			
			
		}	
	}
	swap(v[i], v[swapIndex]);
	QuickSort(v, i, swapIndex);
	QuickSort(v, swapIndex + 1, j);
}


