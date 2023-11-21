#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool check(TreeNode* p,TreeNode* q){
        if(p && q && p->val == q->val){
            cout << p->val << endl;
            cout << q->val << endl;
            return check(p->left,q->left) || check(p->right,q->right);
        }
        return false;
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(check(p,q)==true){
            return true;
        }
        return false;
}

int main(){
    system("cls");
    TreeNode *a = new TreeNode(1);
    a->left = new TreeNode(2);
    TreeNode*b = new TreeNode(1);
    b->right = new TreeNode(2);
    if(isSameTree(a,b)){
        cout << "y" << endl;
    }
    else cout << "n" << endl;
    return 0;
}