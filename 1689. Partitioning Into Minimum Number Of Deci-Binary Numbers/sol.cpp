class Solution {
public:
    int minPartitions(string n) {
        /*since its only ones and zeros, you would need at least the max number in the string of ones to add up to it for example a number like 431 you would need
        1 0/1 0/1
        1 0/1 0/1
        1 0/1 0/1
        1 0/1 0/1
        and hence the correct answer is the max digit of the string
        */
        return *max_element(n.begin(), n.end()) - '0';
    }
};
