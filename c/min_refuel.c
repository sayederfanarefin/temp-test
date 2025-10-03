#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size, cap;
} Heap;

static void heap_init(Heap *h, int cap) {
    h->data = (int*)malloc(sizeof(int)*cap);
    h->size = 0; h->cap = cap;
}
static void heap_free(Heap *h) {
    free(h->data);
    h->data = NULL; h->size = h->cap = 0;
}
static void heap_push(Heap *h, int val) {
    if (h->size == h->cap) {
        h->cap = h->cap ? h->cap*2 : 8;
        h->data = (int*)realloc(h->data, sizeof(int)*h->cap);
    }
    int i = h->size++;
    h->data[i] = val;
    while (i > 0) {
        int p = (i-1)/2;
        if (h->data[p] >= h->data[i]) break;
        int tmp = h->data[p]; h->data[p] = h->data[i]; h->data[i] = tmp;
        i = p;
    }
}
static int heap_pop(Heap *h) {
    if (h->size == 0) return 0;
    int top = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, mx = i;
        if (l < h->size && h->data[l] > h->data[mx]) mx = l;
        if (r < h->size && h->data[r] > h->data[mx]) mx = r;
        if (mx == i) break;
        int tmp = h->data[i]; h->data[i] = h->data[mx]; h->data[mx] = tmp;
        i = mx;
    }
    return top;
}

int min_refuel_stops(int target, int startFuel, int stations[][2], int n) {
    long long fuel = startFuel;
    Heap h; heap_init(&h, n > 0 ? n : 8);
    int i = 0, stops = 0;

    while (fuel < target) {
        while (i < n && stations[i][0] <= fuel) {
            heap_push(&h, stations[i][1]);
            i++;
        }
        if (h.size == 0) { heap_free(&h); return -1; }
        fuel += heap_pop(&h);
        stops++;
    }
    heap_free(&h);
    return stops;
}
