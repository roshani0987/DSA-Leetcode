
class Trie {
    struct Node {
        Node* child[26] = {};
        bool end = false;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* cur = root;

        for (char c : word) {
            int i = c - 'a';

            if (!cur->child[i])
                cur->child[i] = new Node();

            cur = cur->child[i];
        }

        cur->end = true;
    }

    bool search(string word) {
        Node* cur = root;

        for (char c : word) {
            cur = cur->child[c - 'a'];

            if (!cur)
                return false;
        }

        return cur->end;
    }

    bool startsWith(string prefix) {
        Node* cur = root;

        for (char c : prefix) {
            cur = cur->child[c - 'a'];

            if (!cur)
                return false;
        }

        return true;
    }
};
