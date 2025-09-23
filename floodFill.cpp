#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, int initialColor, int newColor, vector<vector<int>> &image) {
    int n = image.size();    // number of rows
    int m = image[0].size(); // number of columns
    
    // boundary + color check
    if (i < 0 || j < 0 || i >= n || j >= m) return;
    if (image[i][j] != initialColor) return;

    image[i][j] = newColor;

    // explore neighbors
    dfs(i - 1, j, initialColor, newColor, image);
    dfs(i + 1, j, initialColor, newColor, image);
    dfs(i, j - 1, initialColor, newColor, image);
    dfs(i, j + 1, initialColor, newColor, image);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color) {
    int initialColor = image[sr][sc];
    if (initialColor != color) {
        dfs(sr, sc, initialColor, color, image);
    }
    return image;
}

int main() {
    cout << "Enter n (rows) and m (cols): " << endl;
    int n, m;
    cin >> n >> m;

    vector<vector<int>> image(n, vector<int>(m));
    cout << "Enter matrix values: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> image[i][j];
        }
    }

    int sr, sc, newColor;
    cout << "Enter start row, start col, and new color: " << endl;
    cin >> sr >> sc >> newColor;

    auto result = floodFill(image, sr, sc, newColor);

    cout << "Result image:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

