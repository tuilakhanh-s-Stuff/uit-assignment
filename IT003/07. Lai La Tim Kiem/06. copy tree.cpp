/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
};

//###INSERT CODE HERE -
void copy(Node *root, Node *&root_new) {
 	if (root == NULL)
	 	return;
	
 	root_new = new Node;
   	root_new->val = root->val;
   	root_new->left = root_new->right = NULL;

	copy(root->left, root_new->left);
	copy(root->right, root_new->right);
}

int main()
{
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);

    Node* root = NULL, *r2=NULL;

    while(true){
        int x; cin >> x;
        if (x == 0) break;
        /* Hàm add thêm số nguyên x vào cây nhị phân theo nguyên tắc riêng
        * Hàm này đã được viết đầy đủ
        * sinh viên không cần viết hàm này
        */ 
        add(root, x); 
    }

    copy(root, r2); //Cần phải viết hàm này

    /* Hàm check kiểm tra lại 02 cây sau khi copy
    * Hàm này đã được viết đầy đủ
    * sinh viên không cần viết hàm này
    **/
    check(root, r2);

    return 0;
}


