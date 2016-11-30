#include "BloomFilter.h"

using namespace std;

//b (bits in array)
//d (elements * hash functions)
//P = e^(-d/b)

//In our example, P=e^(-6/11)=~58% desnsity of 0s, desity of 1s = 42%
//Probabilty of false positive = 1D^#hashFunctions = .42^3 = 7.4%

//Currently only accepts positive ints
int main() {
    int bits = 100;
    BloomFilter* myFilter = new BloomFilter(bits);
    vector<int> elements = {25,159,585};
    for (int i=0; i<elements.size(); i++) {
        myFilter->add(25);
        myFilter->add(159);
        myFilter->add(585);
    }
    bool result1 = myFilter->test(118);
    bool result2 = myFilter->test(585);
    bool result3 = myFilter->test(25);
    bool result4 = myFilter->test(10);
    bool result5 = myFilter->test(159);
    bool result6 = myFilter->test(162);


    int x = 5;


}