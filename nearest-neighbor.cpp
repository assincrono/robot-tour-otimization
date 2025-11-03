#include <iostream>
#include <cmath>
#include <array>
#include <climits>
using namespace std;

// Problem: Robot Tour Optimization
// Input: A set S of n points in the plane.
// Output: What is the shortest cycle tour that visits each point in the set S?

bool exists(int output[][2], int filled, int x, int y) {
    for (int i = 0; i < filled; i++) {
        if (output[i][0] == x && output[i][1] == y) {
            return true; // found a match
        }
    }
    return false; // not found
}

int main() {
    int n;
    cin >> n;

    // Creates the input
    int points[n][2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> points[i][j];
        }
    }

    // Generates the output
    int output[n + 1][2];
    int i = 0;

    int p0[2];
    p0[0] = points[i][0];
    p0[1] = points[i][1];

    int totalDistance = 0;

    output[i][0] = p0[0];
    output[i][1] = p0[1];

    output[n][0] = p0[0];
    output[n][1] = p0[1];

    while (i < (n - 1)) {
        i++;

        int smallestDistance = INT_MAX;
        int smallestDistancePoint[2];
        for (int j = 0; j < n; j++) {
            int p1[2];
            p1[0] = points[j][0];
            p1[1] = points[j][1];

            if (p1[0] == p0[0] && p1[1] == p0[1]) {
                continue;
            }

            if (exists(output, n, p1[0], p1[1])) {
                continue;
            }

            int distance = sqrt(pow(p1[0] - p0[0], 2) + pow(p1[1] - p0[1], 2));
            if (distance < smallestDistance) {
                smallestDistance = distance;
                smallestDistancePoint[0] = p1[0];
                smallestDistancePoint[1] = p1[1];
            }
        }

        totalDistance += smallestDistance;

        output[i][0] = smallestDistancePoint[0];
        output[i][1] = smallestDistancePoint[1];

        p0[0] = smallestDistancePoint[0];
        p0[1] = smallestDistancePoint[1];
    }

    // Prints the output
    for (int i = 0; i < (n + 1); i++) {
        for (int j = 0; j < 2; j++) {
            cout << output[i][j] << " ";
        }

        cout << "\n";
    }

    cout << totalDistance;
}
