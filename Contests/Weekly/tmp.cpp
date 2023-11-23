#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    class Node {
    public:
        Node* one;
        Node* zero;
        bool deleted;  // New field to mark deleted nodes

        Node() : one(nullptr), zero(nullptr), deleted(false) {}
    };

    class Trie {
        Node* root;

    public:
        Trie() : root(new Node()) {}

        void insert(int n) {
            Node* temp = root;
            for (int i = 21; i >= 0; i--) {
                int bit = (n >> i) & 1;
                if (bit == 0) {
                    if (temp->zero == nullptr) {
                        temp->zero = new Node();
                    }
                    temp = temp->zero;
                } else {
                    if (temp->one == nullptr) {
                        temp->one = new Node();
                    }
                    temp = temp->one;
                }
            }
        }

        void deleteNode(int n) {
            deleteNodeHelper(root, n, 21);
        }

        void deleteNodeHelper(Node* node, int n, int depth) {
            if (node == nullptr) {
                return;
            }

            if (depth == -1) {
                // Mark the leaf node as deleted instead of deleting it.
                node->deleted = true;
                return;
            }

            int bit = (n >> depth) & 1;

            if (bit == 0) {
                deleteNodeHelper(node->zero, n, depth - 1);
            } else {
                deleteNodeHelper(node->one, n, depth - 1);
            }
        }

        int maxXorHelper(int value) {
            Node* temp = root;
            int currentAns = 0;

            for (int i = 21; i >= 0; i--) {
                int bit = (value >> i) & 1;
                if (bit == 0) {
                    if (temp->one && !temp->one->deleted) {
                        temp = temp->one;
                        currentAns += (1 << i);
                    } else {
                        temp = temp->zero;
                    }
                } else {
                    if (temp->zero && !temp->zero->deleted) {
                        temp = temp->zero;
                        currentAns += (1 << i);
                    } else {
                        temp = temp->one;
                    }
                }
            }
            return currentAns;
        }

        int maxXor(vector<int> arr, int n) {
            int maxVal = 0;
            int l = 0;
            insert(arr[0]);
            for (int i = 1; i < n; i++) {
                while ((l < i) && (2 * arr[l] < arr[i])) {
                    deleteNode(arr[l]);
                    ++l;
                }

                maxVal = max(maxXorHelper(arr[i]), maxVal);
                insert(arr[i]);
            }
            return maxVal;
        }

        ~Trie() {
            // Clean up the trie when the object is destroyed.
            deleteTrie(root);
        }

        void deleteTrie(Node* node) {
            if (node) {
                deleteTrie(node->zero);
                deleteTrie(node->one);
                delete node;
            }
        }
    };
};

