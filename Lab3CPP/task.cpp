#include "queue.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input.is_open()) {
        cerr << "Cannot open file: " << argv[1] << endl;
        return 1;
    }
    vector<string> labirint;
    string line;
    while (getline(input, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        if (!line.empty()) {
            labirint.push_back(line);
        }
    }
    if (labirint.empty()) {
        cout << 0 << endl;
        return 0;
    }

    const int h = static_cast<int>(labirint.size());
    const int w = static_cast<int>(labirint[0].size());

    for (const auto &lin : labirint) {
        if (static_cast<int>(lin.size()) != w) {
            return 1;
        }
    }
    int start_str = -1, start_stl = -1, end_str = -1, end_stl = -1;
    for (int r = 0; r < h; r++) {
        for (int c = 0; c < w; c++) {
            if (labirint[r][c] == 'Q') {
                start_str = r;
                start_stl = c;
            } else if (labirint[r][c] == 'E') {
                end_str = r;
                end_stl = c;
            }
        }
    }
    if (start_str == -1 || end_str == -1) {
        cerr << "Start or finish not found." << endl;
        return 1;
    }
    const int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    const int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    vector<vector<int>> dist(h, vector<int>(w, -1));
    vector<vector<long long>> ways(h, vector<long long>(w, 0));

    Queue* q = queue_create();
    dist[start_str][start_stl] = 0;
    ways[start_str][start_stl] = 1;
    queue_insert(q, start_str * w + start_stl);

    while (!queue_empty(q)) {
        int pos = queue_get(q);
        queue_remove(q);
        int r = pos / w;
        int c = pos % w;
        for (int d = 0; d < 8; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            while (nr >= 0 && nr < h && nc >= 0 && nc < w && labirint[nr][nc] != '#') {
                const int nd = dist[r][c] + 1;
                if (dist[nr][nc] == -1) {
                    dist[nr][nc] = nd;
                    ways[nr][nc] = ways[r][c];
                    queue_insert(q, nr * w + nc);
                } else if (dist[nr][nc] == nd) {
                    ways[nr][nc] += ways[r][c];
                }
                nr += dr[d];
                nc += dc[d];
            }
        }
    }

    if (dist[end_str][end_stl] == -1) {
        cout << 0 << endl;
    } else {
        cout << ways[end_str][end_stl] << endl;
    }
    queue_delete(q);
    return 0;
}