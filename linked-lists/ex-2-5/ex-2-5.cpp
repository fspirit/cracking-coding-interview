#include "../list.h"

List listsSum(List& a, List& b) 
{
	List result;

	auto currentA = a.head;
	auto currentB = b.head;
	int carryOver = 0;

	while (currentA != nullptr || currentB != nullptr || carryOver != 0)	
	{
		int sum = 0;
		if (currentA != nullptr && currentB != nullptr)
		{
			sum = currentA->value + currentB->value + carryOver;
			currentA = currentA->next;
			currentB = currentB->next;
		}
		else if (currentA != nullptr)
		{
			sum = currentA->value + carryOver;
			currentA = currentA->next;
		}
		else if (currentB != nullptr)
		{
			sum = currentB->value + carryOver;	
			currentB = currentB->next;
		}
		else
		{
			sum = carryOver;
		}
		int newValue = sum % 10;
		
		result.Add(new Node(newValue));
		carryOver = sum / 10;
	}	
	return result;
}

int main()
{
	Node a1(7);
	Node a2(1);
	Node a3(6);

	List a;
	a.Add(&a1);
	a.Add(&a2);
	a.Add(&a3);

	Node b1(5);
	Node b2(9);
	Node b3(2);

	List b;
	b.Add(&b1);
	b.Add(&b2);
	b.Add(&b3);

	std::cout << "Created lists" << std::endl;

	a.Print();
	b.Print();

	List sum = listsSum(a, b);

	sum.Print();

}