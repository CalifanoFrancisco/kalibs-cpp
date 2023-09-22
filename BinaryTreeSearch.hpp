#ifndef OPTIMIZED_BTS_HPP
#define OPTIMIZED_BTS_HPP

/* 
 * IN DEVELOPMENT...
*/

#include <iostream>

using std::cout;
using std::endl;

class BTS 
{
    struct Node 
    {
        int data;
        size_t repeated;
        Node* left;
        Node* right;

        Node(const int data) : 
            data(data),
            repeated(1),
            left(nullptr),
            right(nullptr)        
        {}

        Node() : 
            data(0),
            repeated(0),
            left(nullptr),
            right(nullptr)
        {}

        ~Node() 
        {
            cout << "~" << this->data << endl;
            delete this->left;
            delete this->right;
        }

        friend std::ostream& operator<<(std::ostream& os, const Node& node)
        {
            os << "Node(" <<
            "t:" << node.repeated << 
            ", val:" << node.data << 
            ", l:" << node.left <<
            ", r:" << node.right <<
            ")" <<
            " &" << &node
            ;
            return os;
        }
    };

    Node* m_root;
    size_t m_array_size;  // array size
    size_t m_size;
    Node* m_nodes;

    void resize_array()
    {
        // temporal array with new size
        Node* temp = new Node[m_array_size * 2];

        // copy old array to new one
        for (size_t i = 0; i < m_array_size; i++)
            temp[i] = m_nodes[i];

        // delete old array
        delete[] m_nodes;

        // update to new array with bigger size
        m_nodes = temp;

        // update size
        m_array_size *= 2;

        cout << "Array resized from " << m_array_size/2 << " to " << m_array_size << endl;
    }

    void addValue(Node* node, int value)
    {   
        // if value is already in tree, increase repeated counter
        if (node->data == value) 
        {
            node->repeated++;
            return;
        }

        if (node->data > value)
        {
            if (!node->left)
            {
                m_nodes[m_size] = Node(value);
                node->left = &m_nodes[m_size];
                cout << m_nodes[m_size] << endl;
                m_size++;
                return;
            }
            addValue(node->left, value);
        }
        else if (node->data < value)
        {
            if (!node->right)
            {
                m_nodes[m_size] = Node(value);
                node->right = &m_nodes[m_size];
                cout << m_nodes[m_size] << endl;
                m_size++;
                return;
            }
            addValue(node->right, value);
        }
    }

    void p_print(Node* node) const 
    {
        if (!node) return;

        p_print(node->left);
        cout << *node << endl;
        p_print(node->right);
    }
public:

    BTS():
        m_root(nullptr),    // no root node created yet
        m_size(-1),         // -1 because no nodes created yet
        m_array_size(1),    // 2 memory spaces
        m_nodes(nullptr)    // no nodes created yet
    {}
    
    ~BTS()
    {
        delete[] m_nodes;
    }

    void addNode(int value)
    {
        if (!m_root) 
        {
            // init array
            m_nodes = new Node[m_array_size];

            // set adress of root node (on index 0)
            m_root = &m_nodes[0];

            // set value of root node
            m_root = new Node(value);

            cout << "Root node created -> " << *m_root << endl;
            m_size = 0;
            return;
        }
    
        // if array is full, resize it
        if (m_size == m_array_size) resize_array();

        addValue(m_root, value);
        cout << endl;
    }

    void print()
    {
        p_print(m_root);
        cout << endl;
    }

    size_t size() const
    {
        return m_array_size;
    }
};  

#endif
