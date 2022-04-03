#include "assignment/binary_search_tree.hpp"

namespace assignment {

  BinarySearchTree::~BinarySearchTree() {
    BinarySearchTree::Clear();
  }

  void BinarySearchTree::Insert(int key, int value) {
    // Write your code here...
    insert(key, value, root_);
  }

  bool BinarySearchTree::Remove(int key) {
    // Write your code here...
    return remove(key, root_);
  }

  void BinarySearchTree::Clear() {
    // Write your code here...
      if (!IsEmpty()) clear(root_);
      root_ = nullptr;
  }

  std::optional<int> BinarySearchTree::Find(int key) const {
    // Write your code here...
    Node* requiredNode = find(key, root_);
    if (requiredNode != nullptr) {
      return requiredNode->value;
    }
    return std::nullopt;
  }

  bool BinarySearchTree::Contains(int key) const {
    // Write your code here...
    return (Find(key) != std::nullopt);
  }

  bool BinarySearchTree::IsEmpty() const {
    return (root_ == nullptr);
  }

  std::optional<int> BinarySearchTree::FindMin() const {
    // Write your code here...
    if (IsEmpty()) {
      return std::nullopt;
    }
    return find_min(root_)->value;
  }

  std::optional<int> BinarySearchTree::FindMax() const {
    // Write your code here...
    if (IsEmpty()) {
      return std::nullopt;
    }
    return find_max(root_)->value;
  }

  Node* BinarySearchTree::root() const {
    return root_;
  }

  // вспомогательные методы

  void BinarySearchTree::insert(int key, int value, Node*& node) {
    // Write your code here ...
    if (node == nullptr) {
      node = new Node(key, value);
    }

    if (key == node->key) {
      node->value = value;
    } else {
      insert(key, value, (key < node->key) ? node->left : node->right);
    }
  }

  bool BinarySearchTree::remove(int key, Node*& node) {
    // Write your code here...
    if (node == nullptr) return false;

    if (key > node->key){
      return remove(key,node->right);
    }
    if (key < node->key){
      return remove(key,node->left);
    }

    if (node->left == nullptr && node->right == nullptr){
      delete node;
      node = nullptr;
      return true;
    }
    if (node->right != nullptr && node->left != nullptr){
      Node* newRoot = find_min(node->right);
      node->value = newRoot->value;
      node->key = newRoot->key;
      return remove(node->key, node->right);
    }

    Node* toDeleteNode = node;
    if (node->left != nullptr){
      node = node->left;
      delete toDeleteNode;
      return true;
    }
    if (node->right != nullptr) {
      node = node->right;
      delete toDeleteNode;
      return true;
    }
  }

  void BinarySearchTree::clear(Node* node) {
    // Write your code here...
    if (node->left != nullptr) {
      clear(node->left);
      node->left = nullptr;
    }
    if (node->right != nullptr) {
      clear(node->right);
      node->right = nullptr;
    }
    delete node;
  }

  Node* BinarySearchTree::find(int key, Node* node) const {
    // Write your code here...
    if (node == nullptr) {
      return nullptr;
    }
    if (node->key == key) {
      return node;
    }
    return (key < node->key) ? find(key, node->left) : find(key, node->right);
  }

  Node* BinarySearchTree::find_min(Node* node) const {
    // Write your code here...
    return (node->left != nullptr) ? find_min(node->left) : node;
  }

  Node* BinarySearchTree::find_max(Node* node) const {
    // Write your code here...
    return (node->right != nullptr) ? find_max(node->right) : node;
  }

}  // namespace assignment