class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startR = -1, startC = -1;
        vector<pair<int, int>> litters;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    litters.push_back({r, c});
                }
            }
        }

        int numLitter = litters.size();
        if (numLitter == 0) return 0;

        int targetMask = (1 << numLitter) - 1;

        // maxEnergySaved[r][c][mask] tracks max remaining energy at state (r, c, mask)
        vector<vector<vector<int>>> maxEnergySaved(m, vector<vector<int>>(n, vector<int>(1 << numLitter, -1)));

        // BFS Queue stores: {moves, r, c, mask, currentEnergy}
        queue<tuple<int, int, int, int, int>> q;

        int initialMask = 0;
        for (int i = 0; i < numLitter; ++i) {
            if (litters[i].first == startR && litters[i].second == startC) {
                initialMask |= (1 << i);
            }
        }

        q.push({0, startR, startC, initialMask, energy});
        maxEnergySaved[startR][startC][initialMask] = energy;

        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [moves, r, c, mask, e] = q.front();
            q.pop();

            if (mask == targetMask) {
                return moves;
            }

            if (e < maxEnergySaved[r][c][mask]) {
                continue;
            }

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }

                int nextEnergy = e - 1;
                if (nextEnergy < 0) continue;

                int nextMask = mask;

                // Reset energy at 'R'
                if (classroom[nr][nc] == 'R') {
                    nextEnergy = energy;
                }

                // Collect litter at 'L'
                if (classroom[nr][nc] == 'L') {
                    for (int i = 0; i < numLitter; ++i) {
                        if (litters[i].first == nr && litters[i].second == nc) {
                            nextMask |= (1 << i);
                            break;
                        }
                    }
                }

                if (nextEnergy > maxEnergySaved[nr][nc][nextMask]) {
                    maxEnergySaved[nr][nc][nextMask] = nextEnergy;
                    q.push({moves + 1, nr, nc, nextMask, nextEnergy});
                }
            }
        }

        return -1;
    }
};