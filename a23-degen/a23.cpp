#include "a23.h"

int A23::isRotationPossible(NoA23* p, NoA23* r) {
    if (p != r) {   //p will be equal to r only once when r is the raiz.
        if (p->n == 1) {    //Parent is a 2 node
            //If UNDERFLOW had occured at r
            if( r->n == 0 )
            {
                if ( (p->esq == r) && (p->mid->n == 2) )  //If deficiency was occured on esq filho
                    return 2;           // 2 indicates anti-clockwise(esq) rotation is to be done

                else if ( (p->mid == r) && ( p->esq->n == 2) )    //If deficiency was occured on mid filho
                    return 1;           // 1 indicates clockwise(dir) rotation is to be done
            }

            //If OVERFLOW had occured at r
            else
            {
                if (! ((p->esq->n == 2) && (p->mid->n == 2)))   //One has to be a 2 node and other a 3 node
                {
                    if (p->esq == r)
                        return 1;            // 1 indicates clockwise(dir) rotation is to be done

                    else
                        return 2;             // 2 indicates anti-clockwise(esq) rotation is to be done
                }
            }
        }


        else {               //Parent is a 3 node
            if (r->n == 0)    //If UNDERFLOW had occurred at r
            {
                if ( (p->esq == r) && (p->mid->n == 2) )  //If deficiency is created on esq filho
                {
                    return 2;   // 2 indicates anti-clockwise(esq) rotation is to be done
                }

                else if (p->mid == r)      //If deficiency is created on mid filho
                {
                    if (p->esq->n == 2)
                        return 1;           // 1 indicates clockwise(dir) rotation is to be done

                    else if (p->dir->n == 2)
                        return 2;           // 2 indicates anti-clockwise(esq) rotation is to be done
                }

                else                    //If deficiency is created on dir filho
                {
                    if ( p->mid->n == 2)
                        return 1;         // 1 indicates clockwise(dir) rotation is to be done
                }
            }


            else                //If OVERFLOW had occured at r
            {
                if ( (p->esq == r) && (p->mid->n == 1) )
                    return 1;          // 1 indicates clockwise(dir) rotation is to be done


                else if (p->mid == r)
                {
                    if (p->esq->n == 1)
                        return 2;           // 2 indicates anti-clockwise(esq) rotation is to be done

                    else if (p->dir->n == 1)
                        return 1;           // 1 indicates clockwise(dir) rotation is to be done
                }

                else
                {
                    if (p->mid->n == 1)
                        return 2;           // 2 indicates anti-clockwise(esq) rotation is to be done
                }
            }
        }
    }

    return 0;   //No rotation
}
AuxA23 A23::rotateRight (NoA23* p, NoA23* r, std::string d, NoA23* filho) {
    //CASE 1 :  If the rotation is done to overcome the UNDERFLOW at r
    if (r->n == 0)
    {
        if ( (p->n == 2) && ( p->dir == r) )       //If parent is a 3 node and deficiency is created on its dir filho
        {
            r->key1 = p->key2;              //Separator Key
            r->n = 1;

            p->key2 = p->mid->key2;

            p->mid->n = 1;

            //Updating Pointers

            p->dir->esq = p->mid->dir;

        }

        else    //If the deficiency was created at mid node then the processing is the same irrespective of the fact
                //whether the parent was a 2 node or a 3 node
        {
            r->key1 = p->key1;              //Separator Key
            r->n = 1;                     //Because one key was moved into r

            p->key1 = p->esq->key2;

            p->esq->n = 1;

            //Updating Pointers

            p->mid->esq = p->esq->dir;
        }
    }


    //CASE 2 :  If the rotation is done to overcome the OVERFLOW at r
    else
    {
        if ( p->n == 2 && p->mid == r )      //If parent is a 3 node and p->mid is also a 3 node
        {
            p->dir->key2 = p->dir->key1;    //Right node ney ab 2 se 3 banna hai. Is lye key1 ko shift esq kar rahey kiun
                                                    //ke K1 pe ab parent se aik key ne ana hai.

            p->dir->key1 = p->key2;             //Separator Key

            if (d < r->key1)
            {
                p->key2 = r->key2;
                r->key2 = r->key1;
                r->key1 = d;
            }

            else if (d < r->key2)
            {
                p->key2 = r->key2;
                r->key2 = d;
            }

            else
            {
                p->key2 = d;
            }


            p->dir->dir  = p->dir ->mid;
            p->dir->mid = p->dir->esq;

            p->dir->esq   = filho;

            p->dir->n = 2;
        }

        else    //if r is the esq node then the processing is same irrespective of the fact whether the parent is a 2 or 3 node
        {
            p->mid->key2 = p->mid->key1;  //Middle node ney ab 2 se 3 banna hai. Is lye key1 ko shift esq kar rahey kiun
                                                    //ke K1 pe ab parent se aik key ne ana hai.
            p->mid->key1 = p->key1;

            if (d < r->key1)
            {
                p->key1 = r->key2;
                r->key2 = r->key1;
                r->key1 = d;
            }

            else if (d < r->key2)
            {
                p->key1 = r->key2;
                r->key2 = d;
            }

            else
            {
                p->key1 = d;
            }

            p->mid->dir = p->mid->mid;
            p->mid->mid = p->mid->esq;

            p->mid->esq   = filho;

            p->mid->n = 2;
        }
    }

    return (NULL);
}

AuxA23 A23::rotateLeft (NoA23* p, NoA23* r, std::string d, NoA23* filho) {
    /*CASE 1 :  If the rotation is done to overcome the UNDERFLOW at r*/
    if ( r->n == 0) {
        if ( (p->n == 2) && ( p->mid == r) ) //If the parent is a 3 node and if the deficiency is created at mid node
        {
            r->key1 = p->key2;                  //Separator Key
            r->n = 1;

            p->key2 = p->dir->key1;

            p->dir->key1 = p->dir->key2;
            p->dir->n = 1;

            //Updating Pointers
            p->mid->mid = p->dir->esq;

            p->dir->esq   = p->dir->mid;
            p->dir->mid = p->dir->dir;
        }

        else        //If the deficiency was created at esq node then the processing is the same irrespective of the fact
                    //whether the parent was a 2 node or a 3 node
        {
            r->key1 = p->key1;                  //Separator Key
            r->n = 1;

            p->key1 = p->mid->key1;

            p->mid->key1 = p->mid->key2;
            p->mid->n  = 1;

            //Updating Pointers
            p->esq->mid = p->mid->esq;

            p->mid->esq   = p->mid->mid;
            p->mid->mid = p->mid->dir;
        }

    }


    /*CASE 2 :  If the rotation is done to overcome the OVERFLOW at r*/
    else
    {
        if ( p->n == 2 && p->dir == r )       //If parent is a 3 node and p->dir is also a 3 node
        {
            p->mid->key2 = p->key2;                //Separator Key

            if (d < r->key1)
            {
                p->key2 = d;
            }

            else if (d < r->key2)
            {
                p->key2 = r->key1;
                r->key1 = d;
            }

            else
            {
                p->key2 = r->key1;
                r->key1 = r->key2;
                r->key2 = d;
            }

            p->mid->dir = p->dir->esq;

            p->dir->esq  = p->dir->mid;
            p->dir->mid = p->dir->dir;
            p->dir->dir = filho;

            p->mid->n = 2;
        }

        else    //if r is the mid node then the processing is same irrespective of the fact whether the parent is a 2 or 3 node
        {
            p->esq->key2 = p->key1;      //Separator Key

            if (d < r->key1)
            {
                p->key1 = d;
            }

            else if (d < r->key2)
            {
                p->key1 = r->key1;
                r->key1 = d;
            }

            else
            {
                p->key1 = r->key1;
                r->key1 = r->key2;
                r->key2 = d;
            }

            p->esq->dir = p->mid->esq;

            p->mid->esq  = p->mid->mid;
            p->mid->mid = p->mid->dir;
            p->mid->dir = filho;

            p->esq->n = 2;
        }
    }

    return (NULL);
}

// Wrapper function
bool A23::insert(std::string d) {
    std::string temp = searchFor(d);

    if (temp != d)
    {
        NoA23* p = raiz;                  //Parent Pointer (Will be used for rotation purposes)

        AuxA23 s1 = insert(raiz, d, p);

        if (s1.filho != NULL)               //The case when the result of the split reaches the raiz and raiz itself is to be splitted
        {
            NoA23 * temp = new NoA23;

            temp->key1 = s1.mid;
            temp->n  = 1;

            temp->esq = raiz;
            temp->mid  = s1.filho;

            temp->dir = NULL;
            raiz = temp;
        }

        return true;
    }

    else
        std::cout << "\nThe current item is already present.\n";

    return false;
}


// Recursive function
AuxA23 A23::insert (NoA23* & r, std::string d, NoA23* p) {
    //Case 1 (Empty Tree)
    if( r == nullptr)               //Tree is completely Empty (This case happens once in the lifetime of a tree!)
    {
        NoA23* temp = new NoA23;

        temp->key1 = d;
        temp->esq = temp->mid = temp->dir = NULL;

        temp->n = 1;
        r = temp;

        return (NULL);
    }


    //Case 2 (Leaf Nodes)
    else if (r->esq == nullptr)  //r is a leaf node
    {
        if ( r->n == 1)           //r is a 2 node and hence data can be accomodated
        {
            //Simple Data Accomodation
            if ( d < r->key1)
            {
                r->key2 = r->key1;
                r->key1 = d;
            }

            else
                r->key2 = d;

            r->n = 2;

            return (NULL);
        }


        else { //r is a 3 node so overflow as a result
            // If rotation is not possible then try split
            AuxA23 s1;
            int e = isRotationPossible(p,r);

            if (e == 1)
                s1 = rotateRight(p,r,d, NULL);
            else if (e == 2)
                s1 = rotateLeft(p,r,d, NULL);
            else
                s1 = split3node(r, d, NULL); //Splitting is to be done if the rotation didn't work

            return s1;
        }
    }


    //Case 3 (Non-Leaf Nodes)
    else {//r is a non-leaf node
        if (r->n == 1) { //r is a 2 node
            if (d < r->key1) {
                AuxA23 s1 = insert(r->esq, d, r);

                //Because parents par splitting ka result pass on hota hai
                if (s1.filho != nullptr) {
                    //Larger key ko dir pe shift kar do, isi lye ye do steps
                    r->key2 = r->key1;
                    r->key1 = s1.mid;

                    r->dir = r->mid;
                    r->mid = s1.filho;

                    r->n = 2;
                }
            }

            else if (d > r->key1) {
                AuxA23 s1 = insert (r->mid, d, r);

                //Because parents par splitting ka result pass on hota hai
                if (s1.filho != NULL) {
                    //key ko shift karne ki zaroorat nai pari, isi lye oper wale case mai kye gaye do steps yahan nahi kye

                    r->key2 = s1.mid;
                    r->dir = s1.filho;

                    r->n = 2;
                }
            }

            return (NULL);
        }


        else                            //r is a 3 node
        {
            AuxA23 s1;

            if ( d < r->key1)
                    s1 = insert (r->esq, d, r);

            else if (d < r->key2)
                    s1 = insert (r->mid, d, r);

            else
                    s1 = insert (r->dir, d, r);


            //In case oper waley teen cases mai se kisi case mai splitting huwi ho. Ab us splitting waley data ko
            //yahan accomodate karna
            if (s1.filho != NULL)
            {

                // If rotation is not possible then try split

                int e = isRotationPossible(p ,r);

                if (e == 1)
                    s1 = rotateRight(p ,r ,s1.mid, s1.filho);

                else if (e == 2)
                    s1 = rotateLeft(p ,r ,s1.mid, s1.filho);

                else
                    s1 = split3node(r, s1.mid, s1.filho);      //Splitting is to be done if the rotation didn'std::string work

                return s1;
            }

            return (NULL);
        }
    }

}

AuxA23 A23::split3node (NoA23* current, std::string k, NoA23* filho) {
    //filho means that filho which was made orphan in the previous split operation

    std::string mid;

    NoA23* temp = new NoA23;
    temp->n = 1;
    temp->esq = temp->mid = temp->dir = NULL;

    if (k < current->key1)
    {
        mid = current->key1;

        temp->key1    = current->key2;
        current->key1 = k;

        if (current->esq != NULL)
        {
            temp->esq = current->mid;
            temp->mid = current->dir;
            current->mid = filho;
        }
    }


    else if (k < current->key2)
    {
        mid = k;

        temp->key1    = current->key2;

        if (current->esq != NULL)
        {
            temp->esq = filho;
            temp->mid = current->dir;
        }
    }

    else
    {
        mid = current->key2;

        temp->key1 = k;

        if(current->esq != NULL)
        {
            temp->esq = current->dir;
            temp->mid = filho;
        }
    }

    current->dir = NULL;
    current->n = 1;

    AuxA23 s1(temp, mid);
    return s1;
}

AuxA23 A23::merge(NoA23* p, NoA23* &r, NoA23* filho) {

    if( (p->n == 2) && (p->dir == r) ) //If parent is a 3 node and deficiency is created on dir of parent
    {
        p->mid->key2 = p->key2;

        p->mid->n  = 2;

        p->mid->dir = filho;

        filho = NULL;
    }

    else            //If deficiency is created on esq or mid filho, then the processing is (mostly) the same (just a few checks only)
                    //irrespective of the fact that whether parent is a 2 node or a 3 node

    {
        if (p->esq == r)    //Deficiency is created on esq filho
        {
            p->mid->key2 = p->mid->key1;      //Shifting K1 to K2's position
            p->mid->key1 = p->key1;

            p->mid->n = 2;

            //Updating children of the node where merge is done because now it has become a 3 node
            p->mid->dir = p->mid->mid;
            p->mid->mid = p->mid->esq;
            p->mid->esq  = filho;

            filho = p->mid;

            p->esq   = p->mid;
            p->mid = p->dir;
        }

        else                    //Deficiency is created on mid filho
        {
            p->esq->key2 = p->key1;

            p->esq->n = 2;

            p->esq->dir = filho;

            filho = p->esq;

            p->mid = p->dir;
        }

        if (p->n == 2)
        {
            p->key1 = p->key2;      //Shift key2 to key1
            filho  = NULL;
        }
    }


    p->dir = NULL;

    p->n--;       //Because one key was moved from parent to its filho. So one key is decreased.


    //Deleting the node where the deficieny was created
    r->esq = r->mid = r->dir = NULL;
    delete r;
    r = NULL;


    return (filho);
}


//Wrapper Function
std::string A23::searchFor(std::string item) {
    return search(raiz, item);
}

//Recursive Function
std::string A23::search (NoA23* r, std::string d) {
    if (r != NULL)
    {
        if (r->n == 1)            //Two Node
        {
            if (d == r->key1)
                return r->key1;

            else if (d < r->key1)
            {
                return search (r->esq , d);
            }

            else
            {
                return search (r->mid, d);
            }
        }

        else                        //Three Node
        {
            if (d == r->key1)
                return r->key1;

            else if (d == r->key2)
                return r->key2;

            else if (d < r->key1)
            {
                return search (r->esq , d);
            }

            else if (d < r-> key2)
            {
                return search (r->mid, d);
            }

            else
                return search (r->dir, d);
        }
    }

    else
        return "throwException"; //An exception has to be thrown here
}

// Helper function to print spaces for indentation
void printIndentation(int level) {
    for (int i = 0; i < level; ++i) {
        std::cout << "  "; // Two spaces for each level
    }
}

// Recursive function to print a single node
void printRecursive(NoA23* node, int level) {
    printIndentation(level);

    if (node->n == 1) {
        std::cout << node->key1 << std::endl;
    } else if (node->n == 2) {
        std::cout << node->key1 << " " << node->key2 << std::endl;
    }
}

// Recursive function to print the 2-3 tree
void printTreeRecursive(NoA23* root, int level = 0) {
    if (root != nullptr) {
        printRecursive(root, level);

        if (root->n == 1) {
            printTreeRecursive(root->esq, level + 1);
            printTreeRecursive(root->mid, level + 1);
        } else if (root->n == 2) {
            printTreeRecursive(root->esq, level + 1);
            printTreeRecursive(root->mid, level + 1);
            printTreeRecursive(root->dir, level + 1);
        }
    }
}

// Wrapper function to print the 2-3 tree
void A23::printTree() {
    std::cout << "The tree is as follows:" << std::endl;
    if (raiz != nullptr) {
        printTreeRecursive(raiz);
    } else {
        std::cout << "The tree is empty." << std::endl;
    }
}


// // Wrapper Function
// void A23::printTree() {
//     std::cout << "\nThe tree is as follows :";
//     if (raiz != NULL) {
//         print(raiz);
//     } else {
//         std::cout << "\nThe tree is empty.";
//     }
// }

// // Recursive Function
// void A23::print(NoA23* r) {
//     if (r != NULL) {
//         if (r->n == 1) { // Two Node
//             print(r->esq);
//             std::cout << " " << r->key1;
//             print(r->mid);
//         } else { // Three Node
//             print(r->esq);
//             std::cout << " " << r->key1;
//             print(r->mid);
//             std::cout << " " << r->key2;
//             print(r->dir);
//         }
//     }
// }



void A23::displayFunctions() {
    std::cout << "\n\n\nThis class 2 3 Tree has the following functionality : ";
    std::cout << "\n1)Insert \n2)Delete \n3)Search \n4)Print\n\n";
    std::cout << "\nEnter the option number. To exit, enter -1.\nOption Number : ";
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


std::string getStringInput() {
    std::string userInput;
    std::getline(std::cin, userInput);
    return userInput;
}

int getUserInput() {
    int userInput;
    while (!(std::cin >> userInput)) {
    // while (!checkUserInput(userInput)) {
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        clearInputBuffer();
    }
    clearInputBuffer();
    return userInput;
}

void driver() {
    A23 tree1;
    int userInput = 0;
    std::string data;

    while (userInput != -1) {
        tree1.displayFunctions();
        userInput = getUserInput();

        if (userInput == 1) {
            std::cout << "Enter the data to be inserted into the tree: ";
            data = getStringInput();
            tree1.insert(data);
            std::cout << "After insertion:" << std::endl;
            tree1.printTree();
        } else if (userInput == 2) {
            std::cout << "Enter the data to be deleted from the tree: ";
            data = getStringInput();
            tree1.deleteNode(data);
            std::cout << "After deletion:" << std::endl;
            tree1.printTree();
        } else if (userInput == 3) {
            std::cout << "Enter the data element to search for: ";
            data = getStringInput();
            std::string result = tree1.searchFor(data);
            std::cout << result << std::endl;
        } else if (userInput == 4) {
            tree1.printTree();
        } else if (userInput != -1) {
            std::cout << "Invalid input. Please enter a valid option." << std::endl;
        }
    }
}