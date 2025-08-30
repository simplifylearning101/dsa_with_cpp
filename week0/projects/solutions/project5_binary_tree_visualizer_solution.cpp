#include <iostream>  // For input/output operations
#include <vector>    // For storing multiple values

// Abstract base class for tree nodes
class TreeNode {
protected:
    int value;
public:
    TreeNode(int v) : value(v) {}
    virtual void inorder() = 0;
    virtual void preorder() = 0;
    virtual void postorder() = 0;
    virtual bool compare(const TreeNode* other) const = 0;
    virtual TreeNode* merge(const TreeNode* other) = 0;
    virtual ~TreeNode() {}
    int getValue() const { return value; }
};

// Binary tree node class
class BinaryNode : public TreeNode {
private:
    BinaryNode* left;
    BinaryNode* right;
public:
    BinaryNode(int v) : TreeNode(v), left(nullptr), right(nullptr) {}
    ~BinaryNode() {
        delete left;
        delete right;
    }
    
    // Recursive inorder traversal
    void inorder() override {
        if (left) left->inorder();
        std::cout << value << " ";
        if (right) right->inorder();
    }
    
    // Recursive preorder traversal
    void preorder() override {
        std::cout << value << " ";
        if (left) left->preorder();
        if (right) right->preorder();
    }
    
    // Recursive postorder traversal
    void postorder() override {
        if (left) left->postorder();
        if (right) right->postorder();
        std::cout << value << " ";
    }
    
    // Compare trees recursively
    bool compare(const TreeNode* other) const override {
        auto* o = dynamic_cast<const BinaryNode*>(other);
        if (!o || value != o->value) return false;
        bool leftEq = (left == nullptr && o->left == nullptr) || 
                      (left && o->left && left->compare(o->left));
        bool rightEq = (right == nullptr && o->right == nullptr) || 
                       (right && o->right && right->compare(o->right));
        return leftEq && rightEq;
    }
    
    // Merge trees by adding other as right subtree
    TreeNode* merge(const TreeNode* other) override {
        BinaryNode* newNode = new BinaryNode(value);
        newNode->left = left ? dynamic_cast<BinaryNode*>(left->merge(nullptr)) : nullptr;
        newNode->right = dynamic_cast<const BinaryNode*>(other);
        return newNode;
    }
    
    // Insert single value
    void insert(int val) {
        if (val < value) {
            if (!left) left = new BinaryNode(val);
            else left->insert(val);
        } else {
            if (!right) right = new BinaryNode(val);
            else right->insert(val);
        }
    }
    
    // Insert multiple values (overloaded)
    void insert(const std::vector<int>& values) {
        for (int val : values) insert(val);
    }
};

// Binary tree class
class BinaryTree {
private:
    BinaryNode* root;
public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { delete root; }
    
    // Overloaded insert
    void insert(int val) {
        if (!root) root = new BinaryNode(val);
        else root->insert(val);
    }
    void insert(const std::vector<int>& values) {
        for (int val : values) insert(val);
    }
    
    void inorder() const { 
        if (root) root->inorder(); 
        std::cout << "\n"; 
    }
    void preorder() const { 
        if (root) root->preorder(); 
        std::cout << "\n"; 
    }
    void postorder() const { 
        if (root) root->postorder(); 
        std::cout << "\n"; 
    }
    
    // Overload + to merge trees
    BinaryTree operator+(const BinaryTree& other) const {
        BinaryTree result;
        if (root && other.root) {
            result.root = dynamic_cast<BinaryNode*>(root->merge(other.root));
        }
        return result;
    }
    
    // Overload == to compare trees
    bool operator==(const BinaryTree& other) const {
        if (!root && !other.root) return true;
        if (!root || !other.root) return false;
        return root->compare(other.root);
    }
};

// Menu-driven interface
void menu(std::vector<BinaryTree*>& trees, int& count, int capacity) {
    while (true) {
        std::cout << "\n1. Create Tree\n2. Insert Value\n3. Insert Multiple Values\n"
                  << "4. Inorder Traversal\n5. Preorder Traversal\n6. Postorder Traversal\n"
                  << "7. Merge Trees\n8. Compare Trees\n9. Exit\nOption: ";
        int choice;
        std::cin >> choice;
        
        if (choice == 9) break;
        
        if (choice == 1) {
            if (count >= capacity) {
                std::cout << "Tree array full\n";
                continue;
            }
            trees[count++] = new BinaryTree();
            std::cout << "Tree created\n";
        }
        else if (choice == 2) {
            int treeIdx, val;
            std::cout << "Enter tree index (0-" << count-1 << ") and value: ";
            std::cin >> treeIdx >> val;
            if (treeIdx >= 0 && treeIdx < count) {
                trees[treeIdx]->insert(val);
                std::cout << "Value inserted\n";
            } else {
                std::cout << "Invalid tree index\n";
            }
        }
        else if (choice == 3) {
            int treeIdx, n;
            std::cout << "Enter tree index (0-" << count-1 << ") and number of values: ";
            std::cin >> treeIdx >> n;
            if (treeIdx >= 0 && treeIdx < count) {
                std::vector<int> values(n);
                std::cout << "Enter " << n << " values: ";
                for (int i = 0; i < n; i++) std::cin >> values[i];
                trees[treeIdx]->insert(values);
                std::cout << "Values inserted\n";
            } else {
                std::cout << "Invalid tree index\n";
            }
        }
        else if (choice == 4) {
            int treeIdx;
            std::cout << "Enter tree index (0-" << count-1 << "): ";
            std::cin >> treeIdx;
            if (treeIdx >= 0 && treeIdx < count) {
                std::cout << "Inorder: ";
                trees[treeIdx]->inorder();
            } else {
                std::cout << "Invalid tree index\n";
            }
        }
        else if (choice == 5) {
            int treeIdx;
            std::cout << "Enter tree index (0-" << count-1 << "): ";
            std::cin >> treeIdx;
            if (treeIdx >= 0 && treeIdx < count) {
                std::cout << "Preorder: ";
                trees[treeIdx]->preorder();
            } else {
                std::cout << "Invalid tree index\n";
            }
        }
        else if (choice == 6) {
            int treeIdx;
            std::cout << "Enter tree index (0-" << count-1 << "): ";
            std::cin >> treeIdx;
            if (treeIdx >= 0 && treeIdx < count) {
                std::cout << "Postorder: ";
                trees[treeIdx]->postorder();
            } else {
                std::cout << "Invalid tree index\n";
            }
        }
        else if (choice == 7) {
            int idx1, idx2;
            std::cout << "Enter two tree indices (0-" << count-1 << "): ";
            std::cin >> idx1 >> idx2;
            if (idx1 >= 0 && idx1 < count && idx2 >= 0 && idx2 < count && count < capacity) {
                trees[count++] = new BinaryTree(*trees[idx1] + *trees[idx2]);
                std::cout << "Trees merged\n";
            } else {
                std::cout << "Invalid indices or array full\n";
            }
        }
        else if (choice == 8) {
            int idx1, idx2;
            std::cout << "Enter two tree indices (0-" << count-1 << "): ";
            std::cin >> idx1 >> idx2;
            if (idx1 >= 0 && idx1 < count && idx2 >= 0 && idx2 < count) {
                std::cout << (*trees[idx1] == *trees[idx2] ? "Trees are equal" : "Trees are not equal") << "\n";
            } else {
                std::cout << "Invalid indices\n";
            }
        }
        else {
            std::cout << "Invalid option\n";
        }
    }
}

int main() {
    const int capacity = 10;
    std::vector<BinaryTree*> trees(capacity, nullptr);
    int count = 0;
    menu(trees, count, capacity);
    for (int i = 0; i < count; i++) delete trees[i];
    return 0;
}