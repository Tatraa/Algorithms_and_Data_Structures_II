#include <iostream>
#include <string>

using namespace std;

int solution(std::string &S) {
    int counter = 0;
    int i = S.length() - 1;
    bool carry = false;

    // process the bits in S from right to left
    while(i >= 0) {
        if(S[i] == '0') {
            if(carry) {
                counter++;
            }
        } else {
            if(!carry) {
                counter++;
            }
            carry = !carry;
        }
        i--;
    }

    // if there's a carry left over, add one more step
    if(carry) {
        counter++;
    }

    return counter;
}

int main() {
    // Test case 1
    string s1 = "10101";
    int expected_output1 = 5;
    int output1 = solution(s1);
    cout << "Test case 1: expected output = " << expected_output1
         << ", actual output = " << output1 << endl;
    
    // Test case 2
    string s2 = "1111";
    int expected_output2 = 2;
    int output2 = solution(s2);
    cout << "Test case 2: expected output = " << expected_output2
         << ", actual output = " << output2 << endl;
    
    // Test case 3
    string s3 = "1010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010101010";
    int expected_output3 = 51;
    int output3 = solution(s3);
    cout << "Test case 3: expected output = " << expected_output3
         << ", actual output = " << output3 << endl;

    return 0;
}
