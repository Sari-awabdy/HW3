//
//  Queue.h
//  QUEUE
//
//  Created by Sari Awabdy on 09/03/2024.
//
#ifndef Queue_h
#define Queue_h
//
template <class T>
class Queue{
private:
    class Node;
    Node* front;
    Node* rear;
    int size;

public:
    //constructors
    Queue();
    Queue(const Queue queue)();

    //deconstrustors
    ~Queue();

    //getter and setter
    Node* getFront(){return front}
    void setFront(const Node* front){this.front = front}
    
    Node* getRear(){return rear}
    void setRear(const Node* rear){this.rear = rear}

    //Iterator
    class Iterator;
    Iterator begin();
    Iterator end();

    /**
     * pushBack: adds element to the end of the Queue
     * 
     * @param element - the element to add 
     * @return 
     *          a refrence to the queue
    */
    Queue& pushBack(const T& element);

    /**
     * front: returns the data of the front element
     * 
     * @return
     *       the data of the element in the front of the queue
    */
    const T& front();

    /**
     * popFront: deletes the first 
     *  
     * add exceptions
     * @return
     *        deletes the front element
    */
    void popFront();

    /**
     * size: returns the size of the queue
     * 
     * @return
     *       the size of the queue
    */
    int size();
}
//exceptions
class EmptyQueue(){}
class InvalidOperation(){}

/**
 * filter: creates a new queue in which the elements are those element from queue who work on a condition 
 * 
 * @param queue - the queue which we need to get elements from
 * @param condition - the function object that checks the needed condition
 * 
 * @return
 *      new queue in which the elements that are tru to the condition 
*/
template <class T,class Condition>
Queue<T> filter(const Queue<T>& queue,Condition condition);{
    Queue<T> resultQueue = new Queue<T>();
    for(const Iterator it = queue.begin(); it != queue.end(); it++){
        resultQueue.pushBack(it.node.getData());
    }
    return resultQueue;
}

/**
 * transform: transforms each element of a queue into the convert(element)
 * 
 * @param queue - the queue we want to convert
 * @param convert - the convertion function object  
*/
template <class T,class Convert>
void transform(Queue<T>& queue, Convert convert){
    if(queue.getfront() == nullptr){
        return
    }
    for(const Iterator it = queue.begin(); it != queue.end(); it++){
        it.node.setData(convert(it.node.getData()));
    }
}

/**
 * reduce: repeats function on each element with the result of the previous result(result of 1 -> result of 2 -> result of 3)
 * 
 * @param queue - the queue we want to go through
 * @param base - the base value we start with
 * @param condition - the function we calculate by
 * 
 * @return
 *      the final value calculated
*/
template<class T,class Condition>
T reduce(Queue<T> queue, T base, Condition condition){
    T finalResult = base;
    for(const Iterator it = queue.begin(); it != queue.end(); it++){
        finalResult = condition(base, it.node.getData()); 
    }
    return finalResult;
}

//class Node
template <class T>
class Queue :: Node{
private:
    T data;
    Node* next;

    friend class Iterator;
    friend class Queue:
public:
    // Constructors
    Node() : next(nullptr) {}
    Node(T value) : data(value), next(nullptr) {}
    Node(const Node node): data(node.data), next(node.next) {}

    // Destructor
    ~Node() = default;

    // Getters and setters
    T getData() const { return data; }
    void setData(T value) { data = value; }

    Node* getNext() const { return next; }
    void setNext(Node* nextNode) { next = nextNode; }

    Node* getPrevious() const { return previous; }
    void setPrevious(Node* prevNode) { next = prevNode; }
}

//constructors
Queue :: Queue() : size(0){
    this.front = nullptr;
    this.rear = front;
}

Queue :: Queue(const Queue queue) : front(nullptr), rear(nullptr), size(0){
    for(const Iterator it = (queue.begin()++); it != queue.end(); it++){
        this.pushBack(it.node.getData());
    }
}
//deconstructor
Queue :: ~Queue(){
    //check this
    for(const Iterator it = this.begin(); it != this.end(); ++it){
        delete it.node;
    }
}

//class Iterator
template <class T>
class Queue :: Iterator{
private:
    const Node* node;
    Iterator() : node(nullptr);
    Iterator(const Node* node) : node(node){};
    friend class Queue;
public:
    const int& operator*() const;
    Iterator& operator++();
    Iterator& operator++(int);
    bool operator==(const Iterator& it) const;
    bool operator!=(const Iterator& it) const;
    Iterator& operator=(const Iterator&) = default;
} 
const T& Queue :: Iterator :: operator*(){
    return this.node.getData();
} 
Iterator& Queue :: Iterator :: operator++(){
    if(this.node == nullptr || node.getNext() == nullptr){
        throw InvalidOperation();
    }
    this.node = node.getNext();
    return this;
}
Iterator& Queue :: Iterator :: operator++(int){
    Node& prevNode = this.node;
    this++;
    return prevNode;
}
bool Queue :: Iterator :: operator==(const Iterator& it) const{
    return this.node == it.node;
}
bool Queue :: Iterator :: operator!=(const Iterator& it) = const{
    return this.node != it.node;
}

Iterator Queue :: Iterator :: begin(){
    return Iterator(this.front);
}
Iterator Queue :: Iterator :: end(){
    return Iterator();
}


//pushBack
Queue& Queue :: pushBack(const T& element){
    try{
        Node* addedElement = new Node(element);
        if(this.front == nullptr){
            this.front = addedElement;
            this.rear = this.front;
        }else{
            this.rear.setNext(addedElement);
            this.rear = rear.getNext();
        }
    } catch (const std :: bad_alloc& e){
        throw;
    }
    this.size++;
    return this;
}

//front 
const T& Queue :: front(){
    //if queue is empty throw exeption
    if(this.front == nullptr){
        throw EmptyQueue();
    }
    return this.front.getData();
}

//popFront
void Queue :: popFront(){
    //if queue is empty throw exeption
    if(this.size == 0){
        throw EmptyQueue();
    }
    Node* tmpNewFront = this.front.getNext();
    delete front;
    this.front = tmpNewFront;
    if (tmpNewFront == nullptr)
    {
        this.rear = nullptr;
    }
}

//size
int Queue :: size(){
    return size;
}
#endif /* Queue_h */
