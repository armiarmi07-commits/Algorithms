#include <cstddef>
#include "list.h"

struct ListItem
{
    Data data;
    ListItem *next;
    ListItem *prev;
    bool is_head = false;
};

struct List
{
    ListItem *head = nullptr;
    size_t size = 0;

};

List *list_create()
{
    List *list = new List;
    list->head = new ListItem;
    list->head->is_head = true;
    list->head->next = list->head;
    list->head->prev = list->head;
    return list;
}

void list_delete(List *list)
{
    // TODO: free items
    if (!list) return;
    ListItem *cur = list->head->next;
    while (cur != list->head) {
        ListItem *next = cur->next;
        delete cur;
        cur = next;
    }
    delete list->head;
    delete list;
}

ListItem *list_first(List *list)
{
    if (!list || list->head == list->head->next) {
        return NULL;
    }
    return list->head->next;

}

ListItem *list_last(List *list)
{
    if (!list || list->head->next == list->head) {
        return NULL;
    }
    return list->head->prev;
}

Data list_item_data(const ListItem *item)
{
    if (item == NULL) {
        return (Data)0;
    }
    return item->data;
}

ListItem *list_item_next(ListItem *item)
{
    if (!item || !item->next || item->next->is_head) {
        return NULL;
    }
    return item->next;
}

ListItem *list_item_prev(ListItem *item)
{
    if (!item || !item->prev || item->prev->is_head) {
        return NULL;
    }
    return item->prev;
}

ListItem *list_insert(List *list, Data data)
{
    if (!list) {
        return NULL;
    }
    ListItem *item = new ListItem;
    item->data = data;
    item->next = list->head->next;
    item->prev = list->head;
    list->head->next->prev = item;
    list->head->next = item;
    ++list->size;
    return item;

}

ListItem *list_insert_after(List *list, ListItem *item, Data data)
{
    if (!list) {
        return NULL;
    }
    if (!item) {
        return NULL;
    }
    ListItem *new_item = new ListItem;
    new_item->data = data;
    ListItem *tail = item->next;
    new_item->next = tail;
    new_item->prev = item;
    tail->prev = new_item;
    item->next = new_item;
    ++list->size;
    return new_item;
}

ListItem *list_erase_first(List *list)
{
    if (!list) {
        return NULL;
    }
    ListItem *first = list->head->next;
    if (first == list->head) {
        return NULL;
    }
    ListItem *two = list->head->next->next;
    list->head->next = two;
    two->prev = list->head;
    delete first;
    --list->size;
    return two;
}

ListItem *list_erase_next(List *list, ListItem *item)
{
    if (!list || !item) {
        return NULL;
    }
    ListItem *del = item->next;
    if (del == list->head) {
        return NULL;
    }
    ListItem *next = del->next;
    item->next = next;
    next->prev = item;
    delete del;
    --list->size;
    return next;
}
