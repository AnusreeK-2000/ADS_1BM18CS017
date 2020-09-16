#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    struct Node* next; 
}; 
  
struct Node* reverse (struct Node* head, int k)  
{  
    Node* curr = head;  
    Node* next = NULL;  
    Node* prev = NULL;  
    int count = 0;  

    while (curr != NULL && count < k)  
    {  
        next = curr->next;  
        curr->next = prev;  
        prev = curr;  
        curr = next;  
        count++;  
    }  

    if (next != NULL)  
    head->next = reverse(next, k);  
  
    return prev;  
}  

struct Node* insert(struct Node* head, int val) 
{ 
    struct Node* newn =  
          (struct Node*)malloc(sizeof(struct Node)); 
    newn->data = val; 
    newn->next = NULL; 
    if(head == NULL){
        return newn;
    }
    struct Node* curr = head;
    while(curr->next != NULL){
        curr = curr->next;
    }
    curr->next = newn;
    return head;

} 
int main() {
	int n,k;
	cout<<"Enter the no. of elements"<<endl;
	cin>>n;
	int val;
	struct Node* head = NULL;
	cout<<"Enter the elements"<<endl;
	for(int i = 0; i < n; i++){
	    cin>>val;
	   head = insert(head, val);
	}
	cout<<"Enter k value"<<endl;
	cin>>k;
	head = reverse(head, k);
	while(head!=NULL){
	    cout<<head->data<<" ";
	    head = head->next;
	}
	return 0;
}
