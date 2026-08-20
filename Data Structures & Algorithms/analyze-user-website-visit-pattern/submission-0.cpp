#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 1. Define structure for combined data
    struct Visit {
        string user;
        int time;
        string site;
    };

    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        int n = username.size();
        vector<Visit> visits(n);

        for (int i = 0; i < n; ++i) {
            visits[i] = {username[i], timestamp[i], website[i]};
        }

        // 2. Sort strictly by timestamp (chronological order)
        sort(visits.begin(), visits.end(), [](const Visit& a, const Visit& b) {
            return a.time < b.time;
        });

        // 3. Group websites by user
        unordered_map<string, vector<string>> userSites;
        for (const auto& v : visits) {
            userSites[v.user].push_back(v.site);
        }

        unordered_map<string, int> freqMap;
        string bestPattern = "";
        int maxFreq = 0;

        // 4. Extract combinations per user
        for (const auto& p : userSites) {
            const vector<string>& sites = p.second;
            int m = sites.size();
            
            // Use a local set to prevent a user from voting for the same pattern twice
            unordered_set<string> uniquePatterns;

            // Generate all O(N^3) subsequences (order matters, but elements don't need to be contiguous)
            for (int i = 0; i < m - 2; ++i) {
                for (int j = i + 1; j < m - 1; ++j) {
                    for (int k = j + 1; k < m; ++k) {
                        // The '#' delimiter (ASCII 35) ensures safe lexicographical comparison
                        string pattern = sites[i] + "#" + sites[j] + "#" + sites[k];
                        uniquePatterns.insert(pattern);
                    }
                }
            }

            // 5. Add unique user votes to global map and track the winner on the fly
            for (const string& pat : uniquePatterns) {
                freqMap[pat]++;
                int currentFreq = freqMap[pat];

                // Tie-breaking logic: strictly greater frequency OR equal frequency but lexicographically smaller
                if (currentFreq > maxFreq) {
                    maxFreq = currentFreq;
                    bestPattern = pat;
                } else if (currentFreq == maxFreq && pat < bestPattern) {
                    bestPattern = pat;
                }
            }
        }

        // 6. Decode the winning string back into an array
        vector<string> result;
        string tmp = "";
        for (char ch : bestPattern) {
            if (ch != '#') {
                tmp += ch;
            } else {
                result.push_back(tmp);
                tmp = "";
            }
        }
        result.push_back(tmp);

        return result;
    }
};