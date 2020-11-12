class Heap:
    def __init__(self):
        self.heap = []
        self.heap_size = 0
    
    def parent(self, i):
        return (i-1)//2

    def right(self, i):
        return 2*i + 2

    def left(self, i):
        return 2*i + 1

    def insert_heap(self, e):
        self.heap.append(e)
        index = self.heap_size
        par = self.parent(index)
        while(par >= 0 and self.heap[index] < self.heap[par]):
            self.heap[index], self.heap[par] = self.heap[par], self.heap[index]
            index = par
            par = self.parent(index)
        self.heap_size += 1
        return index

    def print_heap(self):
        for x in self.heap:
            print(x, end=" ")
    
    def extract_min(self):
        if self.heap_size == 0: 
           return 
        root = self.heap[0]
        if self.heap_size == 1:
            self.heap.pop()
            return root
        else:
            self.heap[0] = self.heap[self.heap_size - 1]
            self.heap.pop()
            self.min_heapify(0)
        self.heap_size -= 1
        return root

    def min_heapify(self, i):
        l = self.left(i)
        r = self.right(i)
        smallest = i
        if (l < self.heap_size and self.heap[l] < self.heap[i]): 
            smallest = l
        if (r < self.heap_size and self.heap[r] < self.heap[smallest]):
            smallest = r
        if(smallest != i):
            self.heap[i], self.heap[smallest] = self.heap[smallest], self.heap[i]
            self.min_heapify(smallest)

def main():
    H = Heap()
    H.insert_heap(10)
    H.insert_heap(1)
    H.insert_heap(6)
    H.insert_heap(0)
    H.insert_heap(100)
    H.insert_heap(-1)
    H.print_heap()

    print(H.extract_min())
if __name__ == "__main__":
    main()