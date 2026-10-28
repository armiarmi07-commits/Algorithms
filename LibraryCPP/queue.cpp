#include "queue.h"
#include "list.h"
struct Queue
{
    List *list;
};

Queue *queue_create()
{
    Queue *queue = new Queue();
    queue->list = list_create();
    return queue;
}

void queue_delete(Queue *queue)
{
    // TODO: free queue items
    if (!queue) {
        return;
    }
    list_delete(queue->list);
    delete queue;
}

void queue_insert(Queue *queue, Data data)
{
    if (!queue) {
        return;
    }
    ListItem *last = list_last(queue->list);

    if (last == nullptr) {
        list_insert(queue->list, data);
    } else {
        list_insert_after(queue->list, last, data);
    }
}

Data queue_get(const Queue *queue)
{
    if (!queue) {
        return (Data)0;
    }
    ListItem *first = list_first(queue->list);
    if (!first) {
        return (Data)0;
    }
    return list_item_data(first);
}

void queue_remove(Queue *queue)
{
    if (!queue) {
        return;
    }
    list_erase_first(queue->list);
}

bool queue_empty(const Queue *queue)
{
    if (!queue) {
        return true;
    }
    if (list_first(queue->list) == nullptr) {
        return true;
    }
    return false;
}