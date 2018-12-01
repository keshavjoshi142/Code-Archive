#include <bits/stdc++.h>

using namespace std;

typedef struct node {
	
	int data;
	struct node * next;
	node(int x) : data(x), next(NULL) {}

}
NODE;


NODE * addNodeAtEnd(NODE* head , int x){
	
	if(head == NULL){
		
		head = new NODE(x);
		return head;

	}

	NODE * h = head;
	while(h->next != NULL)
		h = h->next;

	h->next = new NODE(x);

	return head;
}

void printList(NODE * head) {

	NODE * h = head;
	while(h != NULL){
		
		cout << h->data << " ";
		h = h->next;

	}
}


int main()
{
	NODE * head = NULL;

	int N;
	cin >> N;

	for(int i=0 ; i<N ; i++) {


		int a;
		cin >> a;

		head = addNodeAtEnd(head , a);
	}

	printList(head);
	int k;
	
	if ( N&1 ) {
		k = N/2+1;
	} else {
		k = N/2;
	}

	NODE * cur = head;
	NODE * next = head->next;
	NODE * prev = NULL;

	

	for(int i=0 ; i<k ; i++)
	{	
		cur->next = prev;
		prev = cur;
		//cout << next << endl;
		cur = next;
		next = next->next;
	}

	NODE * st1;
	NODE * st2;

	if( N&1 ) {
		st1 = st2 = prev;
	} else {
		st1 = prev;
		st2 = cur;
	}

	int flag = 0;

	for(int i=0 ; i<k ; i++) {
		
		if(st1->data != st2->data){
			flag = 1;
			break;
		}

		st1 = st1->next;
		st2 = st2->next;
			cout << st1->data << " " << st2->data << endl;
	}

	if(flag == 0)
		cout << "pallindrom" << endl;
	else
		cout << "NOT" << endl;


}