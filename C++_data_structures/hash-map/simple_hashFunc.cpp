#include "common.hpp"

// 加法哈希

int addHashFunc(string key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash = (hash + (int)c) % MODULUS;
    }
    return int(hash);
}

// 乘法哈希

int mulHashFunc(string key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash = (21 * hash + (int)c) % MODULUS;
    }
    return int(hash);
}

// 异或哈希
int xorHashFunc(string key)
{
    int hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash ^= c;
    }
    return hash % MODULUS;
}

// 旋转哈希
int rotHashFunc(string key)
{
    long long hash = 0;
    const int MODULUS = 1000000007;
    for (unsigned char c : key)
    {
        hash = ((hash << 1) ^ (hash >> 8) ^ (int)c) % MODULUS;
    }
    return (int)hash;
}