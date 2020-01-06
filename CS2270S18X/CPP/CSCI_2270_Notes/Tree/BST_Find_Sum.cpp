int findSum(TreeNode * root, int depth)
{
    if(root != NULL)
    {
       int leftSum = findSum(root->left, depth + 1);
       int rightSum = findSum(root->right, depth + 1);
       cout << root->key;
       if (depth != 0)
       {
          cout << " ";
       }
       return leftSum + rightSum + root->key;
    }
    else
       return 0;
}