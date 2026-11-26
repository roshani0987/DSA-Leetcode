
class Trie {
private:
    struct Node {
        Node* links[26];
        bool flag;

        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            flag = false;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->links[idx] == nullptr) {
                node->links[idx] = new Node();
            }

            node = node->links[idx];
        }

        node->flag = true;
    }

    bool search(string word) {
        Node* node = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (node->links[idx] == nullptr) {
                return false;
            }

            node = node->links[idx];
        }

        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (node->links[idx] == nullptr) {
                return false;
            }

            node = node->links[idx];
        }

        return true;
    }
};
