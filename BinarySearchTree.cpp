#include"BinarySearchTree.h"
#include<queue>


template<class T>
BST<T>::BST()
	: root_(nullptr)
{}


template<class T>
BST<T>::BST(const BST& st) 
	: root_(nullptr)
{
	copy(st.root_);
}


template<class T>
BST<T>::BST(BST&& st)
	: root_(nullptr)
{
	root_ = st.root_;
	st.root_ = nullptr;
	cout << "move" << endl;
}

template<class T>
BST<T>& BST<T>::operator = (const BST<T>& st) {
	if (this != &st) {
		clear(root_);
		copy(st.root_);
	}
	return *this;
}

template<class T>
BST<T>& BST<T>::operator = (BST<T>&& st) {
	if (this != &st) {
		clear(root_);
		root_ = st.root_;
		st.root_ = nullptr;
	}
	cout << "move =" << endl;
	return *this;
}

template<class T>
BST<T>::~BST() {
	clear(root_);
}

template<class T>
void BST<T>::insert(const T& info) {
	BSTNode<T>* parent = nullptr;
	travel(info, parent);
	if (parent == nullptr) {
		root_ = new BSTNode<T>(info);
	}
	else {
		if (info > parent->info_)
			parent->right_ = new BSTNode<T>(info);
		else
			parent->left_ = new BSTNode<T>(info);
	}
}

template<class T>
void BST<T>::remove(const T& info) {
	BSTNode<T>* parent = nullptr;
	BSTNode<T>* current = travel(info, parent); 
	if (current) {
		BSTNode<T>* tempo = current;
		if (current->left_ && current->right_) {
			current = current->right_;
			while (current->left_) {
				parent = current;
				current = current->left_;
			}
			tempo->info_ = current->info_;
			parent->left_ = current->right_;
		}
		else if (current->left_) {
			parent->left_ = current->left_;
		}
		else {
			parent->right_ = current->right_;
		}
		delete current;
	}
}

template<class T>
bool BST<T>::find(const T& info) {
	BSTNode<T>* parent  = nullptr;
	BSTNode<T>* current = travel(info, parent);
	return current;
}

template<class T>
bool BST<T>::empty()const {
	return !root_;
}

template<class T>
void BST<T>::printPreorderTraverse() {
	cout << "Preorde   :";
	preor(root_);
	cout << endl;
}


template<class T>
void BST<T>::printInorderTraverse() {
	cout << "Inorde    :";
	inor(root_);
	cout << endl;
}

template<class T>
void BST<T>::printPostorderTraverse() {
	cout << "Postorde  :";
	postor(root_);
	cout << endl;
}

template<class T>
void BST<T>::printLevelorderTraverse() {
	cout << "Levelorde :";
	levelor(root_);
	cout << endl;
}


template<class T>
void BST<T>::preor(BSTNode<T>* node) {
	if (node == nullptr)return;
	cout << node->info_ << ",";
	preor(node->left_);
	preor(node->right_);
}


template<class T>
void BST<T>::inor(BSTNode<T>* node) {
	if (node == nullptr) return;
	inor(node->left_);
	cout << node->info_ << ",";
	inor(node->right_);
}


template<class T>
void BST<T>::postor(BSTNode<T>* node) {
	if (node == nullptr) return;
	postor(node->left_);
	postor(node->right_);
	cout << node->info_ << ",";
}

template<class T>
void BST<T>::levelor(BSTNode<T>* node) {
	if (node == nullptr) return;
	BSTNode<T>* current = node;
	queue<BSTNode<T>*>  q;
	q.push(node);
	while (!q.empty()) {
		current = q.front();
		cout << current->info_ << ",";
		q.pop();
		if (current->left_) {
			q.push(current->left_);
		}
		if (current->right_) {
			q.push(current->right_);
		}
	}
}

template<class T>
void BST<T>::copy(BSTNode<T>* from) {
	if(from){
		insert(from->info_);
		copy(from->left_);
		copy(from->right_);
	}
}

template<class T>
void BST<T>::clear(BSTNode<T>* node) {
	if (node) {
		clear(node->left_);
		clear(node->right_);
		delete node;
	}
}

template<class T>
BSTNode<T>* BST<T>::travel(const T& info,BSTNode<T>* &parent) {
	BSTNode<T>* current = root_;
	parent = nullptr;
	while (current != nullptr && current->info_ != info) {
		parent = current;
		current = (info > current->info_ ? current->right_ : current->left_);
	}
	return current;
}




