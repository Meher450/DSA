class Solution {
public:

    // DFS to recolor connected pixels
    void DFS(vector<vector<int>>& image,
             int i, int j,
             int oldcol, int newCol) {

        // Base case:
        // 1. Out of bounds
        // 2. Current pixel is not the original color
        if (i < 0 || j < 0 ||
            i >= image.size() ||
            j >= image[0].size() ||
            image[i][j] != oldcol) {
            return;
        }

        // Recolor current pixel
        image[i][j] = newCol;

        // Explore all 4 directions
        DFS(image, i - 1, j, oldcol, newCol);
        DFS(image, i + 1, j, oldcol, newCol);
        DFS(image, i, j + 1, oldcol, newCol);
        DFS(image, i, j - 1, oldcol, newCol);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        // Original color of starting pixel
        int oldcol = image[sr][sc];

        // Important optimization:
        // Avoid infinite recursion if new color == old color
        if (oldcol != color) {
            DFS(image, sr, sc, oldcol, color);
        }

        return image;
    }
};
