#include <string>
#include <iostream>

struct NoA23 {
    std::string key1, key2; 
    NoA23* esq; NoA23* mid; NoA23* dir;
    int n;
};

/*---Data Useful During Insertion and Deletion---*/
struct AuxA23 {
    std::string mid; // Will be useful only in case of split operation and will be useless in case of merge operation
    NoA23* filho;

    AuxA23() { filho = NULL; }

    // Overloaded Constructor 1
    AuxA23(NoA23* c) { filho = c; }

    // Overloaded Constructor 2
    AuxA23(NoA23* c, std::string m) {
        filho = c;
        mid = m;
    }

    // Overloaded Assignment Operator
    AuxA23& operator=(const AuxA23& otherusefulData) {
        if (&otherusefulData != this) {
            filho = otherusefulData.filho;
            mid = otherusefulData.mid;
        }
        return *this;
    }

    // Copy Constructor
    AuxA23(const AuxA23& otherusefulData) {
        filho = otherusefulData.filho;
        mid = otherusefulData.mid;
    }
};

/*-------------------------2 3 Tree-------------------------*/
class A23 {
private:
    NoA23 * raiz;

public:
    // Default Constructor
    A23() {
        raiz = NULL;
    }

    // Destructor
    ~A23()
    {
        if (raiz != NULL)                   //If tree is empty then do nothing.
        {
            destroy(raiz);
        }
    }
    // Destroys Nodes
    void destroy (NoA23 * r)
    {
        if (r != NULL)
        {
            destroy (r->esq);
            destroy (r->mid);
            destroy (r->dir);
            delete r;
        }
    }

    /*------------------- Rotation Functions -------------------*/
    int isRotationPossible(NoA23* p, NoA23* r); // Tells if rotation is possible or not and if possible then which rotation (anti-clockwise or clockwise)

    AuxA23 rotateRight (NoA23* p, NoA23* r, std::string d, NoA23* filho);
    AuxA23 rotateLeft (NoA23* p, NoA23* r, std::string d, NoA23* filho);

    /*--------------------------Insertion Function---------------------*/
    //Main Insert Function
    //Wrapper Function
    bool insert(std::string d);

    //Recursive Function
    AuxA23 insert (NoA23* & r, std::string d, NoA23* p);
    AuxA23 split3node (NoA23* current, std::string k, NoA23* filho);


    /*------------------- Deletion Function -------------------*/


    /*------------------- Merge Function -------------------*/
    AuxA23 merge(NoA23* p, NoA23* &r, NoA23* filho);


    //Main Wrapper Function
    void deleteNode (std::string d)
    {
        NoA23 * p = raiz;     //Parent pointer will be used for rotation and merging purposes

        Delete(raiz,d,p);
    }


    //Recursive Function
    AuxA23 Delete(NoA23* r , std::string d, NoA23* p) {
        if (r != NULL)                      //When Tree is empty, do nothing
        {

            /*---Cases---*/

            //CASE 1 when key from intermediate node is to be deleted

            if (r->esq != NULL)          //Non-Leaf Node , Swap with predecessor
            {

                AuxA23 s1(NULL);

                if (r->n == 1)    //2 node
                {
                    if (d != r->key1)
                    {
                        if (d < r->key1)
                        {
                            s1 = Delete (r->esq, d, r);
                        }

                        else
                            s1 = Delete (r->mid, d, r);

                        if(s1.filho == NULL)
                            return s1;
                    }
                }


                else                //3 node
                {
                    if ( (d != r->key1) && ( d != r->key2) )
                    {
                        if (d < r->key1)
                        {
                            s1 = Delete (r->esq, d, r);
                        }

                        else if (d < r->key2)
                        {
                            s1 = Delete (r->mid, d, r);
                        }

                        else
                            s1 = Delete (r->dir, d, r);

                        if(s1.filho == NULL)
                            return s1;
                    }
                }


                if(raiz->n == 0)  //When the raiz itself is merged. So new raiz is formed
                {
                    raiz->esq = raiz->mid = raiz->dir = NULL;
                    delete raiz;
                    raiz = s1.filho;

                    r    = raiz;

                    return (NULL);
                }


                if (s1.filho != NULL)       //Means the previous merge operation has created a new deficiency
                {
                    int e = isRotationPossible(p,r);

                    if (e == 1)
                        s1 =  rotateRight(p,r,s1.mid,s1.filho);        //mid is just a dummy here. Used to complete the argument list

                    else if (e == 2)
                        s1 =  rotateLeft(p,r,s1.mid,s1.filho);

                    else
                        s1 = merge(p,r,s1.filho);                 //Merging is to be done if the rotation didn't work

                    return s1;
                }


                //Swap with predecessor and delete the non leaf node

                NoA23* current;
                std::string temp;

                if ( (r->n == 2) && (r->key2 == d) )    //If r is a 3 node and key to be deleted is key2
                {
                    temp    = r->key2;
                    current = r->mid;

                    p = r;

                    while (current->esq != NULL)     //Because predecessor is always in a leaf node
                    {
                        p = current;

                        if (current->n == 1)
                        {
                            current = current->mid;    //If current is a 2 node then move towards its mid
                        }

                        else
                        {
                            current = current->dir;     //If current is a 3 node then move towards its dir
                        }
                    }


                    if (current->n == 1)              //If predecessor is in a 2 node
                    {
                        r->key2       = current->key1;
                        current->key1 = temp;
                    }

                    else                                //If predecesoor is in a 3 node
                    {
                        r->key2       = current->key2;
                        current->key2 = temp;
                    }
                }


                else                        //If the key to be deleted is key1 then the processing is the same irrespective
                                            //of the fact whether r is a 2 node or a 3 node
                {
                    temp    = r->key1;
                    current = r->esq;

                    p = r;

                    while (current->esq != NULL)     //Because predecessor is always in a leaf node
                    {
                        p = current;

                        if (current->n == 1)          //If current is a 2 node then move towards its mid
                        {
                           current = current->mid;
                        }

                        else                            //If current is a 3 node then move towards its dir
                        {
                            current = current->dir;
                        }
                    }


                    if (current->n == 1)  //Predecessor is in a 2 node
                    {
                        r->key1       = current->key1;
                        current->key1 = temp;
                    }

                    else if (current->n == 2) //Predecessor is in a 3 node
                    {
                        r->key1       = current->key2;
                        current->key2 = temp;
                    }
                }

                    current->n--;             //Deleting that key value
                    r = current;
            }


                //CASE 2 When key from leaf node is to be deleted

                else if ((r->esq == NULL) && ( (r->key1 == d) || (r->key2 == d) ))     //r is a Leaf node, Simply delete
                {
                    if (r->n == 2)           //r is a 3 node
                    {
                        if (r->key1 == d)       //key1 is to be deleted
                        {
                            r->key1 = r->key2;  //Shift K2 to K1's place
                        }
                    }

                    r->n --;          //Deleting that key value
                }


                //After deletion, checking for underflow

                //Check for underflow
                //If rotation possible then do rotation
                //else do merge

                if ( (r->n == 0) && (p == r) )         //Means if raiz was deleted
                {
                    delete r;
                    raiz = NULL;
                }

                else if (r->n == 0)
                {

                    AuxA23 s1;

                    int e = isRotationPossible(p,r);


                    if (e == 1)
                        s1 =  rotateRight(p,r,s1.mid,NULL);            //mid is just a dummy here. Used to complete the parameter list

                    else if (e == 2)
                        s1 =  rotateLeft(p,r,s1.mid,NULL);

                    else
                        s1 = merge(p,r,NULL);                 //Merging is to be done if the rotation didn't work

                    return s1;
                }

            }

            else
                std::cout << "\nThe tree is already empty.";

            return (NULL);
        }






    /*------------------- Lookup Function -------------------*/

    //Wrapper Function
    std::string searchFor(std::string item);
    //Recursive Function
    std::string search (NoA23* r, std::string d);

    /*------------------- Utility Functions -------------------*/
    // Wrapper Function
    void printTree();
    
    // Recursive Function
    void print(NoA23* r);

    void displayFunctions();

//--------------Ended 2 3 Tree Class---------------------//

};

void driver() {
    A23 tree1;
    int userInput = 0;
    std::string data;

    while (userInput != -1) {
        tree1.displayFunctions();
        std::cin >> userInput;

        if (userInput == 1) {
            std::cout << "\nEnter the data to be inserted into the Tree : ";
            std::cin  >> data;

            tree1.insert(data);

            std::cout << "\nAfter insertion :";
            tree1.printTree();
        }

        else if (userInput == 2) {
            std::cout << "\nEnter the data to be deleted from the Tree : ";
            std::cin  >> data;

            tree1.deleteNode(data);

            std::cout << "\nAfter deletion :";
            tree1.printTree();
        }

        else if (userInput == 3) {
            std::cout << "\nEnter the data element which is to be searched : ";
            std::cin  >> data;

            if(tree1.searchFor(data) != "throwException")
                std::cout << "\nThe element is found. ";
            else
                std::cout << "\nThe element is not found. ";
        }

        else if (userInput == 4) {
            tree1.printTree();
        }
    }


    /*
    std::cout << "\nTesting the copy constructor :";
   //A23<int> tree2 = tree1;

    std::cout << "\nTree 2 is a copy of Tree 1 constructed through Copy Constructor.";

    std::cout << "\nTree 1 : ";
    //tree1.printTree();

    std::cout << "\nTree 2 : ";
    //tree2.printTree();
    */
}
