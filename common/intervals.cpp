
// seg: [l, r] intervals (both included), return the point covered by maximum times.
auto max_cover = [&](vector<pair<int,int> > seg) {
    vector<pair<int, int> > upd;
    for (const auto &[x, y]: seg) {
        upd.push_back({x, 1});
        upd.push_back({y + 1, -1});
    }
    sort(upd.begin(), upd.end());
    int ans = 0;
    for (int i = 0, j = 0, pref = 0; i < upd.size(); i = j) {
        while (j < upd.size() and upd[j].first == upd[i].first) {
            pref += upd[j].second;
            j ++;       
        }
        //printf("[%d, %d)\n", i, j);
        ans = max(ans, pref);
    }
    return ans;
};
