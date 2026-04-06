class LRUCache {
public:
list<int>dll;
unordered_map<int,pair<list<int>::iterator,int>>map1;
int size;
    LRUCache(int capacity) {
        size=capacity;
    }
    void makeRecentlyUsed(int key){
        auto val=map1[key].first;
dll.erase(val);
dll.push_front(key);
map1[key].first=dll.begin();
    }
    int get(int key) {

       if(map1.find(key)!=map1.end()){
        makeRecentlyUsed(key);
        return map1[key].second;
       }
return -1;
    }
    
    void put(int key, int value) {
     if(map1.find(key)!=map1.end()){
        map1[key].second=value;
        makeRecentlyUsed(key);
     }   
     else{
        dll.push_front(key);
        map1[key].first=dll.begin();
        map1[key].second=value;
        size--;
        if(size<0){
            int k=dll.back();
            auto add=map1[k].first;
            dll.erase(add);
            //remember
            map1.erase(k);
            size++;
        }
     }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */