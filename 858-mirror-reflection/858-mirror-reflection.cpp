class Solution {
public:
    int mirrorReflection(int p, int q) {
        int n = lcm(p, q);
		if((n / q) % 2 == 0) return 2;
		else if((n / p) % 2 == 0) return 0;
		else return 1;
    }
};