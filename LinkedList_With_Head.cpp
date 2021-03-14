#include<iostream>
/* Implementacja listy wiązanej z głową.
 * 1. addLast -  dodaje na koniec listy element
 * 2. contain - sprawdza czy lista zawiera element o nazwie n
 * 3. remove - usuwa pierwsze wystapienie elementu o nazwie n
 * 4. removeAll - usuwa wszystkie wystapienia elementu o nazwie n
 * 5. length - zwraca dlugosc listy
 * 6. isEmpty - sprawdza czy lista jest pusta
 * 7. clear - usuwa wszystkie elementy z listy
 * 8. indexOf - zwraca indeks elementu o nazwie n
 * 9. add_index - dodaje elemnt e na pozycje o indeksie n
 * 10. removeRep - usuwa wszystkie powtórzenia
 * 11. rverse - odwraca tablice
 * 12. toArray - zwraca tablice zawieracja wszystkie elementy*/

struct node {
    std::string data;
    struct node *next;
};

//1
void addLast(struct node **head, std::string e) {

    struct node *newNode = new node;
    newNode->data = e;
    newNode->next = nullptr;


    if (*head == nullptr)
        *head = newNode;

    else {
        struct node *lastNode = *head;


        while (lastNode->next != nullptr) {
            lastNode = lastNode->next;
        }


        lastNode->next = newNode;
    }

}
//2
bool contain(struct node *head, std::string n) {
    struct node *temp = head;

    while (temp != nullptr) {
        if (temp->data == n)
            return true;
        temp = temp->next;
    }
    return false;
}
//3
void remove(struct node **head, std::string n) {
    struct node *temp;

    if ((*head)->data == n) {
        temp = *head;
        *head = (*head)->next;
        delete temp;
    } else {
        struct node *current = *head;
        while (current->next != nullptr) {
            if (current->next->data == n) {
                temp = current->next;
                current->next = current->next->next;
                delete temp;
                break;
            } else
                current = current->next;
        }
    }

}
//4
void removeAll(struct node **head, std::string n) {
    struct node *temp;

    if ((*head)->data == n) {
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }

    struct node *current = *head;
    while (current->next != nullptr) {
        if (current->next->data == n) {
            temp = current->next;
            current->next = current->next->next;
            delete temp;
        } else
            current = current->next;

    }

}
//5
int length(struct node *head) {
    struct node *temp = head;
    int i = 0;

    while (temp != nullptr) {
        temp = temp->next;
        i++;
    }
    return i;

}
//6
bool isEmpty(struct node **head) {
    if (*head == nullptr)
        return true;
    return false;

}
//7
void clear(struct node **head) {
    struct node *temp;
    while ((*head) != nullptr) {
        temp = *head;
        *head = (*head)->next;
        delete temp;
    }
}

//8
int indexOf(struct node *head, std::string n) {
    struct node *temp = head;
    int index = 0;
    while (temp != nullptr) {
        if (temp->data == n)
            return index;
        else {
            temp = temp->next;
            index++;
        }
    }
    return index;
}
//9
void add_index(struct node **head, std::string e, int n) {
    struct node *pointer = *head, *prev;
    int i = -1;

    while (pointer != nullptr && i != n - 1) {
        prev = pointer;
        pointer = pointer->next;
        i++;
    }

    struct node *newNode = new node;
    newNode->data = e;
    newNode->next = prev->next;
    prev->next = newNode;

}
//10
void removeRep(struct node **head) {
    struct node *pointer, *duplicate, *tmp;
    pointer = *head;
    while (pointer->next != nullptr) {
        struct node *tmp = pointer;
        while (tmp->next != nullptr) {
            if (tmp->next->data == pointer->data) {
                duplicate = tmp->next;
                tmp->next = tmp->next->next;
                delete duplicate;
            } else
                tmp = tmp->next;
        }

        pointer = pointer->next;
    }
}
//11
void reverse(struct node **head) {
    node *current = *head;
    node *prev = nullptr;
    node *next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}
//12
std::string *toArray(struct node *head, int n) {
    std::string *array = new std::string[n];
    int i = 0;
    struct node *temp = head;

    while (temp != nullptr) {
        *(array + i) = temp->data;
        temp = temp->next;
        i++;
    }
    return array;
}

void displayArray(std::string *A, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << *(A + i) << "  ";
    }
    std::cout << std::endl;
}

void printList(struct node *head) {
    struct node *temp = head;

    while (temp != nullptr) {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    }
    std::cout << "null\n" << std::endl;
}

int main() {
    struct node *head = nullptr;
    //test reverse
    /*   {
           addLast(&head, "10");
           addLast(&head, "20");
           addLast(&head, "30");
           reverse(&head);
           printList(head);
       } */

    //test contain
    /*   {
           addLast(&head, "10");
           addLast(&head, "20");
           addLast(&head, "30");
          std::cout << contain(head, "10") << std::endl;

       } */

    //test length
    /*   {
           addLast(&head, "10");
           addLast(&head, "20");
           addLast(&head, "30");
           std::cout << length(head) << std::endl;
       } */

    //test isEmpty
    /*   {
          addLast(&head, "10");
           addLast(&head, "20");
           addLast(&head, "30");
           std::cout << isEmpty(&head) << std::endl;
       } */

    //test clear
/*    {
        addLast(&head, "10");
        addLast(&head, "20");
        addLast(&head, "30");
        clear(&head);
        printList(head);
    } */
    //test indexOf

/*    {
        addLast(&head, "10");
        addLast(&head, "20");
        addLast(&head, "30");
        addLast(&head, "40");
        addLast(&head, "50");
        addLast(&head, "60");
        addLast(&head, "70");
        addLast(&head, "80");
       std::cout <<  indexOf(head, "50") << std::endl;

    } */

    //test toArray
    /*   {
           addLast(&head, "10");
           addLast(&head, "20");
           addLast(&head, "30");
           addLast(&head, "40");
           addLast(&head, "50");
           addLast(&head, "60");
           addLast(&head, "70");
           addLast(&head, "80");
           std::string *A = toArray(head, length(head));
           displayArray(A,length(head));
       } */

    //test removeRep
    /*     {
              addLast(&head, "10");
              addLast(&head, "50");
              addLast(&head, "50");
              addLast(&head, "40");
              addLast(&head, "50");
              addLast(&head, "60");
              addLast(&head, "50");
              addLast(&head, "80");
              removeRep(&head);
              printList(head);
          } */

    //test add_index
    /*  {
          addLast(&head, "10");
          addLast(&head, "50");
          addLast(&head, "50");
          addLast(&head, "40");
          addLast(&head, "50");
          addLast(&head, "60");
          addLast(&head, "50");
          addLast(&head, "80");
        //  add_index(&head, "130", 2);
          add_index(&head, "140", 8);
          printList(head);
      } */

    //test remove
    /*   {
           addLast(&head, "10");
           addLast(&head, "50");
           addLast(&head, "50");
           addLast(&head, "40");
           addLast(&head, "50");
           addLast(&head, "60");
           addLast(&head, "50");
           addLast(&head, "80");
           remove(&head, "40");
           remove(&head, "80");
           printList(head);
       } */

    //test removeAll
    {
        addLast(&head, "10");
        addLast(&head, "50");
        addLast(&head, "50");
        addLast(&head, "40");
        addLast(&head, "50");
        addLast(&head, "60");
        addLast(&head, "50");
        addLast(&head, "80");
        removeAll(&head, "50");

        printList(head);
    }
    return 0;
}