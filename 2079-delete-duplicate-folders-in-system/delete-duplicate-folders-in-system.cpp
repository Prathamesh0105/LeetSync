struct Trie {
    unordered_map<string, Trie*> links;
    string id = "";
    bool mark = 0;
    Trie(string id = "") : id(id) {}

    void insert(vector<string>& path) {
        Trie* Node = this;
        for (string& s : path) {
            if (!Node->links.count(s))
                Node->links[s] = new Trie(s);
            Node = Node->links[s];
        }
    }
};

class Solution {
public:
    Trie trie;
    unordered_map<string, Trie*> mp;
    vector<vector<string>> ans;

    string serial(Trie* Node) {
        if (Node->links.empty())
            return "";

        vector<pair<string, Trie*>> sorted(Node->links.begin(),
                                           Node->links.end());
        sort(sorted.begin(), sorted.end());

        string dir;
        for (auto& [id, child] : sorted)
            dir += "(" + id + serial(child) + ")";

        if (mp.count(dir)) {
            mp[dir]->mark = 1;
            Node->mark = 1;
        } 
        else
            mp[dir] = Node;
        //    cout<<dir<<endl;
        return dir;
    }

    void to_ans(Trie* Node, vector<string>& path) {
        for (auto& [id, child] : Node->links) {
            if (child->mark)
                continue;
            path.push_back(id);
            ans.push_back(path);
            to_ans(child, path);
            path.pop_back();
        }
    }

    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>>& paths) {
        for (auto& path : paths)
            trie.insert(path);

        serial(&trie);
        vector<string> path;
        to_ans(&trie, path);
        return ans;
    }
};

auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();