#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

// Representation of the 2x2x2 Rubik's Cube
using CubeState = vector<vector<string> >;

// Define the solved state
CubeState solvedState = {
    {"G", "Y", "O"}, {"B", "O", "Y"},
    {"G", "O", "W"}, {"B", "W", "O"},
    {"G", "R", "Y"}, {"B", "Y", "R"},
    {"G", "W", "R"}, {"B", "R", "W"}
};

// Define the possible moves
enum Move { R, U, F, Rp, Up, Fp, R2, U2, F2 };

// Function to apply a move to the cube state
void applyMove(vector<vector<string> >& cube, Move move) {
    switch (move) {
        case R://2367
            swap(cube[3][1], cube[2][2]);
            swap(cube[2][2], cube[6][1]);
            swap(cube[6][1], cube[7][2]);
            swap(cube[3][0], cube[2][1]);
            swap(cube[2][1], cube[6][0]);
            swap(cube[6][0], cube[7][1]);
            swap(cube[3][2], cube[2][0]);
            swap(cube[2][0], cube[6][2]);
            swap(cube[6][2], cube[7][0]);
            break;
        case U://0123
            swap(cube[1][1], cube[0][2]);
            swap(cube[0][2], cube[2][1]);
            swap(cube[2][1], cube[3][2]);
            swap(cube[1][2], cube[0][0]);
            swap(cube[0][0], cube[2][2]);
            swap(cube[2][2], cube[3][0]);
            swap(cube[1][0], cube[0][1]);
            swap(cube[0][1], cube[2][0]);
            swap(cube[2][0], cube[3][1]);
            break;
        case F://0246
            swap(cube[2], cube[0]);
            swap(cube[0], cube[4]);
            swap(cube[4], cube[6]);
            break;
        case Rp://2367
            swap(cube[2][2], cube[3][1]);
            swap(cube[3][1], cube[7][2]);
            swap(cube[7][2], cube[6][1]);
            swap(cube[2][1], cube[3][0]);
            swap(cube[3][0], cube[7][1]);
            swap(cube[7][1], cube[6][0]);
            swap(cube[2][0], cube[3][2]);
            swap(cube[3][2], cube[7][0]);
            swap(cube[7][0], cube[6][2]);
            break;
        case Up://0123
            swap(cube[0][2], cube[1][1]);
            swap(cube[1][1], cube[3][2]);
            swap(cube[3][2], cube[2][1]);
            swap(cube[0][1], cube[1][0]);
            swap(cube[1][0], cube[3][1]);
            swap(cube[3][1], cube[2][0]);
            swap(cube[0][0], cube[1][2]);
            swap(cube[1][2], cube[3][0]);
            swap(cube[3][0], cube[2][2]);
            break;
        case Fp://0246
            swap(cube[0], cube[2]);
            swap(cube[2], cube[6]);
            swap(cube[6], cube[4]);
            break;
        case R2:
            applyMove(cube, R);
            applyMove(cube, R);
            break;
        case U2:
            applyMove(cube, U);
            applyMove(cube, U);
            break;
        case F2:
            applyMove(cube, F);
            applyMove(cube, F);
            break;
        default:
            cout << "Invalid move!" << endl;
            break;
    }
}

// Function to print the sequence of moves
void printMoves(const vector<Move>& moves) {
    for (const auto& move : moves) {
        switch (move) {
            case R: cout << "R "; break;
            case U: cout << "U "; break;
            case F: cout << "F "; break;
            case Rp: cout << "R' "; break;
            case Up: cout << "U' "; break;
            case Fp: cout << "F' "; break;
            case R2: cout << "R2 "; break;
            case U2: cout << "U2 "; break;
            case F2: cout << "F2 "; break;
        }
    }
    cout << endl;
}

// Function to check if the cube is in the solved state
bool isSolved(const CubeState& cube) {
    return cube == solvedState;
}

// Encoding the cube state
string serializeCubeState(const CubeState& cube) {
    string serialized;
    for (const auto& row : cube) {
        for (const auto& color : row) {
            serialized += color;
        }
    }
    return serialized;
}

// BFS algorithm to solve the Rubik's Cube
vector<Move> solveRubiksCubeBFS(const CubeState& initialCube) {
    queue<pair<CubeState, vector<Move> > > q;

    unordered_set<string> visited;

    q.push({initialCube, {}});

    while (!q.empty()) {
        auto current = q.front();
        q.pop();

        const CubeState& currentCube = current.first;
        const vector<Move>& currentMoves = current.second;

        // Check if the current state is the goal state
        if (isSolved(currentCube)) {
            return currentMoves;
        }

        string serializedState = serializeCubeState(currentCube);

        if (visited.find(serializedState) == visited.end()) {
            visited.insert(serializedState);

            // Iterate through possible moves
            for (int move = R; move <= F2; ++move) {
                CubeState nextCube = currentCube;
                applyMove(nextCube, static_cast<Move>(move));

                vector<Move> nextMoves = currentMoves;
                nextMoves.push_back(static_cast<Move>(move));
                q.push({nextCube, nextMoves});
            }
        }
    }

    return {};
}

// Function to print the CubeState
void printCubeState(const CubeState& cube) {
    for (const auto& row : cube) {
        for (const auto& color : row) {
            cout << color << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {

    CubeState  initialCube = {
    {"G", "Y", "O"}, {"B", "O", "Y"},
    {"G", "O", "W"}, {"B", "W", "O"},
    {"G", "R", "Y"}, {"B", "Y", "R"},
    {"G", "W", "R"}, {"B", "R", "W"}
    };

    applyMove(initialCube, R2);
    applyMove(initialCube, U2);
    applyMove(initialCube, F);
    applyMove(initialCube, R2);
    applyMove(initialCube, U2);
    applyMove(initialCube, U2);
    applyMove(initialCube, Fp);
    applyMove(initialCube, U2);
    applyMove(initialCube, Rp);
    applyMove(initialCube, Fp);
    applyMove(initialCube, U2);
    printCubeState(initialCube);
    
    vector<Move> solution = solveRubiksCubeBFS(initialCube);

    if (!solution.empty()) {
        cout << "Solution found:" << endl;
        printMoves(solution);
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}