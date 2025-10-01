#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

const int N = 3;

// Goal state
vector<vector<int>> goal = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 0}
};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
string dir[] = {"Up", "Down", "Left", "Right"};

struct Puzzle {
    vector<vector<int>> board;
    int x, y;
    string path;

    Puzzle(vector<vector<int>> b, int x_, int y_, string p = "") : board(b), x(x_), y(y_), path(p) {}

    bool isGoal() const {
        return board == goal;
    }

    int heuristic() const {
        int dist = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] != 0) {
                    int val = board[i][j] - 1;
                    int targetX = val / N;
                    int targetY = val % N;
                    dist += abs(i - targetX) + abs(j - targetY);
                }
        return dist;
    }
};

// Global variables to track best solution
int bestCost = 501;
string bestPath = "";

set<vector<vector<int>>> visited;

void BestFirstSearch(Puzzle current, int depth = 0, int maxDepth = 500) {
    int estimate = depth + current.heuristic();

    // Prune if worse than best
    if (estimate >= bestCost || depth > maxDepth)
        return;

    // Goal check
    if (current.isGoal()) {
        if (depth < bestCost) {
            bestCost = depth;
            bestPath = current.path;
        }
        return;
    }

    visited.insert(current.board);

    vector<Puzzle> nextStates;

    // Generate next states
    for (int i = 0; i < 4; i++) {
        int newX = current.x + dx[i];
        int newY = current.y + dy[i];
        if (newX >= 0 && newX < N && newY >= 0 && newY < N) {
            vector<vector<int>> newBoard = current.board;
            swap(newBoard[current.x][current.y], newBoard[newX][newY]);

            if (visited.count(newBoard)) continue;

            nextStates.emplace_back(newBoard, newX, newY, current.path + " " + dir[i]);
        }
    }

    // Sort by heuristic (Greedy Best-First)
    sort(nextStates.begin(), nextStates.end(), [](const Puzzle& a, const Puzzle& b) {
        return a.heuristic() < b.heuristic();
    });

    // Recurse
    for (Puzzle& next : nextStates) {
        BestFirstSearch(next, depth + 1, maxDepth);
    }

    // Backtrack: remove from visited
    visited.erase(current.board);
}

int main() {
    vector<vector<int>> start = {
        {1, 2, 3},
        {4, 0, 5},
        {6, 7, 8}
    };

    // Find the position of 0
    int x = 0, y = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (start[i][j] == 0) x = i, y = j;

    Puzzle startPuzzle(start, x, y);
    BestFirstSearch(startPuzzle);

    if (bestCost < 501) {
        cout << "Solved! Cost: " << bestCost << endl;
        cout << "Path: " << bestPath << endl;
    } else {
        cout << "No solution found within depth limit." << endl;
    }

    return 0;
}