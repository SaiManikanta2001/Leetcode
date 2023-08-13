// #include<bits/stdc++.h>
// using namespace std;
// int main() {
    // int num = 88;
    // int *p = &num;
    // cout<<p<<endl;
    // cout<<*p<<endl;

    // int *p = nullptr;
    // p = new int;
    // *p = 77;
    // cout<<*p<<endl;
    // cout<<&p;
    // delete p;
    // p = nullptr;

    // for(size_t i=0;i<10;i++) {
    //     try {
    //         int *data = new int[100000000];
    //     }
    //     catch(exception & exp) {
    //         cout<<"Something went wrong"<<exp.what();
    //     }
    // }

    // cout<<"Code has completed";

    // int *p = nullptr;
    // p = new int(7);
    // cout<<p<<endl;
    // cout<<*p<<endl;
    // cout<<&p<<endl;

    // int num = 7;
    // cout<<&num;

    // int *p;
    // int (*ptr)[5];
    // int arr[5] = {1,2,3,4,5};
    // p = arr; // pointing to the first element 
    // ptr = &arr; // pointing to the whole array
    // for(int i=0;i<5;i++) {
    //     cout<<*(ptr + i)<<endl;
    // }

    
//     return 0;
// }

// #include<bits/stdc++.h>

// using namespace std;

// struct Node {
//     int val;
//     Node *next;
// };

// Node* frontadd(Node* front, int val) {
//     Node* newnode = new Node;
//     newnode->val = val;
//     newnode->next = front;
//     return newnode;
// }

// Node* backadd(Node* back, int val) {
//     Node* newnode = new Node;
//     newnode->val = val;
//     newnode->next=NULL;
//     back->next = newnode;
//     return newnode;
// }

// void printList(Node* front)
// {
//     while(front!=NULL) {
//     cout<<front->val<<endl;
//     front = front->next;
//     }
// }

// Node* deleteEle(int val, Node* &front) {
//     Node* temp = front;
//     if(val == front->val) {
//         Node* newFront = front->next;
//         delete front;
//         return newFront;
//     }
//     while(temp->next->val!=val) {
//         temp = temp->next;
//     }
//     Node* it = temp->next;
//     temp->next = temp->next->next;
//     delete it;
// }

// int main() {
//     Node *front=NULL, *back=NULL;
//     Node* firstnode = new Node;
//     firstnode -> val = 0;
//     firstnode->next = NULL;
//     front=back=firstnode;
//     front = frontadd(front,8);
//     back = backadd(back,10);
//     deleteEle(8,front);
//     printList(front);
//     return 0;
// }

#include<bits/stdc++.h>

using namespace std;

int main() {
    // int num = 6;
    // double num1 = 8;

    // int& reference_to_num{num};
    // double& refernce_to_double{num1};

    // cout<<num<<endl;
    // cout<<&num<<endl;
    // cout<<num1<<endl;
    // cout<<&num1<<endl;

    // cout<<"==================="<<endl;

    // cout<<reference_to_num<<endl;
    // cout<<&reference_to_num<<endl;
    // cout<<refernce_to_double<<endl;
    // cout<<&refernce_to_double<<endl;

    // return 0;

    int num =2;
    int *p = &num;
    cout<<p<<endl;
    cout<<*p<<endl;
    int num2 = 3;
    p=&num2;
    cout<<p<<endl;
    cout<<*p<<endl;
    return 0;
}
