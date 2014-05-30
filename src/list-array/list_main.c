/* 纯粹使用链表实现，验证各种算法的效率 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "list.h"

#define DEBUG
#define LIST_LENGTH (1024 * 1024)

LIST_HEAD(mylist);

static struct node {
    struct list_head list;
    char data[1024];
};

static void add_node(const char *str)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    memset(new_node, 0, sizeof(struct node));
    memcpy(new_node->data, str, strlen(str));
    DEBUG("%s strlen %d\n", str, strlen(str));
    list_add(&(new_node->list), &mylist);
}

/* 查找第n个元素 */
struct node *find_node_by_num(int n)
{
    int i;
    struct list_head *pos;
    struct node *cur_node;

    i = 1;
    list_for_each(pos, &mylist) {
        i++;
        if (i == n) {
            cur_node = list_entry(pos, struct node, list);
            return cur_node;
        }
    }

    return NULL;
}

static void show_all_node()
{
    struct list_head *pos;
    struct node *cur_node;
    
    list_for_each(pos, &mylist) {
        cur_node = list_entry(pos, struct node, list);
        printf("%s \n", cur_node->data);
    }
}

void list_main(void)
{
    int i;
    char word[1024];
    struct node *cur_node;
      
    for(i = 0; i < LIST_LENGTH; i++) {
        sprintf(word, "word%d", i);
        add_node(word);
    }

    cur_node = find_node_by_num(3);
    printf("%s\n", cur_node->data);

    //show_all_node();
}

