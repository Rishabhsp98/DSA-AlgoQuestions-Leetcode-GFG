void solve(Node *root,int &sum)
{
    if(root == nullptr)
        return;
    if(root->left == nullptr && root->right == nullptr)
        sum +=root->data;
    solve(root->left,sum);
    solve(root->right,sum);
}
int sumOfLeafNodes(Node *root ){
     /*Your code here */
     int sum = 0;
     if(root == nullptr)
        return 0;
     solve(root,sum);
     return sum;
}