//22520566
//Nguyen Quoc Huy
//Session 01 - Exercise 01
//Notes or Remarks: ......
#include <iostream>
#include <cstdlib>  
#include <ctime>
using namespace std;

class Node {
public:
    Node* next;
    int data;
    Node*random;
    Node(int value) : data(value), next(NULL), random(NULL) {}
};

class SingleLinkedList {
public:
    Node* head;
    SingleLinkedList() : head(NULL) {}

    void addNode(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void display() {
        if (head == NULL) {
            cout << "ham rong";
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    int getLength() {
        int length = 0;
        Node* temp = head;
        while (temp) {
            length++;
            temp = temp->next;
        }
        return length;
    }
 SingleLinkedList addTwoNumbers(SingleLinkedList& list1, SingleLinkedList& list2) {
        Node* cur1 = list1.head;
        Node* cur2 = list2.head;
        SingleLinkedList result;  
        int carry = 0;

        while (cur1!= NULL || cur2 != NULL) {
            int x = 0;
            int y = 0;

            if (cur1 != NULL) {
                x = cur1->data;
            }

            if (cur2 != NULL) {
                y = cur2->data;
            }
			//tinh tong them phan du cua so tiep du
            int sum = carry + x + y;
            //tim phan du ( neu co)
            carry = sum / 10;
            // lay phan du vao linked list moi
            result.addNode(sum % 10);

            if (cur1!= NULL) {
                cur1 = cur1->next;
            }

            if (cur2 != NULL) {
                cur2 = cur2->next;
            }
        }

        if (carry > 0) {
            result.addNode(carry);
        }

        return result;
    }
  SingleLinkedList copyList(){
  	SingleLinkedList newList;
  	Node* curr =head;
  	//step 1: tao dummy Node dang sau Node goc
  	while(curr!=nullptr){
  		Node*copy= new Node(curr->data);
  		copy->next=curr->next;
  		curr->next=copy;
  		curr=copy->next;
	  }
	  //tra curr ve vi tri dau tien
	  curr=head;
	  //Step 2: cho nut copy nhan con tro random cua nut goc
	  while(curr!=nullptr){
	  	Node*copy =curr->next;
	  	if(curr->random!=nullptr){
	  		copy->random=curr->random->next;// curr->random->next vi` giong nhu
			 // tao them node copy vao nut goc nut copy khi nay se tro den phan tu randomCopy 
			 //vd A tro random toi C thi A' tro random toi C'
	  	
		  }
		else{
			copy->random=NULL;
		}	
		curr=copy->next;
	  }
	  //Step 3: tach thanh 2 linkedlist
	  curr = head;
        Node* newHead = NULL;
        Node* newTail = NULL;
        while (curr != NULL) {
            Node* copy = curr->next;// cho nut copy bat dau lai 
            curr->next = copy->next;// loai bo nut copy tu linked list goc
            if (newHead == NULL) {
                newHead = copy;
                newTail = newHead;
            } else {
                newTail->next = copy;
                newTail = newTail->next;
            }
            curr = curr->next;
        }

        newList.head = newHead;
        return newList;
	  
}

   void printListWithRandomPointers() {
        Node* temp = head;
        while (temp != NULL) {
            cout << "Data: " << temp->data;
            if (temp->random != NULL) {
                cout << ", Random: " << temp->random->data;
            } else {
                cout << ", Random: NULL";
            }
            cout << endl;
            temp = temp->next;
        }
    }
 void swapNodes(int x, int y) {
        if (x == y) return;

        Node *prevX = NULL, *currX = head;
        while (currX && currX->data != x) {
            prevX = currX;
            currX = currX->next;
        }

        Node *prevY = NULL, *currY = head;
        while (currY && currY->data != y) {
            prevY = currY;
            currY = currY->next;
        }

        if (!currX || !currY) return;

        if (prevX) {
            prevX->next = currY;
        } else {
            head = currY;
        }

        if (prevY) {
            prevY->next = currX;
        } else {
            head = currX;
        }

        Node* temp = currY->next;
        currY->next = currX->next;
        currX->next = temp;
    }
    void removeNthFromEnd(int n) {
    Node* first = head;
    Node* second = head;

    // Di chuyen con tro first de tao gap voi con tro thu 2
    for (int i = 0; i < n; ++i) {
        if (first == NULL) return;  // neu n out of range cua list thi return
        first = first->next;
    }

    // truong hop remove head
    if (first == NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // sau khi tao gap , cho first cho toi nut cuoi va second di chuyen theo
    while (first->next != NULL) {
        first = first->next;
        second = second->next;
    }

    // remove node qua bien tam temp
    Node* temp = second->next;
    second->next = temp->next;
    delete temp;
}
  void SeparateList(SingleLinkedList& list1, SingleLinkedList& list2) {
        SingleLinkedList oddList;
        SingleLinkedList evenList;
        Node* p = list1.head;
        Node* q = list2.head;

        while (p !=NULL) {
            if (p->data % 2 == 1) {
                oddList.addNode(p->data);
            } else {
                evenList.addNode(p->data);
            }
            p = p->next;
        }

        while (q != NULL) {
            if (q->data % 2 == 1) {
                oddList.addNode(q->data);
            } else {
                evenList.addNode(q->data);
            }
            q = q->next;
        }

        cout << "Odd list:" << endl;
        oddList.display();

        cout << "Even list:" << endl;
        evenList.display();
    }
	void  dividedList(int k){// voi x la so luong phan muon chia
	int length = getLength();
	int partSize =length/k;
	int extraSize=length%k;
		Node* curr =head;
		for(int i = 0 ; i < k;i++){
			int currentSize=partSize;
			//them vao du vao nhung list current dau
			if(extraSize>0){
				currentSize = partSize + 1;
				extraSize--;
			}
			//insert data vao currentSize(i)
			for(int j = 0 ; j < currentSize; j++){
				if(curr!=NULL){
					cout<<curr->data<<" ";
					curr=curr->next;
				}
			}
			cout<<endl;
		}
	}
void removeZeroSum() {
    Node *dummy = new Node(0);
    dummy->next = head;  // Dummy node gi�p don gi?n h�a vi?c x�a node d?u
    Node *curr = dummy;

    // Duy?t qua t?ng node
    while (curr != NULL) {
        Node *runner = curr->next;  // B?t d?u t? node ti?p theo c?a curr
        int sum = 0;
        
        // Duy?t qua danh s�ch d? t�m do?n c� t?ng b?ng 0
        while (runner != NULL) {
            sum += runner->data;
            
            // N?u t?ng b?ng 0, x�a do?n t? curr->next d?n runner
            if (sum == 0) {
                Node *temp = curr->next;
                // xoa cac node
                while (temp != runner) {
                    Node *nodeToDelete = temp;
                    temp = temp->next;
                    delete nodeToDelete;
                }
                // bo qua cac node bi xoa
                curr->next = runner->next;
                break;  // thoat vong lap
            }
            runner = runner->next;
        }
        // Chuyen node tiep theo
        if (runner ==NULL || sum != 0) {
            curr = curr->next;
        }
    }

    head = dummy->next;
    delete dummy;
}
void automaticInput() {
        srand(time(NULL));  

        int numEntries = rand() % 21 + 39;  
        cout << "random number: " << numEntries << endl;

        for (int i = 0; i < numEntries; ++i) {
            int value = rand() % 199 - 99;  
            addNode(value);
        }
    }



};

int main() {
    SingleLinkedList list1,list2,result;
    SingleLinkedList oddList,evenList;	
    Node* mergedList = NULL;
    int choice;
    while (true) {
        cout << "Choose a tasnk:\n";
        cout << "1. Add 2 Numbers\n";
        cout << "2. Copy List With Random Pointers\n";
        cout << "3. Swap Nodes in a Linked List\n";
        cout << "4. Remove the N-th Node from the End of a List\n";
        cout << "5. Separate Odd and Even Nodes in a Linked List Medium\n";
        cout << "6. Divide a Linked List into Parts\n";
        cout << "7. Remove Zero-Sum Consecutive Nodes from a Linked List\n";
        cout << "8. Write a function to input values for a list using the automatic input method, with values selected from the range [-99; 99]. The number of entries is randomly chosen from the range [39; 59] (using a function to insert at the end of the list)\n";
        cout << "9. Stop\n";
        cin >> choice;

        switch (choice) {
            case 1:
            	   cout << "Enter data L1 (-1 to stop):" << endl;
    		while (true) {
	        int x;
	        cin >> x;
	        if (x == -1) break;
	        list1.addNode(x);
		}
		
		    cout << "Enter data L2(-1 to stop):" << endl;
		    while (true) {
		        int x;
		        cin >> x;
		        if (x == -1) break;
		        list2.addNode(x);
		 }
            result = result.addTwoNumbers(list1, list2);
            cout << "Result after adding two numbers: ";
            result.display();
                break;
            case 2:{
            	  cout << "Enter data (-1 to stop):" << endl;
    		while (true) {
	        int x;
	        cin >> x;
	        if (x == -1) break;
	        list1.addNode(x);
		}// xet random pointer 
			list1.head->random = list1.head->next->next; 
			list1.head->next->random = list1.head;      
   			list1.head->next->next->random = list1.head->next; 
                 cout << "Copying list with random pointers..." << endl;
                SingleLinkedList copiedList = list1.copyList();
                cout << "Original list with random pointers:" << endl;
                list1.printListWithRandomPointers();
                cout << "Copied list with random pointers:" << endl;
                copiedList.printListWithRandomPointers();
                break;
        }
            case 3: {
            	cout << "Enter data (-1 to stop):" << endl;
		    	while (true) {
			    int a;
			    cin >> a;
			    if (a == -1) break;
			    list1.addNode(a);
			}
	            int x, y;
    			cout << "Enter the values of the nodes to swap:" << endl;
   				cin >> x >> y;
   				list1.swapNodes(x, y);
    			cout << "List after swapped nodes " << x << " and " << y << ":" << endl;
   				list1.display();
    
	        	break;
            }
            case 4:
			{
			cout << "Enter data (-1 to stop):" << endl;
		    while (true) {
		        int x;
		        cin >> x;
		        if (x == -1) break;
		        list1.addNode(x);
		    }
		
		    int n;
		    cout << "Enter the position from the end to remove:" << endl;
		    cin >> n;
		
		    list1.removeNthFromEnd(n);
		    cout << "List after removing the " << n << "-th node from the end:" << endl;
		    list1.display();

                break;
            }
            case 5: {
                  cout << "Enter data L1 (-1 to stop):" << endl;
                while (true) {
                    int x;
                    cin >> x;
                    if (x == -1) break;
                    list1.addNode(x);
                }

                cout << "Enter data L2(-1 to stop):" << endl;
                while (true) {
                    int x;
                    cin >> x;
                    if (x == -1) break;
                    list2.addNode(x);
                }

                list1.SeparateList(list1, list2);
                
                
                
               break;
            }
            case 6:
               {
               	  cout << "Enter data (-1 to stop):" << endl;
                while (true) {
                    int x;
                    cin >> x;
                    if (x == -1) break;
                    list1.addNode(x);
                }
                cout<<"enter how many part you want:";
                int k ; cin>>k;
                list1.dividedList(k);
               	
               	break;
			   }
				
            case 7:
               {
               	cout << "Enter data (-1 to stop):" << endl;
    while (true) {
        int x;
        cin >> x;
        if (x == -1) break;
        list1.addNode(x);
    }

    cout << "Removing zero-sum consecutive nodes from the list..." << endl;
    list1.removeZeroSum();
    cout << "List after removing zero-sum consecutive nodes: ";
    list1.display();
			   
                break;
            }
            case 8: {
                
                SingleLinkedList list;

		    list.automaticInput();
		
		    // hien thi danh sach
		    cout << "Generate list with random number:" << endl;
		    list.display();
                break;
            }
            case 9:
                exit(0);
            default:
                cout << "Vui long nhap lai.\n";
        }
    }

    return 0;
}

