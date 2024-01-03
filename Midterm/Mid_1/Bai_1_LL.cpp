#include<iostream>
#include<fstream>
#include<limits>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF INT_MAX;
const int M = 50;
char vertex[M] = {'a','b','c','d','e','g','h','k'};
struct Node{
    int val;
    Node* next;
};
typedef Node* nd;


