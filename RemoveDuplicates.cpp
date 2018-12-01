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

NODE  * reverseByK(NODE * head){

	if(head == NULL)
		return NULL;

	if(head->next == NULL)
		return head;

	
	NODE * rem = head->next->next;
	head->next->next = head;
	NODE * h = head;
	head = head->next;
	h->next = reverseByK(rem);

	return head;


}

NODE * sortInsert(NODE * head ,int k)
{
	NODE * newNode = new NODE(k);
	
	if(head == NULL || head->data > k)
	{
		newNode->next = head;
		head = newNode;

		return head;
	}

	NODE * h1 = head;

	while(h1->next != NULL && h1->next->data < k)
	{
		h1 = h1->next;
	}

	NODE * nextNode = h1->next;
	h1->next = newNode;
	newNode->next = nextNode;

	return head; 
}




int main() 
{
	/*NODE * h1 = NULL;
	
	int N , B;

	
	cin >> N;
	
	for(int i=0 ; i<N ; i++) {
		int a;
		cin >> a;
		h1 = addNodeAtEnd(h1 , a);
	}


	NODE * head = h1;
	NODE * ansHead = NULL;

	while(h1 != NULL)
	{
		ansHead = sortInsert(ansHead , h1->data);
		h1 = h1->next;
	}

	printList(ansHead);*/

	int n;
	cin >> n;

	vector < int > A;

	for(int i=0 ; i< n ; i++)
	{
		int a;
		cin >> a;
		A.push_back(a);
	}

	stack < int > st;

	vector < int > ans(n);

	st.push(A[0]);
	ans[0] = -1;

	for(int i=1 ; i<n ; i++)
	{
	   cout << st.top() << endl;
		if(st.top() < A[i])
		{	
			ans[i] = st.top();
			st.push(A[i]);
		}
		else{
			while(!st.empty() && st.top() >= A[i])
				st.pop();

			if(st.empty())
			{
				ans[i] = -1;
				st.push(A[i]);
			}
			else{

				ans[i] = st.top();
				st.push(A[i]);
			}
		}
	}
	

	
	for(int i=0 ; i<n ; i++)
		cout << ans[i] << " ";

	cout << endl;



	
}


