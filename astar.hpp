
#define arbre
#include <string>
#include <list>
#include <ostream>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <cfloat> 
#include <set>
#include <array>
#include <stack>
#include <exception>
#include <set>
#include <unistd.h>

#define X_MAX 500
#define X_STEP 1
#define Y_MAX 500
#define Y_STEP 1

struct Node
{
    int y;
    int x;
    int parentX;
    int parentY;
    float gCost;
    float hCost; 
    float fCost;
};

inline bool operator < (const Node& x, const Node& y)
{
    return x.fCost < y.fCost;
}

class astar{

public:

static std::vector<Node> aStar(Node player, Node dest);

static bool obstacle[500][500];

private :

static bool isValid(int x, int y);

static bool isDestination(int x, int y, Node dest);

static double calculateH(int x, int y, Node dest);

static std::vector<Node> makePath(std::array<std::array<Node, (Y_MAX / Y_STEP)>, (X_MAX / X_STEP)> &map, Node dest);
};