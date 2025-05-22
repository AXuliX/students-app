#include <iostream>
#include <conio.h>
#include <vector>
using namespace std;

const int TABLE_SIZE = 10;

struct User
{
    string userID;
    string password;
};

// Node structure for the tree
struct Node {
    string name;
    vector<Node*> children;
    
    Node(string n) : name(n) {}
    
    // Add a child node
    void addChild(Node* child) {
        children.push_back(child);
    }
};

int hashFunction(string userID)
{
    int sum = 0;
    for (char ch : userID)
    {
        sum += int(ch);
    }
    return sum % TABLE_SIZE;
}

class HashTable
{
public:
    User students[TABLE_SIZE];
    User teachers[TABLE_SIZE];

    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            students[i].userID = "";
            teachers[i].userID = "";
        }
    }

    /////////////////////////////// sign up /////////////////////////////
    void signUp(string role)
    {
        string userID, password;
        cout << "Enter user ID: ";
        cin >> userID;
        cout << "Enter password: ";
        cin >> password;

        int index = hashFunction(userID);

        if (role == "student")
        {
            if (students[index].userID == "")
            {
                students[index].userID = userID;
                students[index].password = password;
                cout << "Student signed up successfully!\n";
            }
            else
            {
                cout << "User ID already exists. Try again.\n";
            }
        }
        else if (role == "teacher")
        {
            if (teachers[index].userID == "")
            {
                teachers[index].userID = userID;
                teachers[index].password = password;
                cout << "Teacher signed up successfully!\n";
            }
            else
            {
                cout << "User ID already exists. Try again.\n";
            }
        }
    }
    
    void traverse(Node* currentNode) {
    if (currentNode == nullptr) return;

    while (true) {
        system("cls");
        cout << "You are currently in: " << currentNode->name << "\n";
        cout << "Subtopics available:\n";

        for (size_t i = 0; i < currentNode->children.size(); ++i) {
            cout << i + 1 << ") " << currentNode->children[i]->name << "\n";
        }

        int choice;
        cout << "Enter your choice (or 0 to go back): ";
        cin >> choice;

        // Go back
        if (choice == 0) {
            system("cls");
            return;
            }

        // Check 
        if (choice > 0 && choice <= currentNode->children.size()) {
            //selected child
            traverse(currentNode->children[choice - 1]);
        } else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
}

    /////////////////////////////login////////////////////////
    void login(string role,Node*root)
    {
        string userID, password;
        cout << "Enter user ID: ";
        cin >> userID;
        cout << "Enter password: ";
        cin >> password;

        int index = hashFunction(userID);

        if (role == "student")
        {
            if (students[index].userID == userID && students[index].password == password)
            {
                cout << "Student login successful!\n";
                traverse(root);
            }
            else
            {
                cout << "Invalid user ID or password.\n";
            }
        }
        else if (role == "teacher")
        {
            if (teachers[index].userID == userID && teachers[index].password == password)
            {
                cout << "Teacher login successful!\n";
                traverse(root);
            }
            else
            {
                cout << "Invalid user ID or password.\n";
            }
        }
    }
};

void studentSide(string r, HashTable *h,Node* root)
{
    string choice;
    cout << "Would you like to (1) login or (2) sign up (3) exit? ";
    cin >> choice;

    if (choice == "1")
    {
        h->login(r,root);
    }
    else if (choice == "2")
    {
        h->signUp(r);
    }
    else if (choice == "3")
    {
        return;
    }
    else
    {
        cout << "Invalid choice. Exiting...\n";
    }
}

void teacherSide(string r, HashTable *h,Node* root)
{
    string choice;

    cout << "Would you like to (1) login or (2) sign up (3) exit? ";
    cin >> choice;

    if (choice == "1")
    {
        h->login(r,root);
    }
    else if (choice == "2")
    {
        h->signUp(r);
    }
    else if (choice == "3")
    {
        return;
    }
    else
    {
        cout << "Invalid choice. Exiting...\n";
    }
}

int main()
{
    HashTable ht;
    string role, choice;
    int flag;

    Node* root = new Node("Courses");

    Node* science = new Node("Science");
    Node* maths = new Node("Maths");
    Node* compSci = new Node("Computer Science");

    Node* Physics = new Node("Physics");
    Node* Chemistry = new Node("Chemistry");
    Node* Biology = new Node("Biology");

    Node* Algebra = new Node("Algebra");
    Node* Calculus = new Node("Calculus");
    Node* Geometry = new Node("Geometry");

    Node* Data_Structures = new Node("Data Structures");
    Node* Algorithms = new Node("Algorithms");
    Node* Operating_Systems = new Node("Operating Systems");

    Node* Physics_module_1 = new Node("Module 1");
    Node* Physics_module_2 = new Node("Module 2");
    Node* Physics_module_3 = new Node("Module 3");

    Node* Chemistry_module_1 = new Node("Module 1");
    Node* Chemistry_module_2 = new Node("Module 2");
    Node* Chemistry_module_3 = new Node("Module 3");

    Node* Biology_module_1 = new Node("Module 1");
    Node* Biology_module_2 = new Node("Module 2");
    Node* Biology_module_3 = new Node("Module 3");

    Node* Algebra_module_1 = new Node("Module 1");
    Node* Algebra_module_2 = new Node("Module 2");

    Node* Calculus_module_1 = new Node("Module 1");
    Node* Calculus_module_2 = new Node("Module 2");
    Node* Calculus_module_3 = new Node("Module 3");

    Node* Geometry_module_1 = new Node("Module 1");
    Node* Geometry_module_2 = new Node("Module 2");

    Node* Data_Structures_module_1 = new Node("Module 1");
    Node* Data_Structures_module_2 = new Node("Module 2");
    Node* Data_Structures_module_3 = new Node("Module 3");

    Node* Algorithms_module_1 = new Node("Module 1");
    Node* Algorithms_module_2 = new Node("Module 2");
    Node* Algorithms_module_3 = new Node("Module 3");

    Node* Operating_Systems_module_1 = new Node("Module 1");
    Node* Operating_Systems_module_2 = new Node("Module 2");

    root->addChild(science);

        science->addChild(Physics);
            Physics->addChild(Physics_module_1);
                Physics_module_1->addChild (new Node("Newton's laws of motion\nNewton's laws of motion describe the relationship between an object and the forces acting on it, forming the foundation of classical mechanics:\n First Law (Inertia): An object remains at rest or in uniform motion unless acted upon by an external force.\nSecond Law (Force and Acceleration): The force acting on an object is equal to its mass multiplied by its acceleration (F = ma).\nThird Law (Action and Reaction): For every action, there is an equal and opposite reaction.\nThese laws explain how objects move and interact under various forces."));
            Physics->addChild(Physics_module_2);
                Physics_module_2->addChild (new Node("Gravitation\nGravitation is a natural force of attraction between two objects with mass. It causes objects to be pulled toward each other, with the strength of the force depending on their masses and the distance between them. Discovered by Sir Isaac Newton, his law of universal gravitation states that every mass attracts every other mass with a force proportional to the product of their masses and inversely proportional to the square of the distance between them. On Earth, gravitation is what gives objects weight and causes them to fall toward the ground when dropped. It also governs the orbits of planets and stars."));
            Physics->addChild(Physics_module_3);
                Physics_module_3->addChild (new Node("Radioactivity\nRadioactivity is the spontaneous emission of energy from unstable atomic nuclei as they decay into more stable forms. This decay process releases particles such as alpha particles, beta particles, or gamma rays. There are three primary types of radioactive decay: alpha decay (emission of an alpha particle), beta decay (emission of a beta particle), and gamma decay (release of gamma radiation). Radioactive materials, like uranium or radium, naturally undergo these processes. Radioactivity is a key principle in nuclear physics and is used in various applications, including medical imaging, cancer treatment, energy production, and archaeological dating (radiocarbon dating)."));

        science->addChild(Chemistry);
            Chemistry->addChild(Chemistry_module_1);
                Chemistry_module_1->addChild (new Node("Acid-Base Reactions\nThese involve the transfer of protons (H⁺) between substances. Acids donate protons, while bases accept them, following the Brønsted-Lowry theory. The pH scale measures acidity and alkalinity, with lower values indicating more acidic solutions."));
            Chemistry->addChild(Chemistry_module_2);
                Chemistry_module_2->addChild (new Node("Stoichiometry\nThis branch of chemistry deals with the calculation of reactants and products in chemical reactions. It is based on the law of conservation of mass, using balanced chemical equations to determine mole ratios and quantities of substances involved."));
            Chemistry->addChild(Chemistry_module_3);
                Chemistry_module_3->addChild (new Node("Organic Chemistry\nThis field studies carbon-containing compounds and their reactions. Organic molecules can be simple (like methane) or complex (like proteins). Key topics include functional groups, isomerism, and reaction mechanisms, forming the basis for pharmaceuticals, plastics, and biochemistry."));

        science->addChild(Biology);
            Biology->addChild(Biology_module_1);
                Biology_module_1->addChild (new Node("Cell Biology\nCell biology studies the structure, function, and behavior of cells, the basic units of life. It explores organelles, cellular processes like metabolism and respiration, and cell division (mitosis and meiosis). Understanding cell biology is crucial for fields like genetics, microbiology, and biotechnology."));
            Biology->addChild(Biology_module_2);
                Biology_module_2->addChild (new Node("Genetics\nGenetics is the study of heredity and variation in organisms. It focuses on DNA, genes, and chromosomes, exploring how traits are inherited and expressed. Key concepts include Mendelian inheritance, genetic mutations, and modern techniques like CRISPR for gene editing."));
            Biology->addChild(Biology_module_3);
                Biology_module_3->addChild (new Node("Ecology\nEcology examines interactions among organisms and their environments. It studies ecosystems, biodiversity, and the relationships between species and their habitats. Ecological research informs conservation efforts and understanding climate change impacts."));
            
        
    root->addChild(maths);

        maths->addChild(Algebra);
            Algebra->addChild(Algebra_module_1);
                Algebra_module_1->addChild (new Node("Linear Equations\nLinear equations represent relationships between variables in the form y = 𝑚𝑥 + by = mx + b, where 𝑚m is the slope and b is the y-intercept. They can be solved using methods like substitution or elimination."));
            Algebra->addChild(Algebra_module_2);
                Algebra_module_2->addChild (new Node("Polynomial\nPolynomials are expressions that consist of variables raised to whole-number powers, combined using addition, subtraction, and multiplication. They can be classified by degree (e.g., linear, quadratic, cubic) and are fundamental in algebra for modeling various phenomena."));

        maths->addChild(Calculus);
            Calculus->addChild(Calculus_module_1);
                Calculus_module_1->addChild(new Node("Limits\nLimits describe the behavior of a function as it approaches a specific point. They are fundamental for defining continuity, derivatives, and integrals."));
            Calculus->addChild(Calculus_module_2);
                Calculus_module_2->addChild(new Node("Derivatives\nDerivatives measure the rate of change of a function concerning its variable. They are used to determine slopes of tangent lines, optimize functions, and analyze motion."));
            Calculus->addChild(Calculus_module_3);
                Calculus_module_3->addChild(new Node("Integrals\nIntegrals represent the accumulation of quantities, such as area under a curve. They can be definite (with specific limits) or indefinite (without limits) and are essential for calculating total quantities and solving differential equations."));

        maths->addChild(Geometry);
            Geometry->addChild(Geometry_module_1);
                Geometry_module_1->addChild(new Node("Euclidean Geometry\nThis is the study of flat, two-dimensional spaces based on the postulates of the ancient Greek mathematician Euclid. It includes concepts such as points, lines, angles, triangles, and circles, emphasizing properties and relations. The Pythagorean theorem, which relates the sides of a right triangle, is a cornerstone of this geometry."));
            Geometry->addChild(Geometry_module_2);
                Geometry_module_2->addChild(new Node("Non-Euclidean Geometry\nThis explores geometries that deviate from Euclidean principles, such as hyperbolic and spherical geometry. In hyperbolic geometry, parallel lines diverge, while in spherical geometry, the surface of a sphere alters the rules of angles and distances."));

    root->addChild(compSci);

        compSci->addChild(Data_Structures);
            Data_Structures->addChild(Data_Structures_module_1);
                Data_Structures_module_1->addChild(new Node("Arrays\nArrays are a collection of elements stored in contiguous memory locations, allowing for efficient access and manipulation of data. They support operations like searching, sorting, and traversal. Common algorithms include binary search and quicksort."));
            Data_Structures->addChild(Data_Structures_module_2);
                Data_Structures_module_2->addChild(new Node("Linked Lists\nLinked lists consist of nodes, each containing data and a reference to the next node. They offer dynamic memory allocation, allowing for efficient insertions and deletions. Variants include singly linked lists, doubly linked lists, and circular linked lists."));
            Data_Structures->addChild(Data_Structures_module_3);
                Data_Structures_module_3->addChild(new Node("Trees\nTrees are hierarchical data structures with nodes connected by edges. The root node has children, forming a parent-child relationship. Binary trees, binary search trees, and balanced trees (like AVL trees) optimize search, insert, and delete operations."));

        compSci->addChild(Algorithms);
            Algorithms->addChild(Algorithms_module_1);
                Algorithms_module_1->addChild(new Node("Sorting Algorithms\nThese algorithms arrange elements in a specific order, such as ascending or descending. Common types include Quick Sort, which uses a divide-and-conquer strategy to partition data; Merge Sort, which divides the array into halves, sorts them, and merges them; and Bubble Sort, which repeatedly compares adjacent elements and swaps them until the array is sorted."));
            Algorithms->addChild(Algorithms_module_2);
                Algorithms_module_2->addChild(new Node("Search Algorithms\nThese algorithms find specific elements within a data structure. Linear Search checks each element sequentially, while Binary Search divides the dataset in half, making it efficient for sorted arrays."));
            Algorithms->addChild(Algorithms_module_3);
                Algorithms_module_3->addChild(new Node("Graph Algorithms\nThese algorithms solve problems related to graph data structures. Dijkstra's Algorithm finds the shortest path from a source node to other nodes, while Depth-First Search (DFS) and Breadth-First Search (BFS) traverse graphs to explore all vertices or find specific paths."));

        compSci->addChild(Operating_Systems);
            Operating_Systems->addChild(Operating_Systems_module_1);
                Operating_Systems_module_1->addChild(new Node("Process Management\nThis involves handling processes in an operating system, including their creation, scheduling, and termination. The OS allocates resources to processes and ensures they execute efficiently while managing concurrency and synchronization to avoid conflicts."));
            Operating_Systems->addChild(Operating_Systems_module_2);
                Operating_Systems_module_2->addChild(new Node("File Systems\nFile systems organize and manage data storage, providing a way to store, retrieve, and manipulate files on storage devices. They define file naming conventions, access permissions, and hierarchical directory structures to facilitate user interaction with data."));

    while (true)
    {
        system("cls");
        cout << "Would you like to enter as: 1) student 2) teacher 3) exit? ";
        cin >> choice;

        if (choice == "1")
        {
            system("cls");
            role = "student";
            studentSide(role, &ht,root);
        
        }
        else if (choice == "2")
        {
            system("cls");
            role = "teacher";
            teacherSide(role, &ht,root);
        }
        else if (choice == "3")
        {
            cout << "Exiting..." << endl;
            break;
        }
        else
        {
            cout << "Invalid entry" << endl;
        }

        

        cout << "Would you like to continue? 1) yes 2) no: ";
        cin >> flag;
        if (flag == 2)
        {
            break;
        }
    }
}