#include "astar.hpp"

bool astar::isValid(int x, int y) { 
        if (!obstacle[x][y]) {

            if (x < 0 || y < 0 || x >= (X_MAX / X_STEP) || y >= (Y_MAX / Y_STEP)) {
                return false;
            }
            return true;
        }
        return false;
    }

bool astar::isDestination(int x, int y, Node dest) {
        if (x == dest.x && y == dest.y) {
            return true;
        }
        return false;
    }

double astar::calculateH(int x, int y, Node dest) {
        double H = (std::sqrt((x - dest.x)*(x - dest.x)
            + (y - dest.y)*(y - dest.y)));
        return H;
    }

std::vector<Node> astar::aStar(Node player, Node dest) {

        std::vector<Node> empty;
        if (isValid(dest.x, dest.y) == false) {
            return empty;
            //Destination invalide
        }
        if (isDestination(player.x, player.y, dest)) {
            return empty;
        }
        bool closedList[(X_MAX / X_STEP)][(Y_MAX / Y_STEP)];

        //Initialise la map
        std::array<std::array < Node, (Y_MAX / Y_STEP)>, (X_MAX / X_STEP)> allMap;
        for (int x = 0; x < (X_MAX / X_STEP); x++) {
            for (int y = 0; y < (Y_MAX / Y_STEP); y++) {
                allMap[x][y].fCost = FLT_MAX;
                allMap[x][y].gCost = FLT_MAX;
                allMap[x][y].hCost = FLT_MAX;
                allMap[x][y].parentX = -1;
                allMap[x][y].parentY = -1;
                allMap[x][y].x = x;
                allMap[x][y].y = y;

                closedList[x][y] = false;
            }
        }

        //starting list
        int x = player.x;
        int y = player.y;
        allMap[x][y].fCost = 0.0;
        allMap[x][y].gCost = 0.0;
        allMap[x][y].hCost = 0.0;
        allMap[x][y].parentX = x;
        allMap[x][y].parentY = y;

        std::set<Node> openList;  

        openList.emplace(allMap[x][y]);
        bool destinationFound = false;

        while (!openList.empty()&&openList.size()<(X_MAX / X_STEP)*(Y_MAX / Y_STEP)) {
            Node node;
            do {
                float temp = FLT_MAX;
                std::set<Node>::iterator itNode;

                for (std::set<Node>::iterator it = openList.begin();
                    it != openList.end(); ++it) {
                    Node n = *it;
                    if (n.fCost < temp) {
                        temp = n.fCost;
                        node = n;
                    }
                }


                openList.erase(node);

            } while (isValid(node.x, node.y) == false);

            x = node.x;
            y = node.y;
            closedList[x][y] = true;
            
            //de nord west à sud est
            for (int newX = -1; newX <= 1; newX++) {
                for (int newY = -1; newY <= 1; newY++) {
                    double gNew, hNew, fNew;
                    
                    if (isValid(x + newX, y + newY)) {
                        if (isDestination(x + newX, y + newY, dest))
                        {
                            //Destination trouvée on construit le path
                            allMap[x + newX][y + newY].parentX = x;
                            allMap[x + newX][y + newY].parentY = y;
                            destinationFound = true;
                
                            return makePath(allMap, dest);
                        }
                        else if (closedList[x + newX][y + newY] == false)
                        {
                            gNew = node.gCost + 1.0;
                            hNew = calculateH(x + newX, y + newY, dest);
                            fNew = gNew + hNew;
                            //Check si ce path est meilleur
                            if (allMap[x + newX][y + newY].fCost == FLT_MAX ||
                                allMap[x + newX][y + newY].fCost > fNew)
                            {

                                // Update voisin
                                allMap[x + newX][y + newY].fCost = fNew;
                                allMap[x + newX][y + newY].gCost = gNew;
                                allMap[x + newX][y + newY].hCost = hNew;
                                allMap[x + newX][y + newY].parentX = x;
                                allMap[x + newX][y + newY].parentY = y;
                                openList.emplace(allMap[x + newX][y + newY]);
                            }
                        }
                    }
                }
            }
            
            }
            if (destinationFound == false) {
                return empty;
        }
    }

 std::vector<Node> astar::makePath(std::array<std::array<Node, (Y_MAX / Y_STEP)>, (X_MAX / X_STEP)>  &map, Node dest) {
        try {
            int x = dest.x;
            int y = dest.y;
            std::stack<Node> path;
            std::vector<Node> usablePath;

            while (!(map[x][y].parentX == x && map[x][y].parentY == y)
                && map[x][y].x != -1 && map[x][y].y != -1) 
            {
                path.push(map[x][y]);
                int tempX = map[x][y].parentX;
                int tempY = map[x][y].parentY;
                x = tempX;
                y = tempY;

            }
            path.push(map[x][y]);

            while (!path.empty()) {
                Node top = path.top();
                path.pop();
                usablePath.emplace_back(top);
            }
            return usablePath;
        }
        catch(const std::exception& e){
        }
 }