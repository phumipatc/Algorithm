/*
	Task		: Singly Linked List
	Author		: Phumipat C.
	Language	: C++
	Explanation	: 
*/
#include <iostream>
using namespace std;

struct Node{
	int data;
	Node *next;
	Node(int val){
		data = val;
		next = NULL;
	}
};

Node *create_node(int val){
	Node *new_node = new Node(val);
	return new_node;
}

void insert_node_after(Node *prev_node, int val){
	if(prev_node == NULL){
		cout << "The given previous node cannot be NULL";
		return ;
	}
	Node *new_node = create_node(val);
	new_node->next = prev_node->next;
	prev_node->next = new_node;
}

Node *move_backward(Node *node_to_move, Node *head){
	if(node_to_move == NULL){
		cout << "The given node cannot be NULL";
		return node_to_move;
	}

	Node *current = head;
	while(current != NULL && current->next != node_to_move){
		current = current->next;
	}
	return current;
}

Node *move_forward(Node *node_to_move){
	if(node_to_move == NULL || node_to_move->next == NULL){
		cout << "The given node cannot be NULL or the last node";
		return node_to_move;
	}

	Node *next_node = node_to_move->next;
	return next_node;
}

Node *move_to_front(Node *node_to_move, Node *head){
	if(node_to_move == NULL){
		cout << "The given node cannot be NULL";
		return node_to_move;
	}

	return node_to_move = head;
}

Node *move_to_end(Node *node_to_move){
	if(node_to_move == NULL){
		cout << "The given node cannot be NULL";
		return node_to_move;
	}

	while(node_to_move->next != NULL){
		node_to_move = move_forward(node_to_move);
	}
	return node_to_move;
}

void PrintCurrentNode(Node *current){
	if(current == NULL){
		cout << "The given node cannot be NULL";
		return ;
	}
	cout << current->data << "\n";
}

int main()
{
	// Linked list: 1
	Node *head = create_node(1);
	Node *current = head;

	// Linked list: 1 2
	insert_node_after(current, 2);

	// current pointing to 2
	current = move_forward(current);

	// Linked list: 1 2 3
	insert_node_after(current, 3);

	// current pointing to 1
	current = move_to_front(current, head);

	// Linked list: 1 4 2 3
	insert_node_after(current, 4);

	// current pointing to 3
	current = move_to_end(current);

	// Linked list: 1 4 2 3 5
	insert_node_after(current, 5);

	return 0;
}
