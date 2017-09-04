#include <iostream>

struct Node{
  int _data;
  Node* _left;
  Node* _right;
  //Node* parent;
};

void insertNode(Node* tree, int data)
{
  if(tree == NULL)
    return;
  
  Node* root = tree;
  std::cout << std::endl << "Inserting value " << data << std::endl;
  while(root != NULL){
    if(root->_data > data){  // Insert a node in the left
      if(root->_left == NULL){
        std::cout << "Adding node to the left " << std::endl;
        root->_left = new Node();
        root->_left->_data = data;
        break;
      }
      else{
        std::cout << "Checking the left node " << std::endl;
        root = root->_left;
      }
    }
    else{
      if(root->_right == NULL){
        std::cout << "Adding node to the right " << std::endl;
        root->_right = new Node();
        root->_right->_data = data;
        break;
      }
      else{
        std::cout << "Checking the right node" << std::endl;
        root = root->_right;
      }
    }
  }  
}


// Build a BSTree 
Node* buildTree()
{
  Node* root = new Node();
  for(int i = 1; i < 10; ++i){
    insertNode(root, (i*i));
  }

  // return root;
}

int main()
{
    std::cout << "Hello Pramp!" << std::endl;
    buildTree();
    return 0;
}