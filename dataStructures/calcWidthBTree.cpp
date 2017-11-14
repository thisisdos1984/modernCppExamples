int BTree::_calcWidth(Node *root, int count)
{
    if (root == nullptr)
        return 0;
    if (root->left == nullptr && root->right == nullptr)
        return count;

    return (abs(_calcWidth(root->left, count + 1)) + abs (_calcWidth(root->right, count - 1)));
}

int BTree::calcWidth()
{
    return _calcWidth(m_root, 0) + 1;
}


int main(int argc, char *argv[])
{
    // create object of BTree and call the relevant method.    
    return 0;
}