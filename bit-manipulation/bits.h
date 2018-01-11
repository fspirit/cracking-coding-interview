
bool GetBit(int number, int bitIndex)
{
	return ((number & (1 << bitIndex)) != 0);
}

int SetBit(int number, int bitIndex)
{
	return number | (1 << bitIndex);
}

int ClearBit(int number, int bitIndex)
{
	return number & (~(1 << bitIndex));
}