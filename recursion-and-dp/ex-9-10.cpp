#include <vector>
#include <iostream>

struct Box
{
	int Height;
	int Width;
	int Depth;
	Box(int h, int w, int d): Height(h), Width(w), Depth(d) {};
	bool LessThen(const Box& other) {
		return Height < other.Height && Width < other.Width && Depth < other.Depth;
	}
};

int TallestStack(std::vector<Box> boxes, Box* prev) {

	std::cout << boxes.size() << std::endl;

	if (boxes.size() == 1) {
		if (boxes[0].LessThen(*prev)){
			return boxes[0].Height;
		}
		return 0;		
	}

	int max = 0;
	for (int i = 0; i < boxes.size(); i++) {
		if (prev == nullptr || boxes[i].LessThen(*prev)) {
			auto p = boxes[i];
			auto newBoxes = boxes;
			newBoxes.erase(newBoxes.begin() + i);
			auto h = TallestStack(newBoxes, &p) + p.Height;
			if (h > max) {
				max = h;
			}
		}			
	}

	return max;
}

int main(int argc, char const *argv[])
{
	std::vector<Box> boxes { {4, 4, 4}, {3, 3, 3}, {1, 1, 1}, {1, 1, 1} };

	std::cout << TallestStack(boxes, nullptr) << std::endl;

	return 0;
}