#include <iostream>
#include <queue>

// Define the structure of a tree node
struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to display all nodes at one level of the tree
void levelOrderTraverse(TreeNode *root)
{
    if (!root)
    {
        std::cout << "Tree is empty." << std::endl;
        return;
    }

    // Queue for level order traversal
    std::queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        int levelSize = nodeQueue.size(); // Number of nodes at the current level

        // Iterate through nodes at the current level
        for (int i = 0; i < levelSize; ++i)
        {
            TreeNode *currentNode = nodeQueue.front();
            nodeQueue.pop();

            // Print the value of the current node
            std::cout << currentNode->value << " ";

            // Add left and right children to the queue
            if (currentNode->left)
            {
                nodeQueue.push(currentNode->left);
            }
            if (currentNode->right)
            {
                nodeQueue.push(currentNode->right);
            }
        }

        // Move to the next level
        std::cout << std::endl;
    }
}

int main()
{
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Display nodes at each level
    std::cout << "Nodes at each level:" << std::endl;
    levelOrderTraverse(root);

    // Free allocated memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
