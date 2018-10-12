#include <iostream>


bool isBadVersion(int version) {
    return version >= 1702766719;
}

class Solution {
public:
    int search(int low, int high) {        
        if (isBadVersion(low) == isBadVersion(high)) 
            return -1;
        
        if (high - low == 1)
            return high;
        
        int mid = (high - low) / 2 + low;        
        
        if (isBadVersion(mid)) return search(low, mid);
        return search(mid + 1, high);     
    }
    int firstBadVersion(int n) {
        return search(1, n);
    }
};


int main() {    
        
    int ret = Solution().firstBadVersion(2126753390);
    std::cout << ret << std::endl;
    
    return 0;
}