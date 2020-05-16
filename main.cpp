#include"BinarySearchTree.cpp"

int main() {

	BST<int> st;
	st.insert(8);
	st.insert(16);
	st.insert(12);
	st.insert(13);
	st.insert(20);
	st.insert(4);
	st.insert(2);
	st.insert(6);
	st.printInorderTraverse();
	st.printPreorderTraverse();
	st.printPostorderTraverse();
	st.printLevelorderTraverse();

	return 0;
}