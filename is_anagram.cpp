#include <iostream>
#include <vector>
#include <string>

// O(n) time, where n is length of strings.
// O(1) space.
bool isAnagram(const std::string &s1, const std::string &s2) {

    if (s1.length() != s2.length()) {
        return false;
    }

    // Frequency array for extended ASCII (0 - 255)
    std::vector<int> count(256, 0);
    
    for (char c: s1) {
        count[(unsigned char)c]++;
    }

    for (char c: s2) {
        // If we try to decrement a zero, it's obviously wrong.
        // Because of our initial length restriction, it's impossible for any count to be > 0.
        if (--count[(unsigned char)c] < 0) {
            return false;
        }
    }

    return true;
}

int main() {
    std::cout << std::boolalpha << isAnagram("world! hello", "hello world!");
    return 0;
}