//
// Created by Jason on 11/22/2016.
//

#ifndef BLOOMFILTER_H
#define BLOOMFILTER_H

#include <iostream>
#include <vector>
#include <deque>
#include <bitset>
#include <sstream>
#include <iterator>


//addfunction
//testfunction
//filter number of bits = 64
//number of hash functions = 2
class BloomFilter {
public:

    BloomFilter(uint64_t size) : bitArr(size) {
    };

    void ConvertToBinary(uint64_t n, std::deque<uint64_t>* bin) {
        uint64_t rem;
        if (n/2 != 0) {
            ConvertToBinary(n / 2, bin);
        }
        bin->push_back(n%2);

    };

    uint64_t h1(uint64_t x) {
        std::deque<uint64_t > bin;
        ConvertToBinary(x, &bin);
        std::deque<uint64_t > h;
        for (uint64_t i=0; i<bin.size();i+=2) {
            h.push_back(bin[i]);
        }
        std::stringstream h1;
        std::copy(h.begin(), h.end(), std::ostream_iterator<uint64_t >(h1));
        std::string h2 = h1.str();
        long decimal = std::bitset<8>(h2).to_ulong();
        return decimal%bitArr.size();
    };

    uint64_t g1(uint64_t x) {
        std::deque<uint64_t> bin;
        ConvertToBinary(x, &bin);
        std::deque<uint64_t > g;
        for (uint64_t i=1; i<bin.size();i+=2) {
            g.push_back(bin[i]);
        }

        std::stringstream g1;
        std::copy(g.begin(), g.end(), std::ostream_iterator<uint64_t>(g1));
        std::string g2 = g1.str();
        long decimal = std::bitset<8>(g2).to_ulong();
        return decimal%bitArr.size();
    };

    void add(uint64_t data) {
        uint64_t h = h1(data);
        uint64_t g = g1(data);
        bitArr[h] = 1;
        bitArr[g] = 1;
    };

    bool test(uint64_t data) {
        uint64_t h = h1(data);
        uint64_t g = g1(data);
        if (bitArr[h] == 1 && bitArr[g] == 1) {
            return true;
        }
        return false;
    };


private:
    std::vector<bool> bitArr;
};

#endif