class MyHashMap {
public:
    vector<int> hash;
    MyHashMap() 
    {
        hash.resize(1e6+1, -1);
    }
    
    void put(int key, int val)
    {
        hash[key] = val;
    }
    
    int get(int key)
    {
        return hash[key];
    }
    
    void remove(int key) 
    {
        hash[key] = -1;
    }
};