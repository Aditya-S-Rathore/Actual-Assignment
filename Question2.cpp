#include<bits/stdc++.h>
using namespace std;
#define int long long int

 struct ListNode {
     int val;
     ListNode *next;
 };
 // Function to create a linked list from an array
ListNode* createLinkedList(vector<int>arr, int n) {
    if (n == 0) return nullptr; 
    ListNode* head = new ListNode();
    ListNode* current = head;
    current->val=arr[0];

    for (int i = 1; i <n; i++) {
        current->next = new ListNode();  
        current = current->next;   
        current->val=arr[i];           
    }
    current->next=NULL;
    return head;  
}

// Function to print the linked list
void printLinkedList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << " ";
        current = current->next;
    }
    cout<< endl;
}

 ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *t1=list1,*t2=list2,*p;
        if(t1==NULL)
        return t2;
        if(t2==NULL)
        return t1;
        while(t1 && t2)
        {
            if(t1->val <= t2->val)
            {
                p=t1;
            t1=t1->next;
            }
            else
            {
            if(t1==list1)
            {
                ListNode* temp=t2;
                t2=t2->next;
                temp->next=t1;
                list1=temp;
                p=temp;
            }
            else
            {
                ListNode* temp=t2;
                t2=t2->next;
                p->next=temp;
                temp->next=t1;
                p=temp;
            }

            }
        }

       if(t2)
       {
        p->next=t2;
       }
        
        
        
        return list1;
    }

int32_t main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int n;
      cin>>n;
      vector<int> a1(n);
      for(int i=0;i<n;i++)
      cin>>a1[i];
       int m;
      cin>>m;
      vector<int> a2(m);
      for(int i=0;i<m;i++)
      cin>>a2[i];

      ListNode* l1=createLinkedList(a1,n);
      ListNode* l2=createLinkedList(a2,m);
     


      ListNode* ans=mergeTwoLists(l1,l2);
      printLinkedList(ans);

    }
    
     
    return 0;
}