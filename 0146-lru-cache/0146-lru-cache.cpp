class LRUCache {
public:
list<int>dll;
unordered_map<int,pair<list<int>::iterator,int>>map1;
int size;
    LRUCache(int capacity) {
     size=capacity;   
    }
    
    void makeRecentlyUsed(int key){
dll.erase(map1[key].first);
dll.push_front(key);
map1[key].first=dll.begin();
    }
    int get(int key) {
      if(map1.find(key)==map1.end()){
        return -1;
      }
int val=map1[key].second;
makeRecentlyUsed(key);
return val;
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
      }
      if(size<0){
        int el=dll.back();
        //remember hum log kabhi bhi dll.erase(XXiterator)nhi bhejte hmesha address dete h
        dll.pop_back();
        map1.erase(el);
        size++;
      }

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */