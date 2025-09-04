// To check whether two strings form an anagram pair
//Two strings are considered anagrams if one string can be rearranged to form the other string

# include <iostream>
# include <string>
using namespace std;


// Method 1 : Sorting and Comparing
// Time Complexity = O(nlog(n))
// Space Complexity = O(1)
bool anagram_strings_m1(string s1, string s2) {

    // Cannot be anagrams if lengths are unequal
    if (s1.length() != s2.length()) return false;
    else {
        // Sorting the two strings
        sort(&s1[0], &s1[0]+s1.length());
        sort(&s2[0], &s2[0]+s2.length());
        if (s1 == s2) {
            return true;
        }
        else return false;
    }
}


// Method 2 : Counting frequency of occurenece of characters and then subtracting every occurence in second string
// Time Complexity = O(n)
// Space Complexity = O(1)

bool anagram_strings_m2(string s1, string s2) {

    if (s1.length() != s2.length()) return false;

    // Array to count occurrence of characters (0-255), initialized with every element being zero
    int count[256] = {0};
    
    for (int i=0; i<s1.length(); i++) {
        int alph = s1[i];
        count[alph]++;
    }
    for (int i=0; i<s2.length(); i++) {
        int alph = s2[i];
        count[alph]--;
    }

    // Checking if every element of count array = 0
    for (int i=0; i<256; i++) {
        if (count[i] != 0) return false;
    }

    return true;
}



// Method 3: Parallel counting
//Making two count arrays for each string, and comparing elements for equality
// Less efficient than m2 coz more space(2 arrays) and time is required




int main() {

    string str1,str2;
    cout << "Enter string 1 : " ;
    getline(cin, str1);
    cout << "Enter string 2 : " ;
    getline(cin, str2);

    if (anagram_strings_m1(str1,str2)) {
        cout << "Anagram Pair" << endl;
    }
    else cout << "Not Anagram Pair" << endl;


    if (anagram_strings_m2(str1,str2)) {
        cout << "Anagram Pair" << endl;
    }
    else cout << "Not Anagram Pair" << endl;


    return 0;

}