class LRUCache {
public:
list<int>dll;
map<int,pair<list<int>::iterator,int>>map1;
int n;
    LRUCache(int capacity) {
      n=capacity;  
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
       else{
        makeRecentlyUsed(key);
        return map1[key].second;
       } 
    }
    
    void put(int key, int value) {
        if(map1.find(key)!=map1.end()){
            map1[key].second=value;
            makeRecentlyUsed(key); 
        }
        else{
            dll.push_front(key);
            map1[key]={dll.begin(),value};
            n--;
        }
        if(n<0){
            int key_to_Be_Del=dll.back();
            map1.erase(key_to_Be_Del);
            dll.pop_back();
            n++;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */